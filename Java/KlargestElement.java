public class KlargestElement {
    private static int findKthLargest(int[] nums, int k) {
        int min = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (min > nums[i]) {
                min = nums[i];
            }
        }

        int max = nums[0];
        for (int i = 1; i <= k; i++) {
            max = findMaxIndex(nums);
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == max) {
                    nums[j] = min;
                    break;
                }
            }
        }
        return max;
    }

    private static int findMaxIndex(int[] a) {
        int max = a[0];
        for (int i = 1; i < a.length; i++) {
            if (max < a[i]) {
                max = a[i];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] a = {2, 1};
        System.out.println(findKthLargest(a, 2));
    }
}
