import edu.princeton.cs.algs4.*;

public class Percolation {
	private final WeightedQuickUnionUF uf;
	private final int N;
	private int counter=0;
	private byte[] array;
	private int[] roots;
	private int root=-1;
	//private int rooto=-1;
	private boolean ispercolate=false;
	
    public Percolation(int n){
    	if(n<=0){
    		throw new IllegalArgumentException();
    	}
    	this.N = n;
    	roots = new int[4];
    	for(int i=0;i<4;i++){
    		roots[i]=-1;
    	}
    	uf = new WeightedQuickUnionUF(n*n+n+1);
    	array = new byte[n*n+n+1];
        for(int i=1;i<=n;i++){
    		array[1*n+i]=1;
    		array[n*n+i]=2;
    	}
       // array[0*n+1]=1;

    }
    public void open(int row,int col){
    	if(row<1||row>N){
    		throw new IllegalArgumentException("Row "+row+" out of Bounds");
    	}
    	if(col<1||col>N){
    		throw new IllegalArgumentException("Column "+col+" out of Bounds");
    	}
    	if(array[row*N+col]>=4){
    		return;
    	}
    	for(int i=0;i<4;i++){
    		roots[i]=-1;
    	}
    	
    	array[row*N+col]=(byte) (array[row*N+col]+4);
    	counter++;
    	byte origin = array[row*N+col];
    	
        if((col!=1) && (array[row*N+col-1] >=4)){
        	roots[0] = uf.find(row*N+col-1);
        	uf.union(row*N+col, row*N+col-1);
        }
        if((col!=N) && (array[row*N+col+1] >=4)){
        	roots[1] = uf.find(row*N+col+1);
        	uf.union(row*N+col, row*N+col+1);
        }
        if((row!=1) && (array[(row-1)*N+col] >=4)){
        	roots[2] = uf.find((row-1)*N+col);
        	uf.union(row*N+col, (row-1)*N+col);
        }
        if((row!=N) && (array[(row+1)*N+col] >=4)){
        	roots[3] = uf.find((row+1)*N+col);
        	uf.union(row*N+col, (row+1)*N+col);
        }
        root=uf.find(row*N+col);
        for(int i=0;i<4;i++){
        	if(roots[i]!=-1){
        		array[roots[i]]=(byte)(array[root]|array[roots[i]]);
        		array[root]=(byte)(array[root]|array[roots[i]]);
        	}
        }
        array[root]=(byte) (array[root]|origin);
        if((array[root] ==7) || (N==1))ispercolate=true;
    	
    }
    public boolean isOpen(int row,int col){
    	if(row<1||row>N){
    		throw new IllegalArgumentException("Row "+row+" out of Bounds");
    	}
    	if(col<1||col>N){
    		throw new IllegalArgumentException("Column "+col+" out of Bounds");
    	}
    	return (array[N*row+col] >=4);
    }
    public boolean isFull(int row,int col){
    	if(row<1||row>N){
    		throw new IllegalArgumentException("Row "+row+" out of Bounds");
    	}
    	if(col<1||col>N){
    		throw new IllegalArgumentException("Column "+col+" out of Bounds");
    	}
    	//return ufw.connected(row*N+col,0*N+1) && array[row*N+col];
    	int ro;//ro = uf.find(row*N+col);
    	if(N==1 && array[row*N+col]>=4)return true;
    	else{
    		 ro = uf.find(row*N+col);
             return ((array[ro] & 0b101) == 0b101) && (array[row*N+col] >=4);
    	}
    }
    public int numberOfOpenSites(){
    	return counter;
    }
    public boolean percolates(){
    	
    	return ispercolate;
    }
    public static void main(String[] args){
  /*  	int n = StdIn.readInt();
    	int o = StdIn.readInt();
    	int k =o;
    	Percolation percolation = new Percolation(n);
    	while(o>0){
    		int x = StdRandom.uniform(n)+1;
    		int y = StdRandom.uniform(n)+1;
    		percolation.open(x, y);
    		o--;
    	}
    	StdOut.println(n+"x"+n+",open sites:"+k+"\n");
    	if(percolation.percolates())StdOut.println("Percolates.\n");
    	else StdOut.println("Doesn't percolate.\n");
    	*/
    }
    
}
