import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {
        binarySearchTree var = new binarySearchTree();
        Scanner s = new Scanner(System.in);
        Integer input, option;
        do {
            System.out.print("\n\nBINARY SEARCH TREE (BST)\n");
            System.out.print("\n<1> Insert a number");
            System.out.print("\n<2> Delete a number");
            System.out.print("\n<3> Check if a number is present in the BST");
            System.out.print("\n<4> Display Maximum value");
            System.out.print("\n<5> Display Maximum value");
            System.out.print("\n<6> Display all the numbers present in the BST in increasing order");
            System.out.print("\n<7> Exit");
            System.out.print("\n\nEnter your option: ");
            option = s.nextInt();
            switch(option) {
                case 1: System.out.print("\nEnter an integer: ");
                        input = s.nextInt();
                        var.insert(input);
                        break;
                case 2: System.out.print("\nEnter an integer: ");
                        input = s.nextInt();
                        var.insert(input);
                        break;
                case 3: System.out.print("\nEnter an integer: ");
                        input = s.nextInt();
                        if(var.contains(input))
                            System.out.print("\n" + input + " is present in the BST\n");
                        else
                            System.out.print("\n" + input + " is NOT present in the BST.\n");
                        break;
                case 4: var.maxm();
                        break;
                case 5: var.minm();
                        break;
                case 6: System.out.print("\n");
                        var.printInOrder();
                        System.out.print("\n");
                        break;
            }
        } while(option != 7);
    }
}
