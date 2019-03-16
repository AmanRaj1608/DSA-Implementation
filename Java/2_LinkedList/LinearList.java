public class LinearList<T> implements List<T> {
    ListObject<T> head;
    ListObject<T> tail;
    ListObject<T> iter;
    Integer pos;
    
    LinearList(){
        tail = head = null;
    }
    public void add(T i){
        ListObject<T> obj = new ListObject<T>(i);
        if(head==null){
            head = tail = obj;
        }
        else {
            tail.next = obj;
            tail = obj;
        }
    }
    
    public void add(T i , Integer pos ){
        try {
            if(pos < 0)
                throw new BoundsException();
        } catch(BoundsException e) {
            e.printError();
        }
        ListObject <T> obj = new ListObject(i);
        if(head == null)
            head = tail = obj;
        else {
            tail.next = obj;
            tail = obj;
        }
    }
	
    public void traverse(){
        iter=head;
	    while(iter!=null){
	        System.out.print(iter.value + " ");
	        iter=iter.next;
	    }
        System.out.print("\n");
    }
    
    public boolean isEmpty() {
        return (head == null);
    }
    
    public int size(){
        iter = head;
        int count = 0;
        while(iter!=null){
            count++;
            iter=iter.next;
        }
        return count;
    }

    public boolean search(T i) {
        ListObject <T> searchObj = head;
        while(searchObj != null) {
            if(searchObj.value == i)
                return true;
            searchObj = searchObj.next;
        }
        return false;
    }
    
    public boolean getElementAt(T pos) {
        ListObject <T> element = head;
        Integer count = 0;
        while(element != null) {
            if(count.equals(pos)) {
                System.out.println(element.value);
                return true;
            }
            element = element.next;
            count++;
        }
        return false;
    }

    public void reverse(ListObject <T> rev) {
        if(rev == null)
            return ;
        reverse(rev.next);
        System.out.print(rev.value + " ");
    }
    
}
