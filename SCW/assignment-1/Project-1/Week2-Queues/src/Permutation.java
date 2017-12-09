import edu.princeton.cs.algs4.*;
import java.lang.*;

public class Permutation {
	public static void main(String[] args){
		int k=Integer.parseInt(args[0]);
		RandomizedQueue<String> strQueue = new RandomizedQueue<String>();
		String str;
		String strRead;
		double N=1.0;
		while(!StdIn.isEmpty()){
			str=StdIn.readString();
			if(k==0){
				break;
			}
			else if(strQueue.size()<k){
				strQueue.enqueue(str);
			}
			else if(StdRandom.uniform()>(N-k)/N){
				strQueue.dequeue();
				strQueue.enqueue(str);
			}
			N++;
		}
		for(int i=0;i<k;i++){
			strRead=strQueue.dequeue();
			StdOut.println(strRead);
		}
	}
	
}
