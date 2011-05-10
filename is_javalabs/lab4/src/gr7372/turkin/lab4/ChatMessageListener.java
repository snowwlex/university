package gr7372.turkin.lab4;

import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageListener;
import javax.jms.TextMessage;
import java.text.SimpleDateFormat;
import java.util.Date;

public class ChatMessageListener implements MessageListener {

    public void onMessage(Message message)  {
        try {
            if (message instanceof TextMessage) {
                TextMessage msg = (TextMessage) message;
                System.out.println( getChatLine(msg) );
            } else {
                System.out.format("Incoming message of wrong type (%s)\n", message.getClass().getName());
            }
        } catch (JMSException e) {
          /* ignoring */ 
        }
    }
    
    public static String getChatLine(TextMessage msg) throws JMSException {
        String sender = msg.getStringProperty("sender");
        String receiver = msg.getStringProperty("receiver");
        String text = msg.getText(); 
        Date date = new Date(msg.getJMSTimestamp());
        SimpleDateFormat sdf = new SimpleDateFormat("dd.MM.yy hh:mm");
        String chatLine = "";
        if (receiver.isEmpty()) {
            chatLine = String.format("[%s] %s: %s", sdf.format(date), sender, text);
        } else {
            chatLine = String.format("[%s] PM from %s: %s", sdf.format(date), sender, text);        
        }
        return chatLine;
    }

}
