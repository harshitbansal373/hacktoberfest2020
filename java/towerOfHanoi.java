import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int n1 = scn.nextInt();
        int n2 = scn.nextInt();
        int n3 = scn.nextInt();
        toh(n, n1, n2, n3);
    }

    public static void toh(int n, int t1, int t2, int t3) {
        if(n==0)return;
        toh(n-1,t1,t3,t2);
        System.out.println(n+"["+t1+" -> "+t2+"]");
        toh(n-1,t3,t2,t1);
    }

}