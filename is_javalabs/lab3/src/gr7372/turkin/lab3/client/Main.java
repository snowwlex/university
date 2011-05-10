package gr7372.turkin.lab3.client;

import gr7372.turkin.lab3.intf.MathService;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.List;

public class Main {
    public static void main(String args[]) {
        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {
            String name = "MathService";
            Registry registry = LocateRegistry.getRegistry();
            MathService service = (MathService) registry.lookup(name);
            use(service);
        } catch (Exception e) {
            System.err.println("Main exception:");
            e.printStackTrace();
        }
    }

    public static void use(MathService service) throws Exception {

        System.out.println("Arithmetic Sequence");
        System.out.println("Init = 10, step = 3, 10 members:");
        show(service.arithmeticSequence(10,3,10));
        System.out.println();

        System.out.println("Geometric Sequence");
        System.out.println("Init = 3, multiply = 4, 10 members:");
        show( service.geomSequence(3,4,10) );
        System.out.println();

        System.out.println("Fibbonachi Sequence");
        System.out.println("20 members:");
        show( service.fibbonachiSequence(20) );
        System.out.println();

        System.out.println("Factorial of 100:");
        System.out.println(  service.factorial(100) );
        System.out.println();

        System.out.println("is 10 prime number?");
        System.out.println(  service.isPrimeNumber(10) );
        System.out.println();

        System.out.println("is 5 prime number?");
        System.out.println(  service.isPrimeNumber(5) );

    }

    private static void show(List<Integer> list) {
        for (Integer i: list) {
            System.out.format("%d ", i);
        }
        System.out.println();
    }

}