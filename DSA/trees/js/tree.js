class TreeNode {
    constructor(data, left = null, right = null) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

var head = new TreeNode(12);
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

var x = new TreeNode(24);
var y = new TreeNode(25);

var path1 = [];
var path2 = [];

function findPath(root, path, k) {
    if (root === null) return false;
    path.push(root);
    if (root === k) return true;
    if (findPath(root.left, path, k) || findPath(root.right, path, k)) return true;
    path.pop();
    return false;
}

findPath(head, path1, x);
findPath(head, path2, y);

function findLCA(path1, path2, x, y) {
    var i = 0;
    while (i < path1.length && i < path2.length) {
        if (path1[i] !== path2[i]) break;
        i++;
    }
    return path1[i - 1];
}

var lca = findLCA(path1, path2, x, y);
console.log(lca);
