package gr7372.turkin.lab1;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ResponseHandler;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.BasicResponseHandler;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.regex.*;

public class Main {
    public static void main(String[] args) throws Exception {
        String username = "test";
        String password = "qwertyjkl";
        runWithHttpClient(username,password);
        System.out.println();
        runWithSocket(username, password);
    }

    public static void runWithSocket(String username, String password) {
        System.out.println("Work with HTTP protocol via Socket");

        Requester req = new Requester("rpod.ru");

        LinkedHashMap params = new LinkedHashMap<String,String>();
        params.put("login", username);
        params.put("password", password);
        params.put("unsafeip", "1");
        params.put("remember", "1");

        System.out.println("sending post request to login");
        Response response = req.post("/login/", params);
        System.out.println(response.getStatus());

        System.out.println("sending get request. Retrieving user id");
        response = req.get("/cp/");
        System.out.println(response.getStatus());
        String userID = getUserId(response.getContent());
        System.out.format("User ID is %s\n", userID);

        System.out.println("sending get request. Retrieving last subscribes");
        String page = "http://" + userID + ".rpod.ru/subscribes/feed/";
        System.out.println(page);
        response = req.get(page);
        System.out.println(response.getStatus());

        List<String> lastSubscribes = getLastSubscribes(response.getContent());
        System.out.println("Last subscribes:");
        for (String subscribe: lastSubscribes) {
            System.out.println(subscribe);
        }


    }

    public static String getUserId(String content) {
        Pattern p = Pattern.compile("(<a href=\"http://(u[0-9]+)\\.rpod\\.ru/\")");
        Matcher m = p.matcher(content);
        m.find();
        m.group(0);
        String userID = m.group(2);
        return userID;
    }

    public static List<String> getLastSubscribes(String content) {
        ArrayList<String> issues = new ArrayList<String>();
        ArrayList<String> links = new ArrayList<String>();
        Pattern p = Pattern.compile("(<a class=\"rpad\".+href=\"(http://.+\\.html)\">(.+)</a>)");
        Matcher m = p.matcher(content);
        while (m.find()) {
            issues.add(m.group(2));
            links.add(m.group(3));
        }
        ArrayList<String> lastSubscribes = new ArrayList<String>();
        for (int i=0; i<issues.size(); ++i) {
         lastSubscribes.add(String.format("%s  --  %s", issues.get(i), links.get(i)));
        }
        return lastSubscribes;
    }


    public static void runWithHttpClient(String username, String password) throws Exception {
        DefaultHttpClient httpclient = new DefaultHttpClient();
        ResponseHandler<String> responseHandler = new BasicResponseHandler();
        try {

            System.out.println("Work with HTTP protocol via HttpClient");
            // POST request with AUTHORIZATION
            System.out.println("sending post request to login");
            HttpPost httpost = new HttpPost("http://rpod.ru/login/");
            List <NameValuePair> nvps = new ArrayList<NameValuePair>();
            nvps.add(new BasicNameValuePair("login", username));
            nvps.add(new BasicNameValuePair("password", password));
            nvps.add(new BasicNameValuePair("unsafeip", "1"));
            nvps.add(new BasicNameValuePair("remember", "1"));
            httpost.setEntity(new UrlEncodedFormEntity(nvps, HTTP.UTF_8));
            HttpResponse response = httpclient.execute(httpost);
            HttpEntity entity = response.getEntity();
            EntityUtils.consume(entity);

            // GET request: reading user ID to acess user's page
            System.out.println("sending get request. Retrieving user id");
            HttpGet httpget = new HttpGet("http://rpod.ru/cp/");
            String answer = httpclient.execute(httpget, responseHandler);
            String userID = getUserId(answer);
            System.out.format("User ID is %s\n", userID);

            // GET request: reading feed
            System.out.println("sending get request. Retrieving last subscribes");
            String page = "http://" + userID + ".rpod.ru/subscribes/feed/";
            httpget = new HttpGet(page);
            answer = httpclient.execute(httpget, responseHandler);
            List<String> lastSubscribes = getLastSubscribes(answer);
            System.out.println("Last subscribes:");
            for (String subscribe: lastSubscribes) {
                System.out.println(subscribe);
            }

        } finally {
            httpclient.getConnectionManager().shutdown();
        }
    }


}

