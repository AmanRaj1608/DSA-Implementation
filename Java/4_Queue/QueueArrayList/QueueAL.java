public class QueueAL <T> implements Queue <T> {
    static int n = 0;
    int j;
    Object arr[];
    Integer i, size;
    QueueAL() {
        i = 0;
        size = 2;
        arr = new Object[size];
    }
    public void enqueue(T obj) {
        ++n;
        arr[i] = obj;
            ++i;
            if(i.equals(size)) {
                Object newArr[];
                newArr = new Object[size*2];
                for(j = 0; j<size; j++)
                    newArr[j] = arr[j];
                size*=2;
                arr = newArr;
        }    
    }
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
        T res = (T)arr[0];
        for(int j=0; j<n; j++) {
            (T)arr[j] = (T)arr[j+1];
        }
        i--;
        n--;
        return res;
    }
    public Integer size() {
        return i;
    }
}