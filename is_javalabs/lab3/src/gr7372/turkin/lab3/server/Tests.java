package gr7372.turkin.lab3.server;

import junit.framework.TestCase;

import java.math.BigDecimal;
import java.util.List;

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


    public void testArithmetic() {
        MathServiceImpl ms = new MathServiceImpl();
        List<Integer> li = ms.arithmeticSequence(1,2,3);
        assertTrue( li.size() == 3);
        assertTrue( li.get(1) == 3);
    }
    public void testGeom() {
        MathServiceImpl ms = new MathServiceImpl();
        List<Integer> li = ms.geomSequence(1,2,4);
        assertTrue( li.size() == 4);
        assertTrue( li.get(3) == 8);
    }
    public void testFactorial() {
        MathServiceImpl ms = new MathServiceImpl();
        BigDecimal factorial = ms.factorial(10);
        assertTrue( factorial.equals( new BigDecimal(3628800) ));
    }
    public void testPrimeNumber() {
        MathServiceImpl ms = new MathServiceImpl();
        assertTrue( ms.isPrimeNumber(2) );
        assertTrue( ms.isPrimeNumber(1) );
        assertTrue(ms.isPrimeNumber(13));
        assertFalse( ms.isPrimeNumber(10) );
        assertFalse( ms.isPrimeNumber(55) );
    }
    public void testFibbonachi() {
        MathServiceImpl ms = new MathServiceImpl();
        List<Integer> li = ms.fibbonachiSequence(10);
        assertTrue( li.size() == 10);
        assertTrue( li.get(3) == 2);
        assertTrue( li.get(0) == 0);
        assertTrue( li.get(9) == 34);
    }

}