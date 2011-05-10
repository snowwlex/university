package gr7372.turkin.lab3.server;


import gr7372.turkin.lab3.intf.MathService;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;


public class Main {

    public static void main(String[] args) {
        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {
            String name = "MathService";
            MathServiceImpl service = new MathServiceImpl();
            MathService stub =(MathService) UnicastRemoteObject.exportObject(service, 0);
            Registry registry = LocateRegistry.getRegistry();
            registry.rebind(name, stub);
            System.out.println("MathService bound");
        } catch (Exception e) {
            System.err.println("Exception:");
            e.printStackTrace();
        }
    }

}