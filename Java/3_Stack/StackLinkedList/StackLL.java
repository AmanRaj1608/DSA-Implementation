public class StackLL <T> implements Stack <T> {
    
    Node head; // First Node
    int size; // number of items
    //  class defining node
    class Node {
        T obj;
        Node next;
    }
    //  Constructor
    public StackLL() {
        head = null;
        size = 0;
    }


    //          Defining functions
    //  1. PUSH (adding at begining)
    public void push(T obj) {
        Node oldHead = head;
        head = new Node();
        head.obj = obj;
        head.next = oldHead;
        size++;
    }
    //  2. POP (removing from start)
    public T pop() {
        try {            
            if(n == 0) {
                BoundsException E = new BoundsException();
                throw E;
            }
        } catch (BoundsException e) {
            e.printError();
            System.out.print("\nStack is empty.\n");
            return null;
        }
        T obj = head.next;
        head = head.next;
        size--;
        return obj;
    }
    //  3. PEAK
    public T peak() {
        try {
            if(n == 0) {
                BoundsException E = new BoundsException();
                throw E;
            }
        } catch (BoundsException e) {
            e.printError();
            System.out.print("\nStack is empty.\n");
            return null;
        }
        return (T)arr[i-1];
    }
    //  4. size
    public Integer size() {
        return size;
    }
}