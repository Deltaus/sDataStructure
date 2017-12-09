import edu.princeton.cs.algs4.*;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.lang.*;

public class RandomizedQueue<Item> implements Iterable<Item> {
	private Item[] stack;
	private int size=0;
	
	public RandomizedQueue() {
		stack=(Item[]) new Object[2];
	}
	public boolean isEmpty(){
		return size==0;
	}
    public int size(){
    	return size;
    }
    public void enqueue(Item item){
    	if(item==null){
			throw new IllegalArgumentException("Illegal Argument!");
		}
    		if(size==stack.length)Resize(2*stack.length);
    		stack[size]=item;
    		size++;
    }
    public Item dequeue(){
    	if(isEmpty()){
    		throw new NoSuchElementException();
    	}
    	int label=StdRandom.uniform(size);
    	Item toDrop=stack[label];
    	if(label!=size-1){
    		stack[label]=stack[size-1];
    	}
    	stack[size-1]=null;
    	size--;
    	if(size>0&&size==stack.length/4)Resize(stack.length/2);
    	return toDrop;
    }
    public Item sample(){
    	if(isEmpty()){
    		throw new NoSuchElementException();
    	}
    	int label=StdRandom.uniform(size);
    	Item toSamp=stack[label];
    	return toSamp;
    }
    public Iterator<Item> iterator(){
    	return new RQueueIterator();
    }
    private class RQueueIterator implements Iterator<Item>{
    	private Item[] iterArr=(Item[]) new Object[stack.length];
    	//private Item[] iterArr=new Item[stack.length];
    	private int num = size; 

        public RQueueIterator() {
            for(int i=0;i<num;i++){
            	 iterArr[i]=stack[i];
        	}
            
        }

        public boolean hasNext()  { return num!=0;                     }
        public void remove()      { throw new UnsupportedOperationException();  }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            int sublabel=StdRandom.uniform(num);
        	Item nextone=iterArr[sublabel];
        	if(sublabel!=num-1){
        	     iterArr[sublabel]=iterArr[num-1];
        	}
        	iterArr[num-1]=null;
        	num--;
            return nextone;
        }
    }
    
    private void Resize(int capacity){
    	assert capacity>=size;
    	Item[] copy =(Item[])new Object[capacity];
    	for(int i=0;i<size;i++){
    		copy[i]=stack[i];
    	}
    	stack=copy;
    }
    public static void main(String[] args){
    	
    }

}
