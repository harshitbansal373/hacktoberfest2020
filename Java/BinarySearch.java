class BinarySearch { 
    // Given a sorted array it returns the index of a given number in linear time
    int binarySearch(int array[], int searchNumber) { 
        int left = 0, right = array.length - 1; 
        while (left <= right) { 
            int middle = left + (right - left) / 2;
            // Checks if the number is in the middle
            if (array[middle] == searchNumber) 
                return middle; 
            // If the number is higher go right
            if (array[middle] < searchNumber) 
                left = middle + 1; 
            // If the number is smaller go left 
            else
                right = middle - 1; 
        } 
        // Returns -1 if the number is not in the array
        return -1; 
    } 
    // Testing
    public static void main(String args[]) { 
        BinarySearch binarySeachTest = new BinarySearch(); 
        int array[] = { 2, 3, 4, 10, 40 }; 
        int searchNumber = 10; 
        int result = binarySeachTest.binarySearch(array, searchNumber); 
        System.out.println(result);
    } 
} 