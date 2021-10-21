import java.util.ArrayList;

public class BinarySearchTree {
    private TreeNode rootNode = null;

    public TreeNode getRootNode() {
        return rootNode;
    }

    public TreeNode insert(int data) {
        if (rootNode == null) {
            rootNode = TreeNode.insertNodeRecursive(null, null, data);
            return rootNode;
        }

        return TreeNode.insertNodeRecursive(rootNode, data);
    }

    public boolean delete(int data) {
        return TreeNode.deleteNodeRecursive(rootNode, data);
    }

    public ArrayList<TreeNode> traverseInOrder() {
        ArrayList<TreeNode> treeNodes = new ArrayList<>();
        TreeNode.traverseInOrder(rootNode, treeNodes);

        return treeNodes;
    }

    public TreeNode search(int data) {
        return TreeNode.getTreeNodeOrNull(rootNode, data);
    }
}
