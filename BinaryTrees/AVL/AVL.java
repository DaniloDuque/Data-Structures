public class AVL {

    private class node {
        int data;
        int height;
        node pred, left, right;
        node(int x) {
            data = x;
            height = 0;
            left = right = pred = null;
        }
    }
    
    private node root;
    
    private int height(node root) {
        if (root == null) return -1;
        return root.height;
    }
    
    private node rotateRight(node root) {
        node aux = root.left;
        aux.pred = root.pred;
        root.pred = aux;
        root.left = aux.right;
        if (aux.right != null) aux.right.pred = root;
        aux.right = root;
        // Update the height of the affected nodes
        root.height = 1 + Math.max(height(root.left), height(root.right));
        aux.height = 1 + Math.max(height(aux.left), height(aux.right));
        return aux;
    }

    private node rotateLeft(node root) {
        node aux = root.right;
        aux.pred = root.pred;
        root.pred = aux;
        root.right = aux.left;
        if (aux.left != null) aux.left.pred = root;
        aux.left = root;
        // Update the height of the affected nodes
        root.height = 1 + Math.max(height(root.left), height(root.right));
        aux.height = 1 + Math.max(height(aux.left), height(aux.right));
        return aux;
    }

    private node balance(node root) {
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

    private node insert(node root, node newN) {
        if (root == null) {
            newN.height = 0;
            return newN;
        }
        if (root.data < newN.data) {
            root.right = insert(root.right, newN);
            root.right.pred = root;
        } else {
            root.left = insert(root.left, newN);
            root.left.pred = root;
        }
        root.height = 1 + Math.max(height(root.left), height(root.right));
        return balance(root);
    }

    private node remove(node root, node elim) {
        if (root == null) return null;
        if (root.data == elim.data) return root = remove(root);
        if (root.data < elim.data) root.right = remove(root.right, elim);
        else root.left = remove(root.left, elim);
        root.height = 1 + Math.max(height(root.left), height(root.right));
        return balance(root);
    }

    private node remove(node root) {
        if (root.right == null && root.left == null) return null;
        if (root.right != null && root.left == null) {
            root.right.pred = root.pred;
            return root.right;
        }
        if (root.left != null && root.right == null) {
            root.left.pred = root.pred;
            return root.left;
        }
        node temp = successor(root.left);
        root.data = temp.data;
        root.left = remove(root.left, temp);
        return balance(root);
    }

    private node successor(node root) {
        if (root.right == null) return root;
        return successor(root.right);
    }

    private boolean search(node root, int x) {
        if (root == null) return false;
        if (root.data == x) return true;
        if (root.data < x) return search(root.right, x);
        return search(root.left, x);
    }

    private void display(node root, String prefix, boolean isLeft) {
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

    public void insert(int x) {
        root = insert(root, new node(x));
    }

    public void remove(int x) {
        root = remove(root, new node(x));
    }

    public boolean search(int x) {
        return search(root, x);
    }

    public void display() {
        display(root, "", true);
    }

}
