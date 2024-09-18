package graph;
import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
public class _1_bfs {
  public static void main(String[] args) {
    int n = 5;
    boolean visited[] = new boolean[n];
    for (int i = 0; i < n; i++) {
      visited[i] = false;
    }
    List adj[] = new List[n];
    for (int i = 0; i < n; i++) {
      adj[i] = new ArrayList<>();
    }
    adj[0].add(1);
    adj[0].add(2);
    adj[1].add(0);
    adj[1].add(2);
    adj[1].add(3);
    adj[2].add(0);
    adj[2].add(1);
    adj[2].add(3);
    adj[3].add(1);
    adj[3].add(2);
    adj[3].add(4);
    adj[4].add(3);
    System.out.println(adj[0]);
    for(int i=0;i<n;i++){
      if(!visited[i]){
        bfs(adj,n,i,visited);
      }
    }
  }
  public static void bfs(List<Integer> adj[], int v, int s,boolean visited[]) {
    visited[s]=true;
    Queue<Integer> q = new LinkedList<>();
    q.add(s);
    while(!q.isEmpty()){
      int u=q.poll();
      System.out.print(u+" ");
      for(int i=0;i<adj[u].size();i++){
        int vi=adj[u].get(i);
        if(!visited[vi]){
          visited[vi]=true;
          q.add(vi);
        }

      }
    }
  }
}
