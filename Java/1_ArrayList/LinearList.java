public class ArrayList implements List {
    static int n = 0;
    Integer i, size, arr[];
    int j;
    ArrayList() {
        i = 0;
        size = 2;
        arr = new Integer[size];
    }
    public void add(Integer input) {
        n++;
        arr[i] = input;
        i++;
        if(i.equals(size)) {
            Integer newArr[]1
            ;
            newArr = new Integer[size*2];
            for(j = 0; j<size; j++)
                newArr[j] = arr[j];
            size*=2;
            arr = newArr;
        }
    }
    public void traverse() {
        for(j = 0; j<i; j++)
            System.out.print(arr[j] + " ");
        System.out.print("\n");
    }
    public boolean isEmpty() {
        if(n == 0)
            return true;
        return false;
    }
    public boolean search(Integer searchObj) {
        for(j = 0; j<i; j++) {
            if(arr[j].equals(searchObj)) {
                System.out.print(searchObj + " found at position: " + (j + 1) + "\n");
                return true;
            }
        }
        return false;
    }
    public boolean getElementAt(Integer position) {
        if(position >= 1 && position <= i) {
            System.out.print("Element at position " + position + " is: " + arr[position - 1] + "\n");
            return true;
        }
        return false;
    }
}
