import java.util.Arrays;

//! amortized anaylysis - analyzes algo whose operations has varying T.C
//! two-pointers
//! basic idea of 2pointers - choose a subarray, with l and r
//! move l once right and move r until x is found or their sum of l~r is < x
//! if sum is found - break
//! else repeat 

public class SubArraySum {
    public static void main(String[] args) {
        int arr[] = { 1, 3, 2, 5, 1, 1, 2, 3 };
        int x = 3;
        // * take subarray from l to r
        // * inc l one step
        int l = -1;
        int r = 2;

        while (l < arr.length) {
            l++;

            while ((sumlr(Arrays.copyOfRange(arr, l, r + 1))) < x && r < arr.length) {
                r++;
            }
            if (sumlr(Arrays.copyOfRange(arr, l, r + 1)) == x) {
                System.out.println("found @: " + l + ", " + r);
                System.exit(0);

            } else

                continue;

        }
        System.out.println("Not found");
    }

    static int sumlr(int arr[]) {
        int i = 0;
        int sum = 0;
        while (i < arr.length) {
            sum += arr[i];
            i++;
        }
        return sum;
    }

}
