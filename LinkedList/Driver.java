import java.util.*;
//import java.io;

public class Driver {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        LinearList <Integer> var = new LinearList();
        int option, input, position, choice;
        do {
            System.out.print("\n\nMENU:");
            System.out.println("\n<1> Add an element (without position)");
            System.out.println("\n<2> Add an element (with position)");
            System.out.println("\n<3> Search for an element");
            System.out.println("\n<4> Get the element at a position");
            System.out.println("\n<5> Traverse (display all the elements)");
            System.out.println("\n<6> Check if the list is empty");
            System.out.println("\n<7> Display the list in reverse order");
            System.out.println("\nEnter your option: ");
            option = s.nextInt();
            switch(option) {
                case 1: System.out.print("\nEnter an integer: ");
                    input = s.nextInt();
                    var.add(input);
                    break;
                case 2: System.out.print("\nEnter an integer: ");
                    input = s.nextInt();
                    System.out.print("\nEnter position: ");
                    position = s.nextInt();
                    var.add(input, position);
                    break;
                case 3: System.out.print("\nEnter an integer: ");
                    input = s.nextInt();
                    if(var.search(input))
                        System.out.println("\nValue found.\n");
                    else
                        System.out.println("\nValue NOT found.\n");
                    break;
                case 4: System.out.print("\nEnter position: ");
                    position = s.nextInt();
                    if(!var.getElementAt(position))
                        System.out.println("\nElement NOT found.\n");
                    break;
                case 5: var.traverse();
                    break;
                case 6: if(var.isEmpty())
                    System.out.println("\nThe list is empty.\n");
                else
                    System.out.println("\nThe list is NOT empty.\n");
                    break;
                case 7: var.reverse(var.head);
                    System.out.print("\n");
                    break;
                default: System.out.print("\nERROR! Wrong input.\n");
            }
            System.out.print("\nDo you want to use the Menu again? Enter 1 for a YES.\n");
            choice = s.nextInt();
        } while(choice == 1);
    }
}
