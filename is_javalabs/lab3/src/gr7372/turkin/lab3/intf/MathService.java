package gr7372.turkin.lab3.intf;

import java.math.BigDecimal;
import java.util.List;

import java.rmi.Remote;
import java.rmi.RemoteException;


public interface MathService extends Remote {
    public List<Integer> arithmeticSequence(int init, int step, int number) throws RemoteException;
    public List<Integer> geomSequence(int init, int mul, int number) throws RemoteException;
    public BigDecimal factorial(int number)  throws RemoteException;
    public boolean isPrimeNumber(int number) throws RemoteException;
    public List<Integer> fibbonachiSequence(int number) throws RemoteException;
}
