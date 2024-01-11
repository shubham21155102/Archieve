package trees.java;

import java.util.LinkedList;
import java.util.Queue;

public class _2_traversals {
   public static void preOrder(TreeNode head) {
      if (head == null)
         return;
      System.out.print(head.data + " ");
      preOrder(head.left);
      preOrder(head.right);
   }

   public static void inOrder(TreeNode head) {
      if (head == null)
         return;
      inOrder(head.left);
      System.out.print(head.data + " ");
      inOrder(head.right);
   }

   public static void postOrder(TreeNode head) {
      if (head == null)
         return;
      postOrder(head.left);
      postOrder(head.right);
      System.out.print(head.data + " ");
   }

   public static int Height(TreeNode head) {
      if (head == null)
         return 0;
      return Math.max(Height(head.left), Height(head.right)) + 1;
   }

   public static void NodesAtKdist(TreeNode head, int k) {
      if (head == null)
         return;
      if (k == 0)
         System.out.print(head.data + " ");
      else {
         NodesAtKdist(head.left, k - 1);
         NodesAtKdist(head.right, k - 1);
      }
   }

   public static void levelOrderTraversal(TreeNode head) {
      if (head == null)
         return;
      Queue<TreeNode> q = new LinkedList<TreeNode>();
      q.add(head);
      while (!q.isEmpty()) {
         TreeNode temp = q.poll();
         System.out.print(temp.data + " ");
         if (temp.left != null)
            q.add(temp.left);
         if (temp.right != null)
            q.add(temp.right);
      }
   }

   public static void levelOrderTraversal2(TreeNode head) {
      if (head == null)
         return;
      Queue<TreeNode> q = new LinkedList<TreeNode>();
      q.add(head);
      while (!q.isEmpty()) {
         int size = q.size();
         for (int i = 0; i < size; i++) {
            TreeNode temp = q.poll();
            System.out.print(temp.data + " ");
            if (temp.left != null)
               q.add(temp.left);
            if (temp.right != null)
               q.add(temp.right);
         }
         System.out.println();
      }
   }

   public static void levelLineOrderTraversal(TreeNode head) {
      if (head == null)
         return;
      Queue<TreeNode> q = new LinkedList<TreeNode>();
      q.add(head);
      q.add(null);
      while (!q.isEmpty()) {
         TreeNode temp = q.poll();
         if (temp == null) {
            if (!q.isEmpty()) {
               q.add(null);
               System.out.println();
            }
            continue;
         }
         System.out.print(temp.data + " ");
         if (temp.left != null)
            q.add(temp.left);
         if (temp.right != null)
            q.add(temp.right);
      }
   }

   public static int getSize(TreeNode head) {
      if (head == null)
         return 0;
      return getSize(head.left) + getSize(head.right) + 1;
   }

   public static int getMaxNode(TreeNode head) {
      if (head == null)
         return Integer.MIN_VALUE;
      return Math.max(head.data, Math.max(getMaxNode(head.left), getMaxNode(head.right)));
   }

   public static void printLeftView(TreeNode head) {
      if (head == null)
         return;
      Queue<TreeNode> q = new LinkedList<TreeNode>();
      q.add(head);
      while (!q.isEmpty()) {
         int size = q.size();
         for (int i = 0; i < size; i++) {
            TreeNode temp = q.poll();
            if (i == 0)
               System.out.print(temp.data + " ");
            if (temp.left != null)
               q.add(temp.left);
            if (temp.right != null)
               q.add(temp.right);
         }
      }
   }

   public static void printLeftViewIterative(TreeNode head) {
      if (head == null)
         return;
      Queue<TreeNode> q = new LinkedList<TreeNode>();
      q.add(head);
      while (!q.isEmpty()) {
         int size = q.size();
         for (int i = 0; i < size; i++) {
            TreeNode temp = q.poll();
            if (i == 0)
               System.out.print(temp.data + " ");
            if (temp.left != null)
               q.add(temp.left);
            if (temp.right != null)
               q.add(temp.right);
         }
      }
   }

   public static void printLeftViewRecursive(TreeNode head) {
      if (head == null)
         return;
      System.out.print(head.data + " ");
      if (head.left != null)
         printLeftViewRecursive(head.left);
      else
         printLeftViewRecursive(head.right);
   }

   public static boolean isCSUM(TreeNode head) {
      if (head == null)
         return true;
      if (head.left == null && head.right == null)
         return true;
      int sum = 0;
      if (head.left != null)
         sum += head.left.data;
      if (head.right != null)
         sum += head.right.data;
      return (head.data == sum && isCSUM(head.left) && isCSUM(head.right));
   }

   // Binary Tree is balanced if left and right subtree are balanced and difference
   // between height of left and right subtree is not more than 1
   public static boolean isBalanced(TreeNode head) {
      if (head == null)
         return true;
      if (Math.abs(Height(head.left) - Height(head.right)) > 1)
         return false;
      return (isBalanced(head.left) && isBalanced(head.right));
   }

   public static int maxWidth(TreeNode head) {
      if (head == null)
         return 0;
      Queue<TreeNode> q = new LinkedList<TreeNode>();
      q.add(head);
      int max = 0;
      while (!q.isEmpty()) {
         int size = q.size();
         max = Math.max(max, size);
         for (int i = 0; i < size; i++) {
            TreeNode temp = q.poll();
            if (temp.left != null)
               q.add(temp.left);
            if (temp.right != null)
               q.add(temp.right);
         }
      }
      return max;
   }

   public static void main(String[] args) {
      TreeNode head = new TreeNode(12);
      head.left = new TreeNode(13);
      head.right = new TreeNode(15);
      head.left.left = new TreeNode(14);
      head.left.right = new TreeNode(16);
      head.right.left = new TreeNode(17);
      head.right.right = new TreeNode(18);
      head.left.left.left = new TreeNode(19);
      head.left.left.right = new TreeNode(20);
      head.left.right.left = new TreeNode(21);
      head.left.right.right = new TreeNode(22);
      head.right.left.left = new TreeNode(23);
      head.right.left.right = new TreeNode(24);
      head.right.right.left = new TreeNode(25);
      head.right.right.right = new TreeNode(26);
      TreeNode temp1 = head;
      preOrder(temp1);
      System.out.println();
      TreeNode temp2 = head;
      inOrder(temp2);
      System.out.println();
      TreeNode temp3 = head;
      postOrder(temp3);
      System.out.println();
      TreeNode temp4 = head;
      System.out.println("Height of tree= " + Height(temp4));
      TreeNode temp5 = head;
      NodesAtKdist(temp5, 2);
      System.out.println();
      TreeNode temp6 = head;
      levelOrderTraversal(temp6);
      System.out.println();
      TreeNode temp7 = head;
      levelLineOrderTraversal(temp7);
      System.out.println();
      TreeNode temp8 = head;
      levelOrderTraversal2(temp8);
      System.out.println();
      TreeNode temp9 = head;
      System.out.println("Size of tree= " + getSize(temp9));
      TreeNode temp10 = head;
      System.out.println("Max node of tree= " + getMaxNode(temp10));
      TreeNode temp11 = head;
      printLeftView(temp11);
      System.out.println();
      TreeNode temp12 = head;
      printLeftViewIterative(temp12);
      System.out.println();
      TreeNode temp13 = head;
      printLeftViewRecursive(temp13);

   }
}