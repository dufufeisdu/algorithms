import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
public class Percolation {
    private WeightedQuickUnionUF experiment; 
    private int n; 
    private boolean []openIndicator ;
    public Percolation(int n) { 
      this.n = n;
      openIndicator = new boolean[n*n+2];
      experiment = new WeightedQuickUnionUF(n*n+2); 
      openIndicator[0]=true;
      openIndicator[n*n+1]=true;
      for(int i = 1; i<n*n+1;i++){
      openIndicator[i] = false;
      }
    }
    private int xyTo1D(int row, int col){
        if(isIndexValid(row,col)){
            if(row==0){
                return 0;
            }else if(row==n){
                return n*n+1;
            }else{
                return n*(row-1)+col;
            }
        }else{
          throw new IndexOutOfBoundsException("index out of bounds");   
        }
         
    }
    private boolean isIndexValid(int row, int col){
        if(row==0&&(col>=1||col<=n)){
            return true;
        }
        if(row==n&&(col>=1||col<=n)){
        return true;
        }
        if( row<0&&row>n+1){
          // throw new IndexOutOfBoundsException("row index i out of bounds");
            return false;
        }
        if(col<0&&col>n+1){
         //   throw new IndexOutOfBoundsException("col index j out of bounds");
            return false;
        }
        return true;
    }
    public void open(int row, int col){
        if(!isOpen(row,col)){
            if(isIndexValid(row,col)){
            openIndicator[xyTo1D(row,col)]=true;        
        }
        if(isIndexValid(row+1,col)){
            int p = xyTo1D(row,col);
            int q = xyTo1D(row+1,col);
            if(openIndicator[q]){
              experiment.union(p,q);  
            }
        }
        if(isIndexValid(row-1,col)){
          int p = xyTo1D(row,col);
            int q = xyTo1D(row-1,col);
            if(openIndicator[q]){
              experiment.union(p,q);  
            }       
        }
        if(isIndexValid(row,col+1)){
           int p = xyTo1D(row,col);
            int q = xyTo1D(row,col+1);
            if(openIndicator[q]){
              experiment.union(p,q);  
            }      
        }
        if(isIndexValid(row,col-1)){
          int p = xyTo1D(row,col);
            int q = xyTo1D(row,col-1);
            if(openIndicator[q]){
              experiment.union(p,q);  
            }       
        }
      }
    }
    public boolean isOpen(int row, int col){
       int p = xyTo1D(row,col);
       return openIndicator[p];
    }
    public boolean isFull(int row, int col){
        int q = xyTo1D(row,col);
        return experiment.connected(0,q);
    }
    public int numberOfOpenSites(){
        return n*n-experiment.count();
    }       
    public boolean percolates(){
        return experiment.connected(0,n*n+1);
    }             

    public static void main(String[] args){
        Percolation p = new Percolation(10);
        p.open(1,1);
        p.open(1,2);
        System.out.println(p.isOpen(1,1));
        System.out.println(p.numberOfOpenSites());
    }   // test client (optional)
}
    