
// Program to simulate the Dice Game of Craps, which is commonly played in casinos. 
// If they roll a 7 or 1 on the first try, you win. If you roll a 2, 3, or 12 on first try, you lose. 
// If neither of the above happen, your first roll is called a "point". If you roll the "point" again, you win. 
// If you roll a 7 before rolling the "point" again, you lose. 

public class DiceGameOfCraps
{
    private int[] rolls = new int[20];

    public void start() {
        // reset rolls array if the method is called again
        for(int i = 0; i < rolls.length; i++) 
            rolls[i] = 0;            
        int count = 0;
        TwoDice myDice = new TwoDice();
        int point = 0; // placeholder value to initialize variable
        while(count < 20) {
            myDice.roll();
            int total = myDice.getTotal();
            rolls[count] = total;
            if(count == 0){ // first total 
                if(total == 7 || total == 11) {
                    System.out.println("You win!");
                    printArray();      
                    break;
                } else if(total == 2 || total == 3 || total == 12) {
                    System.out.println("You lose.");
                    printArray();
                    break;
                } else { // save point if didn't win or lose on first total
                    point = total;
                }
            } else { 
                if(total == point) { // win if new total is same as point
                    System.out.println("You win!");
                    printArray();
                    break;
                } else if(total == 7) { // lose if 7 is rolled before reaching the point
                    System.out.println("You lose.");
                    printArray();
                    break;
                }
            }
            count++;
        }
    }

    // Utility method to print the array of totals 
    private void printArray() {
        for(int i = 0; i < 20; i++) {
            System.out.print(rolls[i] + " ");
            if((i + 1) % 5 == 0) // Spacing for readability. 
                System.out.print("\t");  
        }
        System.out.println();
    }
}
