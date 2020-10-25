import java.util.*;
import java.io.*;

public class Shoppinglist {
    public static void main(String args[]) {
        Vector itemList = new Vector();
        String str, item;
        int i, j, len, choice, pos;
        len = args.length;
        for (i = 0; i < len; i++)
            itemList.addElement(args[i]);
        while (true) {
            System.out.println("Choose your choice ...");
            System.out.println("1) Delete  Item");
            System.out.println("2) Add Item at Specified Location ");
            System.out.println("3) Add Item at  the End of the list");
            System.out.println("4) Print Vector List ");
            System.out.println("5) Exit");
            System.out.print("Enter your choice : ");
            System.out.flush();
            try {
                BufferedReader obj = new BufferedReader(new InputStreamReader(System.in));
                str = obj.readLine();
                choice = Integer.parseInt(str);
                switch (choice) {
                    case 1:
                        System.out.print("Enter Item you want to delete : ");
                        str = obj.readLine();
                        itemList.removeElement(str);
                        break;
                    case 2:
                        System.out.print("Enter Item to be Insert : ");
                        System.out.flush();
                        item = obj.readLine();
                        System.out.print("Enter Position to insert item : ");
                        str = obj.readLine();
                        pos = Integer.parseInt(str);
                        itemList.insertElementAt(item, pos - 1);
                        break;
                    case 3:
                        System.out.print("Enter Item to be Insert : ");
                        System.out.flush();
                        item = obj.readLine();
                        itemList.addElement(item);
                        break;
                    case 4:
                        len = itemList.size();
                        System.out.println("\nItem Display ");
                        for (i = 0; i < len; i++) {
                            System.out.println((i + 1) + ") " + itemList.elementAt(i));
                        }
                        break;
                    case 5:
                        System.out.println("\n\nThank You for using this software.....");
                        System.exit(1);
                        break;
                    default:
                        System.out.println("\nEntered Choice is Invalid\nTry Again\n");
                }
            } catch (Exception e) {
            }
        }
    }
}