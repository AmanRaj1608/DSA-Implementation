import java.util.Scanner;

public class StackDriver {
    public static void main(String[] args) {
    Scanner s = new Scanner(System.in);    
    StackAL <Integer> var = new StackAL();
    int option, input, position;
        do {
            System.out.print("\n\nMENU:\n");
            System.out.print("\n<1> Push\n");
            System.out.print("\n<2> Pop\n");
            System.out.print("\n<3> Display top-most element\n");
            System.out.print("\n<4> Display size\n");
            System.out.print("\n<5> Exit\n");
            System.out.print("\nEnter your option: ");
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
                default:
                        System.out.println("Wrong choice!\n");
                        break;
            }
        } while(option != 5);
    }
}
