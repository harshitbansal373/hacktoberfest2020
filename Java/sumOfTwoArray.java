import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        //input 1
        int n1 = scn.nextInt();
        int[] arr1 = new int[n1];
        for (int i = 0; i < n1; i++) {
            arr1[i] = scn.nextInt();
        }
        //input 2
        int n2 = scn.nextInt();
        int[] arr2 = new int[n2];
        for (int i = 0; i < n2; i++) {
            arr2[i] = scn.nextInt();
        }
        sum(arr1, arr2);
    }


    public static void sum(int[] arr1, int[] arr2) {
        int max = arr1.length;
        if (arr2.length > max) {
            max = arr2.length;
        }

        int[] ans = new int[max + 1];
        int idx1 = arr1.length - 1;
        int idx2 = arr2.length - 1;
        int idx3 = ans.length - 1;
        int carry = 0;

        while (idx1 >= 0 || idx2 >= 0 || carry > 0) {
            int sum = carry;
            if(idx1>=0){
                sum+=arr1[idx1];
            }
            if(idx2>=0){
                sum+=arr2[idx2];
            }
            int q = sum / 10;
            int r = sum % 10;
            ans[idx3] = r;
            carry = q;
            idx1--;
            idx2--;
            idx3--;
        }
        int idx=0;
        while(idx<ans.length){
            if(ans[idx]!=0){
                break;
            }
            idx++;
        }
        while(idx<ans.length){
            System.out.println(ans[idx]);
            idx++;
        }
    }

}