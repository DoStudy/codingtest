import java.util.ArrayList;
import java.util.LinkedList;

public class TreeNode {
    private int data;
    private TreeNode left;
    private TreeNode right;
    private TreeNode parent;

    public TreeNode(int data) {
        this.data = data;
    }

    public TreeNode(int data, TreeNode parent) {
        this.data = data;
        this.parent = parent;
    }

    public int getData() {
        return data;
    }

    public TreeNode getLeft() {
        return left;
    }

    public TreeNode getRight() {
        return right;
    }

    public static TreeNode getTreeNodeOrNull(TreeNode node, int targetData) {
        if (node == null) {
            return null;
        }

        if (node.data == targetData) {
            return node;
        }

        if (targetData < node.data) {
            return getTreeNodeOrNull(node.left, targetData);
        }

        return getTreeNodeOrNull(node.right, targetData);
    }

    public static TreeNode insertNodeRecursive(TreeNode node, int targetData) {
        if (node == null) {
            return new TreeNode(targetData);
        }

        if (targetData < node.data) {
            node.left = insertNodeRecursive(node.left, node, targetData);
        } else {
            node.right = insertNodeRecursive(node.right, node, targetData);
        }

        return node;
    }

    public static TreeNode insertNodeRecursive(TreeNode node, TreeNode parent, int targetData) {
        if (node == null) {
            return new TreeNode(targetData, parent);
        }

        if (targetData < node.data) {
            node.left = insertNodeRecursive(node.left, node, targetData);
        } else {
            node.right = insertNodeRecursive(node.right, node, targetData);
        }

        return node;
    }

    public static boolean deleteNodeRecursive(TreeNode node, int targetData) {
        if (node == null) {
            return false;
        }
        // 1. 지울 플레이어를 갖고 있는 노드를 찾음
        TreeNode treeNodeOrNull = getTreeNodeOrNull(node, targetData);
        if (treeNodeOrNull == null) {
            return false;
        }

        // 2. 자식이 있는지에 따라 경우의 수를 나눔 -> successor나 predecessor를 찾음
        if (treeNodeOrNull.left == null && treeNodeOrNull.right == null) { // 리프노드
            TreeNode parent = treeNodeOrNull.parent;

            if (parent != null) {
                if (parent.left == treeNodeOrNull) {
                    parent.left = null;
                } else {
                    parent.right = null;
                }
            }

            return true;
        } else if (treeNodeOrNull.left != null && treeNodeOrNull.right != null) { // 자식이 두개인 경우
            TreeNode successor = findSuccessorRecursive(treeNodeOrNull.right);
            treeNodeOrNull.data = successor.data;

            return deleteNodeRecursive(successor, successor.data);
        } else { // 자식이 하나인 경우
            TreeNode parent = treeNodeOrNull.parent;
            TreeNode child;

            if (parent != null) {
                child = treeNodeOrNull.left != null ? treeNodeOrNull.left : treeNodeOrNull.right;
                child.parent = treeNodeOrNull.parent;

                if (parent.left == treeNodeOrNull) {
                    parent.left = child;
                } else {
                    parent.right = child;
                }
            } else {
                TreeNode nextNode = treeNodeOrNull.left != null ? treeNodeOrNull.left : treeNodeOrNull.right;
                node.data = nextNode.data;
                node.left = nextNode.left;
                node.right = nextNode.right;
            }

            return true;
        }
    }

    public static TreeNode findSuccessorRecursive(TreeNode node) {
        if (node == null) {
            return null;
        }

        if (node.left == null) {
            return node;
        }

        return findSuccessorRecursive(node.left);
    }

    public static void traverseInOrder(TreeNode node, ArrayList<TreeNode> inorderList) {
        if (node == null) {
            return;
        }

        traverseInOrder(node.left, inorderList);
        inorderList.add(node);
        traverseInOrder(node.right, inorderList);
    }

    @Override
    public String toString() {
        return "{" +
                "data=" + data +
                '}';
    }
}
