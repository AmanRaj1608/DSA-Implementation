import java.util.*;

public class Driver {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        ArrayList var = new ArrayList();
        int option, input, position, choice=1;
        while(choice == 1) {
            System.out.print("\n\nMENU:\n");
            System.out.print("\n<1> Add an element (without position)\n");
            System.out.print("\n<2> Search for an element\n");
            System.out.print("\n<3> Get the element at a position\n");
            System.out.print("\n<4> Traverse (display all the elements)\n");
            System.out.print("\n<5> Check if the list is empty\n");
            System.out.print("\nEnter your option: ");
            option = s.nextInt();
            switch(option) {
                case 1: System.out.print("\nEnter an integer: ");
                    input = s.nextInt();
                    var.add(input);
                    break;
                case 2: System.out.print("\nEnter an integer: ");
                    input = s.nextInt();
                    if(!var.search(input))
                        System.out.println("\nValue NOT found.\n");
                    break;
                case 3: System.out.print("\nEnter position: ");
                    position = s.nextInt();
                    if(!var.getElementAt(position))
                        System.out.println("\nElement NOT found.\n");
                    break;
                case 4: var.traverse();
                    break;
                case 5: if(var.isEmpty())
                    System.out.println("\nThe list is empty.\n");
                else
                    System.out.println("\nThe list is NOT empty.\n");
                    break;
                default: System.out.print("\nERROR! Wrong input.\n");
            }
            System.out.print("\nDo you want to use the Menu again? Enter 1 for a YES.\n");
            choice = s.nextInt();
        }
    }
}