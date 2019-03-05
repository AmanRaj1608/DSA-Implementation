import java.util.Scanner;

public class StackDriver {
    public static void main(String[] args) {
    Scanner s = new Scanner(System.in);    
    StackLL <Integer> var = new StackLL();
    int option=0, input, position;
        while(option != 5) {
            System.out.print("\n\n\t\tMENU:\n");
            System.out.println("<1> Push");
            System.out.println("<2> Pop");
            System.out.println("<3> Display top-most element\n");
            System.out.println("<4> Display size");
            System.out.println("<5> Exit");
            System.out.println("\nEnter your option: ");
            option = s.nextInt();
            switch(option) {
                case 1: System.out.print("\nEnter an integer: ");
                        input = s.nextInt();
                        var.push(input);
                        break;
                case 2: System.out.print("\n" + var.pop() + "\n");
                        break;
                case 3: System.out.print("\n" + var.peak() + "\n");
                        break;
                case 4: System.out.print("\nSize = " + var.returnSize() + "\n");
                    break;
            }
        }
    }
}