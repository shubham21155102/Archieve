# Dikstra's Algorithm

---

Given a weighted, undirected and connected graph of **V** vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the** first **integer of each list **j** denotes there is **edge** between i and j , second integers corresponds to the **weight** of that edge . You are given the source vertex **S** and You to Find the shortest distance of all the vertex's from the source vertex **S** . You have to return a list of integers denoting shortest distance between **each node** and Source vertex ** S** .

---

**Note**: The Graph doesn't contain any negative weight cycle.

The structure of adjacency list is as follows :-

For Example : **adj** = { **{{1, 1}, {2, 6}}** , **{{2, 3}, {0, 1}}** , **{{1, 3}, {0, 6}}** }

Here **adj[i]** contains a list which contains all the nodes which are connected to the ith vertex. Here **adj[0] = ** **{** **{1, 1}, {2, 6}}** means there are **two **nodes conneced to the **0**th node, **node 1 **with an** edge weight **of** 1** and **node 2 **with an** edge weight **of** 6 **and similarly for other vertices.

---

**Example 1:**

```
Input:
V = 2
adj [] ={{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest
distance of node 0 is 0 and the shortest
distance from node 1 is 9.
```

<center>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700334/Web/Other/6a77963c-f9a6-4cf4-953c-19a2759a52a3_1685086564.png"/>
</center>

---

**Example 2:**

```
Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
```

<center>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700334/Web/Other/8c9ee3a2-a7d3-4028-ae22-a22ddb6ab7a3_1685086565.png"/>
</center>

---

```cpp
 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        vector<int> dist(V,1e9);
        dist[S]=0;
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            int node=temp.second;
            int dis=temp.first;
            for(auto it:adj[node]){
                int edge_weight=it[1];
                int next_node=it[0];
                if(dist[next_node]>edge_weight+dis){
                    dist[next_node]=edge_weight+dis;
                    pq.push({edge_weight+dis,next_node});
                }
            }
        }
        return dist;
    }
```

---

# Path with Maximum Probability

---


You are given an undirected weighted graph of `n` nodes (0-indexed), represented by an edge list where `edges[i] = [a, b]` is an undirected edge connecting the nodes `a` and `b` with a probability of success of traversing that edge `succProb[i]`.

Given two nodes `start` and `end`, find the path with the maximum probability of success to go from `start` to `end` and return its success probability.

If there is no path from `start` to `end`,  **return 0** . Your answer will be accepted if it differs from the correct answer by at most  **1e-5** .

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

<center>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700334/Web/Other/8c9ee3a2-a7d3-4028-ae22-a22ddb6ab7a3_1685086565.png"/>
</center>

---

Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

<center>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700334/Web/Other/8c9ee3a2-a7d3-4028-ae22-a22ddb6ab7a3_1685086565.png"/>
</center>

---

Example 3:
Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.

<center>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/700334/Web/Other/8c9ee3a2-a7d3-4028-ae22-a22ddb6ab7a3_1685086565.png"/>
</center>

---

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.

---
```cpp
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(n + 1);
    for (auto &it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]}); 
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto it = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();
        if (vis[node]) continue; 
        vis[node] = 1;
        for (auto &edge : adj[node]) {
            int adjNode = edge.first;
            int edW = edge.second;
            if (dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if (dist[n] == 1e9) return {-1}; 
    vector<int> path;
    int node = n;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1); 
    path.push_back(dist[n]); 
    reverse(path.begin(), path.end()); 
    return path;
}
```