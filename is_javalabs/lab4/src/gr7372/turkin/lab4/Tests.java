package gr7372.turkin.lab4;

import junit.framework.TestCase;

import javax.jms.JMSException;


public class Tests extends TestCase {

	public Tests(String name) {
		super(name);
	}
	protected void setUp() throws Exception {
		super.setUp();
	}
	protected void tearDown() throws Exception {
        super.tearDown();
    }


    public void testConnectDisconnect() {
        try {
            ChatClient client = new ChatClient();
            client.connect("alex", "topic", new ChatMessageListener());
            client.disconnect();
        } catch (JMSException e) {
            fail();
        }
    }

    public void testDoubleConnects() {
        try {
            ChatClient client = new ChatClient();
            client.connect("alex1", "topic1", new ChatMessageListener());
            client.connect("alex2", "topic2", new ChatMessageListener());
            client.connect("alex3", "topic3", new ChatMessageListener());
        } catch (JMSException e) {
            fail("can't make a few connection");
        }
    }

    public void testSendMessage() {
        try {
            ChatClient client = new ChatClient();
            client.connect("alex1", "topic1", new ChatMessageListener());
            client.sendMessage("message");
            client.disconnect();
        } catch (JMSException e) {
            fail();
        }
    }

    public void testSendPersonalMessage() {
        try {
            ChatClient client = new ChatClient();
            client.connect("alex1", "topic1", new ChatMessageListener());
            client.sendMessage("message", "alex2");
            client.disconnect();
        } catch (JMSException e) {
            fail();
        }
    }

     public void testDisconnectSendMessage() {
        try {
            ChatClient client = new ChatClient();
            client.sendMessage("message");
            client.disconnect();
        } catch (JMSException e) {
            assertSame(e.getErrorCode(), "C4040");
        }
     }

    public void testSomeDisconnects() {
        try {
            ChatClient client = new ChatClient();
            client.disconnect();
            client.disconnect();
        } catch (JMSException e) {
            fail();
        }
     }


}