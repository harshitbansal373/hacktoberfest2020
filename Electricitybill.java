import java.util.Scanner;

public class Electricitybill {
    String n;
    int units;
    double bill = 0;

    void accept() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Name of Customer: ");
        n = sc.nextLine();
        System.out.println("Number of Units: ");
        units = sc.nextInt();
        sc.close();
    }

    void calculate() {
        if (units <= 100)
            bill += units * 2;
        if (units <= 300)
            bill += units * 3;
        if (units > 300) {
            bill += units * 5;
            bill *= 1.025;// surcharge considered to be after 5 per unit charge
        }
    }

    void print() {
        System.out.println("Name of Customer: " + n);
        System.out.println("Number of Units Consumed: " + units);
        System.out.println("Bill Amount: " + bill);
    }

    public static void main(String[] args) {
        Electricitybill obj1 = new Electricitybill();
        obj1.accept();
        obj1.calculate();
        obj1.print();
    }
}