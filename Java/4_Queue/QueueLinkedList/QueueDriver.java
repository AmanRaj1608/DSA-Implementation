import java.util.Scanner;

public class QueueDriver {
    public static void main(String[] args) {
    Scanner s = new Scanner(System.in);    
    QueueAL <Integer> var = new QueueAL();
    int option=0, input, position;
        while(option != 4) {
            System.out.print("\n\n\t\tMENU:\n");
            System.out.println("<1> Enqueue");
            System.out.println("<2> Dequeue");
            System.out.println("<3> Display size");
            System.out.println("<4> Exit");
            System.out.println("Enter your option: ");
            option = s.nextInt();
            switch(option) {
                case 1: System.out.println("Enter an integer: ");
                        input = s.nextInt();
                        var.enqueue(input);
                        break;
                case 2: System.out.print("\n" + var.dequeue() + "\n");
                        break;
                case 3: System.out.print("\nSize = " + var.size() + "\n");
                    break;
            }
        }
    }
}