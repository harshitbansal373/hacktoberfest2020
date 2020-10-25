import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        
        Scanner scn = new Scanner(System.in);
        int r = scn.nextInt();
        int c = scn.nextInt();
        int [][]mat = new int[r][c];
        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                mat[i][j]=scn.nextInt();
            }
        }
        spiraldisp(mat);
    }
    
    public static void spiraldisp(int [][] mat){
        int rmin=0,rmax=mat.length-1;
        int cmin=0,cmax=mat[0].length-1;
        
        int count = 1;
        int n = (rmax+1)*(cmax+1);
        while(count<=n){
        //leftwall
        for(int i=rmin;i<=rmax && count<=n;i++){
            System.out.println(mat[i][cmin]);
            count++;
        }
        cmin++;
        
        //bottomwall
        for(int j=cmin;j<=cmax && count<=n;j++){
            System.out.println(mat[rmax][j]);
            count++;
        }
        rmax--;
        
        //rightwall
        for(int i=rmax;i>=rmin && count<=n;i--){
            System.out.println(mat[i][cmax]);
            count++;
        }
        cmax--;
        
        //top
        for(int j=cmax;j>=cmin && count<=n;j--){
            System.out.println(mat[rmin][j]);
            count++;
        }
        rmin++;
    }}
}
