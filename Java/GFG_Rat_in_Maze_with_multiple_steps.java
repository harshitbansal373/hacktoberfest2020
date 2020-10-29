public class GFG_Rat_in_Maze_with_multiple_steps {


    public static boolean solve_multi_jump(int [][]maze,int sol[][],int si,int sj, int ei,int ej, boolean vis[][]){
        if(si>ei||sj>ej||vis[si][sj]==true)
            return false;
        if(si==ei&&sj==ej){
            // System.out.println("path found");
            sol[si][sj]=1;
            return true;
        }
        vis[si][sj]=true;
        boolean res=false;
        for(int i=1;i<=maze[si][sj];i++)
        {
            res=res||solve_multi_jump(maze, sol, si, sj+i, ei, ej, vis);
            res=res||solve_multi_jump(maze, sol, si+i, sj, ei, ej, vis);
        }
        vis[si][sj]=false;
        if(res)
            sol[si][sj]=1;
        // System.out.println("path found");
        return res;
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int maze[][]=new int[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                maze[i][j]=s.nextInt();
        int sol[][]=new int[n][n];
        solve_multi_jump(maze,sol,0,0,n-1,n-1,new boolean[n][n]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                System.out.print(sol[i][j]+"  ");
            System.out.println();
        }
        s.close();
    }
}
