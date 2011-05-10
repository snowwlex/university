package gr7372.turkin.lab4;


import javax.jms.JMSException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    private static String DEFAULT_TOPIC_NAME="world";

    public static void main(String args[]) {
        if (args.length < 1 || args.length > 2) {
            System.out.println("Usage: chat-client YOUR_NAME [TOPIC_NAME]");
            System.out.format("(Topic name is '%s' by default)\n" , DEFAULT_TOPIC_NAME);
			return;
		}
        String username = args[0];
        if (username.indexOf(" ") != -1) {
            username = username.replace(' ', '_');
            System.out.format("Your name has been changed to '%s'\n" , username);
        }
        String topicname = DEFAULT_TOPIC_NAME;
        if (args.length == 2) {
            topicname = args[1];
        }
        printHelp();
        try {
            runChat(username,topicname);
        } catch (JMSException e){
            System.out.format("Something wrong with JMS: %s\n", e.getMessage());
        }
    }

    private static void runChat(String username, String topicname) throws JMSException {
        ChatClient client  = new ChatClient();
        client.connect(username, topicname, new ChatMessageListener() );
        client.sendMessage("I'm online!");
        try {
            runChatLoop(client);
        } catch (IOException e) {
            System.out.format("Something wrong with reading from console: %s\n", e.getMessage());
        }
        client.sendMessage("I'm going out!");
        client.disconnect();

    }

    private static void runChatLoop(ChatClient client) throws IOException, JMSException {
        BufferedReader cmdline = new BufferedReader( new InputStreamReader(System.in) );
        String cmd;
        while  ( !(cmd = cmdline.readLine() ).equals("/exit") )  {
            if (cmd.equals("/help")) {
                printHelp();
            } else if (cmd.startsWith("@")) {
                Pattern p = Pattern.compile("^@([^\\s]+)\\s(.+)$");
                Matcher m = p.matcher(cmd);
                if ( m.find() ) {
                    String to = m.group(1);
                    String text = m.group(2);
                    client.sendMessage(text, to);
                }
            } else {
                client.sendMessage( cmd );
            }

        }
    }

    private static void printHelp() {
        System.out.println();
        System.out.println("Write down you message, then press <enter> to send it");
        System.out.println("Special commands: ");
        System.out.println(" * '/exit'  --  exit form chat");
        System.out.println(" * '/help'  --  print this help");
        System.out.println(" * '@username your message'  --  send 'your message' as personal message to username");
        System.out.println();
    }


}