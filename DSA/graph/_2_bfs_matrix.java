package graph;

import java.util.LinkedList;
import java.util.Queue;

public class _2_bfs_matrix {

    public static void main(String[] args) {
        int vertices = 5;
        int[][] adjacencyMatrix = {
                {0, 1, 1, 0, 0},
                {1, 0, 0, 1, 0},
                {1, 0, 0, 1, 0},
                {0, 1, 1, 0, 1},
                {0, 0, 0, 1, 0}
        };

        int m = adjacencyMatrix.length;
        int n = adjacencyMatrix[0].length;
        boolean[][] visited = new boolean[m][n];
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] == 1 && !visited[i][j]) {
                    bfs(adjacencyMatrix, visited, i, j);
                    count++;
                }
            }
        }

        System.out.println("Number of Islands: " + count);
    }

    public static void bfs(int[][] adjMatrix, boolean[][] visited, int row, int col) {
        int m = adjMatrix.length;
        int n = adjMatrix[0].length;
        int[] rowDirs = {-1, 0, 1, 0};
        int[] colDirs = {0, 1, 0, -1};

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{row, col});
        visited[row][col] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentRow = current[0];
            int currentCol = current[1];

            for (int d = 0; d < 4; d++) {
                int newRow = currentRow + rowDirs[d];
                int newCol = currentCol + colDirs[d];

                if (isValid(newRow, newCol, m, n) && adjMatrix[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                    queue.add(new int[]{newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
    }

    public static boolean isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
}
