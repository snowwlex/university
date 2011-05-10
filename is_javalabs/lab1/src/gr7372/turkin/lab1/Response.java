package gr7372.turkin.lab1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Response {
    private ArrayList<String> headers;
    private String content;

    public Response( List<String> headers, String content) {
        this.headers = new ArrayList<String>(headers);
        this.content = content;
    }

    public Response( List<String> response) {
        Iterator<String> it = response.iterator();
        this.headers = new ArrayList<String>();
        String line;
        while (it.hasNext() && (line = it.next() ).length() != 0) {
            headers.add(line);
        }
        this.content = "";
        while ( it.hasNext() ) {
            content += it.next();
        }
    }

    public List<String> getHeaders() {
        return headers;
    }

    public String getContent() {
        return content;
    }

    public String getStatus() {
        return headers.get(0);
    }
}
