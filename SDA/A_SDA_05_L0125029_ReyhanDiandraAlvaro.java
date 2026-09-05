
import java.util.ArrayList;

class Node {

    int data;
    ArrayList<Node> childrenNode = new ArrayList<>();

    Node(int data) {
        this.data = data;
    }

    public void insert(Node new_node) {
        childrenNode.add(new_node);
    }

    public void remove_with_index(int index) {
        if (index < 0 || index >= childrenNode.size()) {
            System.out.println("Child node dengan index " + index + " dari parent node '" + this.data + "' tidak ditemukan di dalam range index 0 - " + childrenNode.size());
            return;
        }

        childrenNode.remove(index);
        System.out.println("Child node dari parent node '" + this.data + "' dengan index " + index + " berhasil dihapus");
    }

    private void _traversal(Node node, int depth) {
        for (int i = 0; i < depth; i++) {
            System.out.print("---");
        }
        System.out.println("> " + node.data);

        for (Node child : node.childrenNode) {
            _traversal(child, depth + 1);
        }
    }

    public void traversal() {
        _traversal(this, 0);
    }

    private void _post_traversal(Node node, int depth) {
        for (Node child : node.childrenNode) {
            _post_traversal(child, depth + 1);
        }
        for (int i = 0; i < depth; i++) {
            System.out.print("---");
        }
        System.out.println("> " + node.data);
    }

    public void post_traversal() {
        _post_traversal(this, 0);
    }
}

public class A_SDA_05_L0125029_ReyhanDiandraAlvaro{

    public static void main(String[] args) {
        Node root = new Node(99);
        Node Node_1 = new Node(1);
        Node Node_2 = new Node(2);
        Node Node_3 = new Node(3);
        Node Node_4 = new Node(4);
        Node Node_5 = new Node(5);
        Node Node_6 = new Node(6);
        Node Node_7 = new Node(7);
        Node Node_8 = new Node(8);
        Node Node_9 = new Node(9);
        Node Node_10 = new Node(10);
        Node Node_11 = new Node(11);
        Node Node_12 = new Node(12);
        Node Node_13 = new Node(13);
        Node Node_14 = new Node(14);
        Node Node_15 = new Node(15);

        // nambahin node 1, 2, dan 3 sebagai child dari root (99)
        root.insert(Node_1); //index 0
        root.insert(Node_2); //index 1
        root.insert(Node_3); //index 2

        // nambahin node 4 dan 5 sebagai child dari node 1
        Node_1.insert(Node_4); //index 0 
        Node_1.insert(Node_5); //index 1

        // nambahin node 6 dan 7 sebagai child dari node 2
        Node_2.insert(Node_6); //index 0
        Node_2.insert(Node_7); //index 1

        // nambahin node 8, 9, dan 10 sebagai child dari node 3
        Node_3.insert(Node_8); //index 0
        Node_3.insert(Node_9); //index 1
        Node_3.insert(Node_10); //index 2

        // nambahin node 11 dan 12 sebagai child dari node 7
        Node_7.insert(Node_11); //index 0
        Node_7.insert(Node_12); //index 1

        // nambahin node 13 sebagai child dari node 9
        Node_9.insert(Node_13); //index 0

        // nambahin node 14 dan 15 sebagai child dari node 10
        Node_10.insert(Node_14); //index 0
        Node_10.insert(Node_15); //index 1

        // Menampilkan tree sebelum deletion
        root.traversal();

        System.out.println("");

        /*  Index child ikut urutan insert pada parent tiap parent punya daftar child sendiri
         Jadi root.insert(Node_1) = index 0, root.insert(Node_2) = index 1 meski di tengah sempat insert child node lain
        misal di tengah tengah root.insert node 1 dan 2 kita masukin node 1 insert itu tidak ngaruh di indeks
        selama tidak berhubungan
        */

        // hapus node 4 dari child node 1, karena node 4 berada pada index 0
        Node_1.remove_with_index(0);

        // hapus node 10 dari child node 3, karena node 10 berada pada index 2
        Node_3.remove_with_index(2);

        System.out.println("");

        // Menampilkan tree setelah deletion
        root.traversal();
    }
}
