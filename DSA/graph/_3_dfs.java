package graph;

import java.util.List;
import java.util.ArrayList;

public class _3_dfs {
    public static void main(String[] args) {
        int n = 5;
        boolean visited[] = new boolean[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        List<Integer>[] adj = new List[n];
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

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, n, i, visited);
            }
        }
    }

    public static void dfs(List<Integer>[] adj, int v, int s, boolean visited[]) {
        visited[s] = true;
        System.out.print(s + " ");
        for (int i = 0; i < adj[s].size(); i++) {
            int vi = adj[s].get(i);
            if (!visited[vi]) {
                dfs(adj, v, vi, visited);
            }
        }
    }
}
