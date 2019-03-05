class ListObject<T>{
    T value;
    ListObject<T> next;
    ListObject(T n) {
        value = n;
        next=null;
    }
}