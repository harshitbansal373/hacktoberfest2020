import java.util.Scanner;
public class Main {
    private static Scanner scanner=new Scanner(System.in);
    public static void main(String[] args) {
        int [] myArray=getArray(5);
        int [] reverseArray=reverse(myArray);
        System.out.println(reverseArray);

    }
    private static int[] getArray(int size){
        int [] array=new int[size];
        System.out.println("Enter size of array :\r"+size);
        for(int i=0;i<5;i++){
            array[i]=scanner.nextInt();

        }
        return array;

    }
    private static int[] reverse(int [] array){
        int [] reverseArray=new int[array.length];
        for(int i=0;i<array.length;i++){
            reverseArray[i]=array[i];
        }
        int flag=1;
        int temp;
        while(flag==1){
            flag=0;
            for(int i=1;i<reverseArray.length;i++){
                if(reverseArray[i]==reverseArray[reverseArray.length-i]){
                    temp=reverseArray[i];
                }
                temp=reverseArray[i];
                reverseArray[i]=reverseArray[reverseArray.length-i];
                reverseArray[reverseArray.length-i]=temp;
                flag=1;
            }

        }
     return   reverseArray;
    }
}
