package gr7372.turkin.lab4;


import javax.jms.*;

public class ChatClient {
    private TopicConnection connection = null;
    private TopicSession session = null;
    private TopicPublisher publisher;
    private TopicSubscriber subscriber;
    private TopicSubscriber personalSubscriber;
    private String username;

    public ChatClient() throws JMSException {
        TopicConnectionFactory connectionFactory = new com.sun.messaging.TopicConnectionFactory();
        this.connection = connectionFactory.createTopicConnection();
        this.session =  this.connection.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);
    }

    public void connect(String username, String topicName, MessageListener listener ) throws JMSException {
      this.username = username;
      Topic topic = new com.sun.messaging.Topic(topicName);
      this.publisher = session.createPublisher(topic);
      this.subscriber = session.createSubscriber(topic, "receiver = ''" ,true);
      this.personalSubscriber = session.createSubscriber(topic, String.format("receiver = '%s'", this.username) ,true);
      this.subscriber.setMessageListener( listener );
      this.personalSubscriber.setMessageListener( listener );
      connection.start();
    }

    public void sendMessage(String text) throws JMSException {
        TextMessage msg = createTextMessage(text, "");
        publisher.publish(msg);
    }
    public void sendMessage(String text, String receiver) throws JMSException {
        TextMessage msg = createTextMessage(text, receiver);
        publisher.publish(msg);
    }

    protected TextMessage createTextMessage(String text, String receiver)  throws JMSException {
        TextMessage msg = session.createTextMessage(text);
        msg.setStringProperty("sender", this.username);
        msg.setStringProperty("receiver", receiver);
        return msg;
    }

    public void disconnect() throws JMSException {
        if (this.session != null) {
            this.session.close();
        }
        if (this.connection != null) {
            this.connection.close();
        }
    }

}
