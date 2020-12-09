public class Stack<Item> {

   private Item[] a;
   private int n;

   
   public Stack() {
      a = (Item[]) new Object[2];
      n = 0;
   }

  
   public boolean isEmpty() {
      return n == 0;
   }
   
   public void push(Item item) { 
      if (n == a.length)
         resize(2 * a.length);
      a[n++] = item;
   }

   public Item pop() {
      Item item = a[--n];
      if (n > 0 && n == a.length/4)
         resize(a.length/2);
      return item;
   }

   private void resize(int max) {
      Item[] temp;
      temp = (Item[]) new Object[max];
      for (int i = 0; i < n; i++)
         temp[i] = a[i];
      a = temp;
   }
}