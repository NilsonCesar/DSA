import java.util.Iterator;

public class Deque<Item> implements Iterable<Item> 
{
    private Node first, last;
    private int n;

    private class Node 
    {
        Item item;
        Node prev = null, next = null;

        Node(Item item) {
            this.item = item;
        }
    }

    public Deque() 
    {
        first = new Node(null);
        last = new Node(null);
        first.next = last;
        last.prev = first;
        n = 0;
    }

    public boolean isEmpty() { return n == 0; }

    public int size() { return n; }

    public void addFirst(Item item)
    {
        if (item == null) throw new IllegalArgumentException();

        Node newFirst = new Node(item);
        newFirst.next = first.next;
        newFirst.prev = first;
        first.next.prev = newFirst;
        first.next = newFirst;
        n++;
    }

    public void addLast(Item item)
    {
        if (item == null) throw new IllegalArgumentException();

        Node newLast = new Node(item);
        newLast.next = last;
        newLast.prev = last.prev;
        last.prev.next = newLast;
        last.prev = newLast;
        n++;
    }

    public Item removeFirst()
    {
        if (isEmpty()) throw new java.util.NoSuchElementException();

        Item item = first.next.item;
        first.next = first.next.next;
        first.next.prev = first;
        n--;

        return item;
    }

    public Item removeLast()
    {
        if (isEmpty()) throw new java.util.NoSuchElementException();

        Item item = last.prev.item;
        last.prev = last.prev.prev;
        last.prev.next = last;
        n--;

        return item;
    }

    public Iterator<Item> iterator() { return new DequeIterator(); }

    private class DequeIterator implements Iterator<Item>
    {
        private Node current = first;

        public boolean hasNext() { return current.next != last; }
        public void remove() { throw new UnsupportedOperationException(); }
        public Item next()
        {
            if (!hasNext()) throw new java.util.NoSuchElementException();

            current = current.next;
            return current.item;
        }
    }
}