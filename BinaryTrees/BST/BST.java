public class BST<T extends Comparable<T>> {

    private class node {
        T data;
        node left, right;
        node(T x) {
            data = x;
            left = right = null;
        }
    }

    private node root;

    private node insert(node root, node newN) {
        if (root == null) return newN;
        if (root.data.compareTo(newN.data) < 0) root.right = insert(root.right, newN);
        else root.left = insert(root.left, newN);
        return root;
    }

    private T getMinValue(node root) {
        if (root.left == null) return root.data;
        return getMinValue(root.left);
    }

    private node remove(node root, T x) {
        if (root == null) return null;
        if (root.data.compareTo(x) == 0) {
            if (root.right != null && root.left != null) {
                T min = getMinValue(root.right);
                root.data = min;
                root.right = remove(root.right, min);
            } else {
                return (root.right != null) ? root.right : root.left;
            }
        } else if (root.data.compareTo(x) < 0) {
            root.right = remove(root.right, x);
        } else {
            root.left = remove(root.left, x);
        }
        return root;
    }

    private boolean search(node root, T x) {
        if (root == null) return false;
        if (root.data.compareTo(x) == 0) return true;
        if (root.data.compareTo(x) < 0) return search(root.right, x);
        return search(root.left, x);
    }

    private void display(node root, String prefix, boolean isLeft) {
        if (root == null) return;
        System.out.print(prefix);
        System.out.print((isLeft ? "|---" : "---"));
        System.out.println(root.data);
        display(root.right, prefix + (isLeft ? "|    " : "     "), true);
        display(root.left, prefix + (isLeft ? "|    " : "     "), false);
    }

    public BST() {
        root = null;
    }

    public void insert(T x) {
        root = insert(root, new node(x));
    }

    public void remove(T x) {
        root = remove(root, x);
    }

    public boolean search(T x) {
        return search(root, x);
    }

    public void display() {
        display(root, "", true);
    }
}
