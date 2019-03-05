interface Queue <T> {
    public void enqueue(T obj);
    public T dequeue();
    public Integer size();
}