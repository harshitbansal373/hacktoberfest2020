import java.util.Scanner;

public class DoublyLinkedListAlgoritm {

    public static Scanner sc = new Scanner(System.in);

    public static void main(String [] args) throws Exception{

        DoublyLinkedList list = new DoublyLinkedList();

        list.addBeginning(1);
        list.addBeginning(2);
        list.addEnd(4);
        list.add(3, 2);
        
        list.print();

        list.remove(1);

        list.print();

    }
}

    class Node {

        public int element;
        public Node previous;
        public Node next;
    
        public Node() {
            this(0);
        }
    
        public Node(int element) {
            this.element = element;
            this.previous = this.next = null;
        }
    }

    class DoublyLinkedList {

        private Node first;
        private Node last;
    

        public DoublyLinkedList() {
            first = new Node();
            last = first;
        }
    

        public void addBeginning(int x) {
            
            Node tmp = new Node(x);
    
            tmp.previous = first;
            tmp.next = first.next;
            first.next = tmp;
            if(first == last){
                last = tmp;
            }else{
                tmp.next.previous = tmp;
            }
            tmp = null;
        }
    

        public void addEnd(int x) {
            last.next = new Node(x);
            last.next.previous = last;
            last = last.next;
        }
    
        public int removeBeginning() throws Exception {
            if (first == last) {
                throw new Exception("Erro ao remove (vazia)!");
            }
    
            Node tmp = first;
            first = first.next;
            int removedElement = first.element;
            tmp.next = first.previous = null;
            tmp = null;
            return removedElement;
        }
    
        public int removeEnd() throws Exception {
            if (first == last) {
                throw new Exception("Erro ao remove (vazia)!");
            } 
            int removedElement = last.element;
            last = last.previous;
            last.next.previous = null;
            last.next = null;
            return removedElement;
        }
    
        public void add(int x, int pos) throws Exception {
    
            int size = size();
    
            if(pos < 0 || pos > size){
                throw new Exception("Erro ao add posicao (" + pos + " / size = " + size + ") invalida!");
            } else if (pos == 0){
                addBeginning(x);
            } else if (pos == size){
                addEnd(x);
            } else {
                Node i = first;
                for(int j = 0; j < pos; j++, i = i.next);
    
                Node tmp = new Node(x);
                tmp.previous = i;
                tmp.next = i.next;
                tmp.previous.next = tmp.next.previous = tmp;
                tmp = i = null;
            }
        }
    
        public int remove(int pos) throws Exception {

            int removedElement;
            int size = size();
    
            if (first == last){
                throw new Exception("Error while removing, list is empty!");
            } else if(pos < 0 || pos >= size){
                throw new Exception("Error while removing (position " + pos + " / " + size + " invalid!");
            } else if (pos == 0){
                removedElement = removeBeginning();
            } else if (pos == size - 1){
                removedElement = removeEnd();
            } else {
                Node i = first.next;
                for(int j = 0; j < pos; j++, i = i.next);
    
                i.previous.next = i.next;
                i.next.previous = i.previous;
                removedElement = i.element;
                i.next = i.previous = null;
                i = null;
            }
    
            return removedElement;
        }
    
        public void print() {
            int position = 0;
            for (Node i = first.next; i != null; i = i.next) {
                System.out.print("[" +position + "]" +i.element+ " ");
                position++;
            }
            System.out.println();
        }
    
        public void printReverse() {
            System.out.print("[ ");
            for (Node i = last; i != first; i = i.previous){
                System.out.print(i.element + " ");
            }
            System.out.println("] "); 
        }
    
        public int size() {
            int size = 0; 
            for(Node i = first; i != last; i = i.next, size++);
            return size;
        }
    }