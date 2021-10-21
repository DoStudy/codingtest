import java.util.ArrayList;

public class Program {
    public static void main(String[] args) {

        /**
         * -> RootNode를 삭제할 수 없는 문제
         * [2][4][5][6][9]
         * ----------------
         * [2][4][6][9]
         * ----------------
         * [4][6][9]
         * ----------------
         * [6][9]
         * ----------------
         * [9]
         * ----------------
         * [9]
         */
        BinarySearchTree bst = new BinarySearchTree();

        bst.insert(5);
        bst.insert(4);
        bst.insert(6);
        bst.insert(2);
        bst.insert(9);

        ArrayList<TreeNode> treeNodes = bst.traverseInOrder();
        for (TreeNode treeNode : treeNodes) {
            System.out.print("[" + treeNode.getData() + "]");
        }
        System.out.println();

        System.out.println("----------------");

        TreeNode search5 = bst.search(5);
        assert (search5.getData() == 5);

        bst.delete(5);
        TreeNode search5Null = bst.search(5);
        assert (search5Null == null);

        ArrayList<TreeNode> treeNodesDelete5 = bst.traverseInOrder();
        for (TreeNode treeNode : treeNodesDelete5) {
            System.out.print("[" + treeNode.getData() + "]");
        }
        System.out.println();


        System.out.println("----------------");

        bst.delete(2);
        ArrayList<TreeNode> treeNodesDelete2 = bst.traverseInOrder();
        for (TreeNode treeNode : treeNodesDelete2) {
            System.out.print("[" + treeNode.getData() + "]");
        }
        System.out.println();

        System.out.println("----------------");

        bst.delete(4);
        ArrayList<TreeNode> treeNodesDelete4 = bst.traverseInOrder();
        for (TreeNode treeNode : treeNodesDelete4) {
            System.out.print("[" + treeNode.getData() + "]");
        }
        System.out.println();

        System.out.println("----------------");

        bst.delete(6);
        ArrayList<TreeNode> treeNodesDelete6 = bst.traverseInOrder();
        for (TreeNode treeNode : treeNodesDelete6) {
            System.out.print("[" + treeNode.getData() + "]");
        }
        System.out.println();

        System.out.println("----------------");

        bst.delete(9);
        ArrayList<TreeNode> treeNodesDelete9 = bst.traverseInOrder();
        for (TreeNode treeNode : treeNodesDelete9) {
            System.out.print("[" + treeNode.getData() + "]");
        }
        System.out.println();
    }
}
