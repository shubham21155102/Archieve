import java.util.ArrayList;

import trees.java.Lists;
public class Index {
    public int recursion(int m, int n, ArrayList<ArrayList<Integer>> list) {
        Lists lists = new Lists();
        
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;
        if (list.get(m).get(n) != -1)
            return list.get(m).get(n);
        int d = recursion(m - 1, n, list);
        int l = recursion(m, n - 1, list);
        list.get(m).set(n, d + l);
        return d + l;
    }
    public int uniquePaths(int m, int n) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                temp.add(-1);
            }
            list.add(temp);
        }
        return recursion(m - 1, n - 1, list);
    }
    public static void main(String[] args) {
         Index index = new Index();
        System.out.println(index.uniquePaths(3, 7));
    }
}
