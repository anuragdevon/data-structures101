import java.util.*; 
import java.io.*; 
  
public class StackDemo { 
  
      // Main Method 
    public static void main(String args[]) 
    { 
        // Creating an empty Stack 
        Stack<String> stack = new Stack<String>(); 
  
        // Use push() to add elements into the Stack
        stack.push("W3Tech"); 
        stack.push("Blog");   
        // Displaying the Stack 
        System.out.println("Initial Stack: " + stack); 
  
        // Fetching the element at the head of the Stack 
        System.out.println("The element at the top of the"
                           + " stack is: " + stack.peek()); 
  
        // Displaying the Stack after the Operation 
        System.out.println("Final Stack: " + stack); 
    } 
}
