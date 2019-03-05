public class QueueLL <T> implements Stack <T> {
    
    Node head,tail; // Begin and end nodes
    int size; // number of items
    //  class defining node
    class Node {
        T obj;
        Node next;
    }
    //  Constructor
    public QueueLL() {
        head = null;
        tail = null;
        size = 0;
    }


    //          Defining functions
    //  1. ENQUEUE ( Add element at end of list )
    public void enqueue(T obj) {
        Node oldTail = tail;
        tail = new Node();
        tail.obj = obj;
        tail.next = null;
        if(size==0){
            head = tail;
        } else {
            oldTail.next = tail;
        }
        size++;
    }
    //  2. DEQUEUE (removing from beginning)
    public T dequeue() {
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
        T obj = head.obj;
        head = head.next;
        if(size==0) {
            tail = null;
        }
        size--;
        return obj;
    }
    //  3. size
    public Integer size() {
        return size;
    }
}