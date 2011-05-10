package gr7372.turkin.lab2;

import junit.framework.TestCase;

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
        MathService ms = new MathService();
        List<Integer> li = ms.arithmeticSequence(1,2,3);
        assertTrue( li.size() == 3);
        assertTrue( li.get(1) == 3);
    }
    public void testGeom() {
        MathService ms = new MathService();
        List<Integer> li = ms.geomSequence(1,2,4);
        assertTrue( li.size() == 4);
        assertTrue( li.get(3) == 8);
    }
    public void testFactorial() {
        MathService ms = new MathService();
        long factorial = ms.factorial(10);
        assertTrue( factorial == 3628800);
    }
    public void testPrimeNumber() {
        MathService ms = new MathService();
        assertTrue( ms.isPrimeNumber(2) );
        assertTrue( ms.isPrimeNumber(1) );
        assertTrue(ms.isPrimeNumber(13));
        assertFalse( ms.isPrimeNumber(10) );
        assertFalse( ms.isPrimeNumber(55) );
    }
    public void testFibbonachi() {
        MathService ms = new MathService();
        List<Integer> li = ms.fibbonachiSequence(10);
        assertTrue( li.size() == 10);
        assertTrue( li.get(3) == 2);
        assertTrue( li.get(0) == 0);
        assertTrue( li.get(9) == 34);
    }

}