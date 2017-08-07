import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
public class PercolationStats {
    private int trialTimes;
    private double[] pocuResult;
    public PercolationStats(int n, int trials){
        trialTimes = trials;
        for(int i = 0; i<trials; i++){
            Percolation p = new Percolation(n);
            while(!p.percolates()){
                int col = StdRandom.uniform(1,n+1);
                int row = StdRandom.uniform(1,n+1);
                p.open(row,col);
            }
            pocuResult[i] = p.numberOfOpenSites()*1.0/n;
        }
    }    
    public double mean(){
        return StdStats.mean(pocuResult);
    }                          
    public double stddev(){
        return StdStats.stddev(pocuResult);
    }                    
    public double confidenceLo(){
        return this.mean()-1.96*this.stddev()/Math.sqrt(trialTimes);
    }                  
    public double confidenceHi(){
         return this.mean()+1.96*this.stddev()/Math.sqrt(trialTimes);
    }                  
    public static void main(String[] args){
        PercolationStats ps = new PercolationStats(Integer.parseInt(args[0]),
                    Integer.parseInt(args[1]));

        System.out.printf("mean                     = %f\n", ps.mean());
        System.out.printf("stddev                   = %f\n", ps.stddev());
        System.out.printf("95%% confidence Interval  = %f, %f\n",
                ps.confidenceLo(), ps.confidenceHi());
    }        
}