package gr7372.turkin.lab2;

import javax.jws.WebService;
import java.util.ArrayList;
import java.util.List;

@WebService
public class MathService {
    public ArrayList<Integer> arithmeticSequence(int init, int step, int number) {
        ArrayList<Integer> members = new ArrayList<Integer>();
        for(int i=init; members.size() < number ; i+=step) {
            members.add(i);
        }
        return members;
    }
    public ArrayList<Integer> geomSequence(int init, int mul, int number) {
        ArrayList<Integer> members = new ArrayList<Integer>();
        for(int i=init; members.size() < number ; i*=mul) {
            members.add(i);
        }
        return members;
    }
    public long factorial(int number) {
        long init = 1;
        for (int i=1; i<number; ++i) {
            init *= (i+1);
        }
        return init;
    }
    public boolean isPrimeNumber(int number) {
        boolean result = true;
        for (int i=2; i < number ; ++i) {
            if (number % i == 0) {
                result = false;
                break;
            }
        }
        return result;
    }
    public  List<Integer> fibbonachiSequence(int number) {
        ArrayList<Integer> members = new ArrayList<Integer>();
        members.add(0);
        members.add(1);
        for (int i=2; i<number; ++i) {
            members.add( members.get(i-1) + members.get(i-2));
        }
        return members;
    }
}
