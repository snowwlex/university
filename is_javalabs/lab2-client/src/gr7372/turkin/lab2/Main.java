package gr7372.turkin.lab2;


import java.util.List;

public class Main {
    public static void main(String[] args) {
        MathServiceService service = new MathServiceService();
        MathService port = service.getMathServicePort();

        System.out.println("Arithmetic Sequence");
        System.out.println("Init = 10, step = 3, 10 members:");
        show(port.arithmeticSequence(10,3,10));
        System.out.println();

        System.out.println("Geometric Sequence");
        System.out.println("Init = 3, multiply = 4, 10 members:");
        show( port.geomSequence(3,4,10) );
        System.out.println();

        System.out.println("Fibbonachi Sequence");
        System.out.println("20 members:");
        show( port.fibbonachiSequence(20) );
        System.out.println();

        System.out.println("Factorial of 5:");
        System.out.println(  port.factorial(5) );
        System.out.println();

        System.out.println("is 10 prime number?");
        System.out.println(  port.isPrimeNumber(10) );
        System.out.println();

        System.out.println("is 5 prime number?");
        System.out.println(  port.isPrimeNumber(5) );

    }
    private static void show(List<Integer> list) {
        for (Integer i: list) {
            System.out.format("%d ", i);
        }
        System.out.println();
    }
}