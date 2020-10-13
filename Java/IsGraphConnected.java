import java.util.*;

public class is_graph_connected {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int nodes = s.nextInt();
		int edgesnumber = s.nextInt();
		int[][] edge = new int[nodes][nodes];
		
		for(int i=0; i<edgesnumber; i++)
		{
			int firstvertex = s.nextInt();
			int secondvertex = s.nextInt();
			edge[firstvertex][secondvertex]=1;
			edge[secondvertex][firstvertex]=1;
		}
		
		boolean visited[]  = new boolean[edge.length];
		help(edge, visited,0);
		
		//checking if all the nodes are visited
		int i=0;
        while(i<visited.length){
            if(visited[i]!=true){
                System.out.print("false");
                System.exit(0);
            }
            i++;
        }
          System.out.print("true");
          System.exit(0);
	}
	
	//function that assigns all the nodes that are connected as true
	private static void help(int[][] edge, boolean[] visited, int firstvertex) {
		visited[firstvertex] = true;
		
		for(int i=0; i<edge.length; i++)
		{
			if(edge[firstvertex][i]==1 && !visited[i])
				help(edge, visited, i);
		}
	}


}
