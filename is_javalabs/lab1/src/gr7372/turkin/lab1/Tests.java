package gr7372.turkin.lab1;


import org.junit.Test;

import java.util.ArrayList;

import static junit.framework.Assert.assertTrue;

public class Tests {

    @Test
    public void testGetRequest() {
        Requester req = new Requester("ya.ru");
        Response response = req.get("/");
        assertTrue (!response.getContent().isEmpty());
        assertTrue (response.getStatus().equals("HTTP/1.1 200 OK"));
    }

    @Test
    public void testFailedGetRequest() {
        Requester req = new Requester("ya.ru");
        Response response = req.get("/cp/");
        assertTrue (response.getStatus().contains("302"));
    }

    @Test
    public void responseTest() {
        ArrayList<String> responseList = new ArrayList<String>();
        responseList.add("HTTP/1.1 200 OK");
        responseList.add("Host: somehost.ru");
        responseList.add("Header: header");
        responseList.add("");
        responseList.add("content");
        Response response = new Response(responseList);
        assertTrue(response.getContent().equals("content"));
        assertTrue(response.getHeaders().size() == 3);
        assertTrue(response.getStatus().equals( "HTTP/1.1 200 OK"));

    }

    @Test
    public void getUserIDTest() {
        String userAnchor = "<a href=\"http://u123.rpod.ru/\"";
        assertTrue(Main.getUserId(userAnchor).equals("u123"));

    }

    @Test
    public void getLastSubscribesTest() {
        String content = "<a class=\"rpad\" href=\"http://1.html\">1st link</a>\n" +
                         "<a class=\"rpad\" href=\"http://2.html\">2nd link</a>" +
                         "<a href=\"1.html\">something</a>";
        assertTrue( Main.getLastSubscribes(content).size() == 2);

    }

}
