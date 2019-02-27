public class StackAL <T> implements Stack <T> {
    static int n = 0;
    int j;
    Object arr[];
    Integer i, size;
    StackAL() {
        i = 0;
        size = 2;
        arr = new Object[size];
    }
    public void push(T obj) {
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
        n--;
        T res = (T)arr[i-1];
        i--;
        return res;
    }
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
    public Integer returnSize() {
        return i;
    }
}