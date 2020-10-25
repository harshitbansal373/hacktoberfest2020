public class String_Buffer {
    public static void main(String[] args) {
    StringBuffer buffer = new StringBuffer();
    // Append the string representation of the argument to the end of the buffer.
    buffer.append("Hello World!");
    System.out.println(buffer.toString());
    // Delete the specified substring by providing the start and the end of the sequence.
    buffer.delete(5, 11);
    System.out.println(buffer.toString());
    
    // Delete just one char by providing its position.
    buffer.deleteCharAt(5);
    System.out.println(buffer.toString());
    // Insert a string in a specified place inside the buffer.
    buffer.insert(0, "World ");
    System.out.println(buffer.toString());
    // Get the index that the specified substring starts at.
    System.out.println("Index of Hello: " + buffer.indexOf("Hello"));
    System.out.println(); // Empty line
    // instantiate a new StringBuffer and provide the initial String in the constructor.
    StringBuffer newBuffer = new StringBuffer("This is a Hello World string. Hello!");
    // lastIndexOf(String) to get the last specified substring appears in the StringBuffer.
    System.out.println("Index of Hello: " + newBuffer.indexOf("Hello"));
    System.out.println("Last index of Hello: " + newBuffer.lastIndexOf("Hello"));
    // You can also replace a specific sub-sequence of the StringBuffer with another string.
    // The size does not need to be the same, as shown here.
    newBuffer.replace(0, 4, "That here");
    System.out.println(newBuffer.toString());
    // You can replace a single char using this method here. We want to
    // replace the last character of the string, so instead of counting the length,
    // we will use the provided length() method, and replace the char in the last index.
    newBuffer.setCharAt(newBuffer.length() - 1, '?');
    System.out.println(newBuffer.toString());
    // You can reverse the StringBuffer as well!
    newBuffer.reverse();
    System.out.println(newBuffer.toString());
    }
} 
