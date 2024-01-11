package trees.java;

public class _1_intro {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(23);
        root.right = new TreeNode(34);
        // System.out.println(root.data + " " + root.left.data + " " + root.right.data);
        // System.out.println(8);
        root.left.left=new TreeNode(43);
    }
}
