public class BST{

    private class node{

        int data;
        node left, right;
        node(int x){

            data = x;
            left = right = null;
            
        }

    }

    private node root;

    private node insert(node root, node newN){

        if(root == null) return newN;

        if(root.data < newN.data) root.right = insert(root.right, newN);

        else root.left = insert(root.left, newN);

        return root;

    }


    private int getMinValue(node root){

        if(root.left == null) return root.data;   
        return getMinValue(root.left);

    }


    private node remove(node root, int x){

        if(root == null) return null;    //if the node we are searching doesnt exist, do not remove anything

        if(root.data == x){

            if(root.right != null && root.left != null){  //this is the case root has 2 child

                int min = getMinValue(root.right);
                root.data = min;
                root.right = remove(root.right, min);

            }else{                       //this is the case that root has 1 or 0 child

                return (root.right != null)? root.right: root.left;   //returns the child of root that exists

            }

        }else if(root.data < x) root.right = remove(root.right, x);

        else root.left = remove(root.left, x);

        return root;

    }


    private boolean search(node root, int x){

        if(root == null) return false;

        if(root.data == x) return true;

        if(root.data < x) return search(root.right, x);

        return search(root.left, x);

    }


    private void display(node root, String prefix, boolean isLeft){

        if (root == null) return;
        System.out.print(prefix);
        System.out.print((isLeft ? "|---" : "---"));
        System.out.println(root.data);
        display(root.right, prefix + (isLeft ? "|    " : "     "), true);
        display(root.left, prefix + (isLeft ? "|    " : "     "), false);

    }




    //public methods call recursive private methods for simplicity

    public BST(){
        root = null;
    }

    public void insert(int x){root = insert(root, new node(x));}

    public void remove(int x){root = remove(root, x);}

    public boolean search(int x){ return search(root, x);}

    public void display(){display(root, "", true);}



}