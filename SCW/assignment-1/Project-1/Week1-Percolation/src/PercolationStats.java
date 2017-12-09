import edu.princeton.cs.algs4.*;

public class PercolationStats {
//	private final double res_mean;
//	private final double res_stddev;
	private double recT[];
	private final int N;
	private final int T;
	
	   public PercolationStats(int n, int trials){
		   if(n<=0){
			   throw new IllegalArgumentException();
		   }
		   if(trials<=0){
			   throw new IllegalArgumentException();
		   }
		   recT = new double[trials];
		   this.N=n;
		   this.T=trials;
		   int times = 0;
		   while(times<trials){
			   Percolation percolation = new Percolation(N);
			   boolean[][] arrOpen = new boolean[N+1][N+1];
			   int count = 0;
			   while(true){
				   //count++;
				   while(true){
					   int x = StdRandom.uniform(N)+1;
					   int y = StdRandom.uniform(N)+1;
					   if(arrOpen[x][y]){
						   continue;
					   }
					   else{
						   percolation.open(x, y);
						   arrOpen[x][y] = true;
						   count++;
						   break;
					   }
				   }
				   if(percolation.percolates()){
					   recT[times] = (double)count/((double)N*(double)N);
					   break;
				   }
			   }
               times++;
		   }
		 //  this.res_mean = StdStats.mean(recT);
		 //  this.res_stddev = StdStats.stddev(recT);
	   }
	   public double mean(){
		   return StdStats.mean(recT);// sample mean of percolation threshold
	   }
	   public double stddev(){
		   return StdStats.stddev(recT);// sample standard deviation of percolation threshold
	   }
	   public double confidenceLo(){
		   return mean() - 1.96 * stddev()/Math.sqrt(T);// low  end point of 95% confidence interval
	   }
	   public double confidenceHi() {
		   return mean() + 1.96 * stddev()/Math.sqrt(T);// high end point of 95% confidence interval
	   }
	   public static void main(String[] args){
		   int NN = StdIn.readInt();
		   int TT = StdIn.readInt();
		   PercolationStats percolationStats = new PercolationStats(NN,TT);
		   double mean = percolationStats.mean();
		   double stddev = percolationStats.stddev();
		   StdOut.println("mean = "+ mean );
		   StdOut.println("stddev = "+ stddev);
		   StdOut.println("95% confidence interval" + percolationStats.confidenceLo() +","+percolationStats.confidenceHi());// test client (described below)
	   }

}
