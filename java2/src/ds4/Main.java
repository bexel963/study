package ds4;

public class Main {
    public static void main(String[] args) {
        MiniTree tree = new MiniTree();

        tree.addNode(10);
        tree.addNode(7);
        tree.addNode(15);
        tree.addNode(6);
        tree.addNode(8);
        tree.addNode(13);
        tree.addNode(18);
        tree.addNode(11);
        tree.addNode(14);
        tree.addNode(16);
        tree.addNode(19);
        tree.addNode(17);

        System.out.println(tree.getNode(15).data);

        System.out.println(tree.removeNode(15));

        MiniTree.Node root = tree.new Node();

        root = tree.getNode(10);
        System.out.print(root.data + " -> ");               // 10
        System.out.print(root.right.data + " -> ");         // 16
        System.out.print(root.right.left.data + " -> ");    // 13
        System.out.print(root.right.right.data + " -> ");    // 18
        System.out.print(root.right.right.left.data + " -> ");    // 17
        System.out.print(root.right.right.right.data + " -> ");    // 19
        System.out.println();


    }
}
