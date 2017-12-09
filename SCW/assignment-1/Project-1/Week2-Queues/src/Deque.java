import edu.princeton.cs.algs4.*;
//import edu.princeton.cs.algs4.Queue.Node;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.lang.*;

public class Deque<Item> implements Iterable<Item> {
	private int size;
	private Node<Item> first;
	private Node<Item> last;
	//private Node<Item> pt;
	//private Item content;
	
	private static class Node<Item>{
		private Item item;
		private Node<Item> previous;
		private Node<Item> next;
	}
	
	public Deque(){
		first=null;
		last=null;
		size=0;                                     
	}
	public boolean isEmpty() {
		return size==0;
	}
	public int size() {
		return size;
	}
	public void addFirst(Item item) {
		if(item==null){
			throw new IllegalArgumentException("Illegal Argument!");
		}
		Node<Item> newnode = new Node<Item>();
		if(size==0){
			newnode.previous=newnode.next=null;
			newnode.item=item;
			first=newnode;
			last=newnode;
		}
		else{
			newnode.next=first;
			newnode.previous=null;
			first.previous=newnode;
			newnode.item=item;
			first=newnode;
		}
		size++;
	}
    public void addLast(Item item) {
    	if(item==null){
			throw new IllegalArgumentException("Illegal Argument!");
		}
    	Node<Item> newnode = new Node<Item>();
		if(size==0){
			newnode.previous=newnode.next=null;
			newnode.item=item;
			first=newnode;
			last=newnode;
		}
		else{
			last.next=newnode;
			newnode.item=item;
			newnode.next=null;
			newnode.previous=last;
			last=newnode;
		}
		size++;
    }
    public Item removeFirst() {
    	if(isEmpty()){
    		throw new NoSuchElementException("Queue underflow");
    	}
    	//Node<Item> pt;
        //pt=first;
        Item content;
        content=first.item;
    	first=first.next;
    	size--;
    	if(isEmpty()){
    		first=last=null;
    	}
    	else{
    		first.previous=null;
    		//pt.next=null;
    	}  	
    	return content;
    }
    public Item removeLast() {
    	if(isEmpty()){
    		throw new NoSuchElementException("Queue underflow");
    	}
    	//Node<Item> pt;
        //pt=last;
    	Item content;
        content=last.item;
    	last=last.previous;
    	size--;
    	if(isEmpty()){
    		first=last=null;
    	}
    	else{
    		last.next=null;
    		//pt.previous=null;
    	}
    	return content;
    }
    public Iterator<Item> iterator() {
    	return new DequeIterator<Item>(first);
    }
    
    private class DequeIterator<Item> implements Iterator<Item>{
    	private Node<Item> current;

        public DequeIterator(Node<Item> first) {
            current = first;
        }

        public boolean hasNext()  { return current != null;                     }
        public void remove()      { throw new UnsupportedOperationException();  }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next; 
            return item;
        }
    }
    public static void main(String[] args)  {
    	
    }

}
