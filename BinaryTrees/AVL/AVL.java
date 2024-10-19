public class AVL<T extends Comparable<T>> {

    private class Node {
        T data;
        int height;
        Node pred, left, right;

        Node(T x) {
            data = x;
            height = 0;
            left = right = pred = null;
        }
    }

    private Node root;

    private int height(Node root) {
        if (root == null) return -1;
        return root.height;
    }

    private Node rotateRight(Node root) {
        Node aux = root.left;
        aux.pred = root.pred;
        root.pred = aux;
        root.left = aux.right;
        if (aux.right != null) aux.right.pred = root;
        aux.right = root;
        root.height = 1 + Math.max(height(root.left), height(root.right));
        aux.height = 1 + Math.max(height(aux.left), height(aux.right));
        return aux;
    }

    private Node rotateLeft(Node root) {
        Node aux = root.right;
        aux.pred = root.pred;
        root.pred = aux;
        root.right = aux.left;
        if (aux.left != null) aux.left.pred = root;
        aux.left = root;
        root.height = 1 + Math.max(height(root.left), height(root.right));
        aux.height = 1 + Math.max(height(aux.left), height(aux.right));
        return aux;
    }

    private Node balance(Node root) {
        int balanceFactor = height(root.left) - height(root.right);
        if (balanceFactor > 1) {
            if (height(root.left.left) - height(root.left.right) >= 1) return rotateRight(root);
            root.left = rotateLeft(root.left);
            return rotateRight(root);
        }
        if (balanceFactor < -1) {
            if (height(root.right.left) - height(root.right.right) <= -1) return rotateLeft(root);
            root.right = rotateRight(root.right);
            return rotateLeft(root);
        }
        return root;
    }

    private Node insert(Node root, Node newN) {
        if (root == null) {
            newN.height = 0;
            return newN;
        }
        if (root.data.compareTo(newN.data) < 0) {
            root.right = insert(root.right, newN);
            root.right.pred = root;
        } else {
            root.left = insert(root.left, newN);
            root.left.pred = root;
        }
        root.height = 1 + Math.max(height(root.left), height(root.right));
        return balance(root);
    }

    private Node remove(Node root, Node elim) {
        if (root == null) return null;
        if (root.data.compareTo(elim.data) == 0) return root = remove(root);
        if (root.data.compareTo(elim.data) < 0) root.right = remove(root.right, elim);
        else root.left = remove(root.left, elim);
        root.height = 1 + Math.max(height(root.left), height(root.right));
        return balance(root);
    }

    private Node remove(Node root) {
        if (root.right == null && root.left == null) return null;
        if (root.right != null && root.left == null) {
            root.right.pred = root.pred;
            return root.right;
        }
        if (root.left != null && root.right == null) {
            root.left.pred = root.pred;
            return root.left;
        }
        Node temp = successor(root.left);
        root.data = temp.data;
        root.left = remove(root.left, temp);
        return balance(root);
    }

    private Node successor(Node root) {
        if (root.right == null) return root;
        return successor(root.right);
    }

    private boolean search(Node root, T x) {
        if (root == null) return false;
        if (root.data.compareTo(x) == 0) return true;
        if (root.data.compareTo(x) < 0) return search(root.right, x);
        return search(root.left, x);
    }

    private void display(Node root, String prefix, boolean isLeft) {
        if (root == null) return;
        System.out.print(prefix);
        System.out.print(isLeft ? "├──" : "└──");
        System.out.println(root.data);
        display(root.left, prefix + (isLeft ? "│   " : "     "), true);
        display(root.right, prefix + (isLeft ? "│   " : "     "), false);
    }

    public AVL() {
        root = null;
    }

    public void insert(T x) {
        root = insert(root, new Node(x));
    }

    public void remove(T x) {
        root = remove(root, new Node(x));
    }

    public boolean search(T x) {
        return search(root, x);
    }

    public void display() {
        display(root, "", true);
    }

}
