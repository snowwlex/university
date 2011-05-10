package gr7372.turkin.lab1;


import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Map;


public class Requester {
    private String host;
    private ArrayList<HttpCookie> cookies;
    private static String ENCODE = "UTF8";

    public Requester(String host) {
        this.host = host;
        this.cookies = new ArrayList<HttpCookie>();
    }
    public Response get(String uri) {
        ArrayList<String> headers = new ArrayList<String>();
        headers.add("GET " + uri + " HTTP/1.1");
        headers.add("Host: " + this.host);
        headers.add("Connection: keep-alive");
        headers.add("Cache-Control: max-age=0");
        String cookieHeader = getCookieHeader(this.cookies);
        if (!cookieHeader.isEmpty()) {
            headers.add(cookieHeader);
        }
        Response response =  sendRequest(this.host,headers);
        updateCookiesFromHeaders(response.getHeaders());
        return response;
    }
    public Response post(String uri, Map<String, String> params) {
        String postParams = makeParamsString(params);
        ArrayList<String> headers = new ArrayList<String>();
        headers.add( "POST " + uri + " HTTP/1.1");
        headers.add( "Host: " + this.host);
        headers.add("Connection: keep-alive");
        headers.add("Cache-Control: max-age=0");
        headers.add( "Content-Type: application/x-www-form-urlencoded");
        headers.add( "Content-Length: " + Integer.toString(postParams.length()));
        String cookieHeader = getCookieHeader(this.cookies);
        if (!cookieHeader.isEmpty()) {
          headers.add(cookieHeader);
        }
        headers.add("");
        headers.add( postParams );
        Response response =  sendRequest(this.host,headers);
        updateCookiesFromHeaders(response.getHeaders());
        return response;
    }
    private void updateCookiesFromHeaders(List<String> headers) {
        for (Iterator<HttpCookie> i = this.cookies.iterator(); i.hasNext(); ) {
            if ( i.next().hasExpired() ) {
                i.remove();
            }
        }
        for (String header: headers) {
            if (header.startsWith("Set-Cookie:") ){
               List<HttpCookie> newCookies = HttpCookie.parse(header);
               for (HttpCookie cookie: newCookies) {
                 for (Iterator<HttpCookie> i = this.cookies.iterator(); i.hasNext(); ) {
                    if (i.next().getName().equals(cookie.getName())) {
                        i.remove();
                    }
               }
               this.cookies.addAll(newCookies);
               }
            }
        }
    }

    private static String makeParamsString(Map<String, String> paramsMap)   {
        String params = "";
            for (String key: paramsMap.keySet()) {
                if (!params.isEmpty()) {
                    params+="&";
                }
                params+=key+"="+paramsMap.get(key);
            }
        return params;
    }

    private static Response sendRequest(String host, ArrayList<String> headers) {
        List<String> responseList = null;
        try {
            Socket socket = new Socket(host,80);
            OutputStream os = socket.getOutputStream();
            BufferedWriter w = new BufferedWriter( new OutputStreamWriter(os, ENCODE) );
            w.write( generateHeadersString(headers) );
            w.flush();
            //w.close();
            StringBuffer b = new StringBuffer();
            InputStreamReader r = new InputStreamReader(socket.getInputStream(), ENCODE);
            int c;
            while ((c = r.read()) > 0){
                b.append((char)c);
            }
            r.close();
            responseList = new ArrayList<String>(  );
            String[] arStrings = b.toString().split("\r\n");
            for (String s: arStrings) {
                responseList.add(s);
            }
            //socket.close();
        } catch (UnknownHostException e) {
            System.out.println("Unknown host exc");
            System.out.println(e.getCause());
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println("exception! " + e.getMessage());
        }
        return processResponse(responseList);
    }

    private static String generateHeadersString(ArrayList<String> headers) {
        final String endHeader  = "\r\n";
        String http = "";
        for (String header: headers) {
            http += header + endHeader;
        }
        http += endHeader;
        return http;
    }

    private static String getCookieHeader(List<HttpCookie> cookies) {
        String cookieString = "";
        for (HttpCookie cookie: cookies ) {
            if (cookieString.length() != 0) {
                cookieString += "; ";
            }
            cookieString += cookie.toString();
        }
        if (!cookieString.isEmpty()) {
            cookieString =  "Cookie: " + cookieString;
        }
        return cookieString;
    }

    private static Response processResponse(List<String> response) {
        Iterator<String> it = response.iterator();
        ArrayList<String> headers = new ArrayList<String>();
        String line;
        while (it.hasNext() && (line = it.next() ).length() != 0) {
            headers.add(line);
        }
        String content = "";
        while ( it.hasNext() ) {
            content += it.next();
        }
        return new Response(headers,content);
    }

    private static void printHeaders(ArrayList<String> headers) {
        for (String header: headers) {
               System.out.println(header);
        }
    }

    private static void printCookies(ArrayList<HttpCookie> cookies) {
        for (HttpCookie cookie: cookies) {
            System.out.println(cookie);
        }
    }

}
