package graph;

public class _4_dfs_matrix {
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
            if (!visited[i][i]) {
                dfs(adjacencyMatrix, visited, i, i);
                count++;
            }
        }

        System.out.println("Number of Islands: " + count);
    }
    public static void dfs(int[][] adjMatrix, boolean[][] visited, int row, int col) {
        int m = adjMatrix.length;
        int n = adjMatrix[0].length;
        int[] rowDirs = {-1, 0, 1, 0};
        int[] colDirs = {0, 1, 0, -1};

        visited[row][col] = true;

        for (int d = 0; d < 4; d++) {
            int newRow = row + rowDirs[d];
            int newCol = col + colDirs[d];

            if (isValid(newRow, newCol, m, n) && adjMatrix[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                dfs(adjMatrix, visited, newRow, newCol);
            }
        }
    }
    public static boolean isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
}
