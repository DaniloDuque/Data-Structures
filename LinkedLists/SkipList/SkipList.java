import java.util.Random;




public class SkipList {



    private class node {

        int data, level;  //data->value stored in node      level->the maximum level that the node reached
        node[] next;     //each node contains a array, next[0] means the node that is to the right, and node [i>0] means all the node that are down fo the current node

        node(int value, int level) {

            data = value;
            next = new node[level + 1]; //the size of the array, is the height of the node in the skip list

        }
    }


    //atributes
    private static final int MAX_LEVEL = 32;
    private node head;
    private int level;
    private Random random;




    // Constructor
    public SkipList() {

        head = new node(Integer.MIN_VALUE, MAX_LEVEL); //the head contains the minimum value possible, and is also the tallest node
        level = 0;    //this means that for the moment there is no express lane
        this.random = new Random();

    }


    //this private method returns the number of levels a new element will go up in the list
    private int getNewLevel(){

        int newLevel = 0;
        while (random.nextBoolean() && newLevel < MAX_LEVEL) newLevel++;
        return newLevel;

    }






    public void insert(int x){

        int newLevel = getNewLevel();

        node newN = new node(x, newLevel);

        node curr = head;

        for(int i = newLevel; i>=0; --i){

            while(curr.next[i] != null && curr.next[i].data < x) curr = curr.next[i]; //if the right node is less than current, then current becomes the right node

            newN.next[i] = curr.next[i];    //insert newN between curr and curr.next
            curr.next[i] = newN;

            
            
        }if (newLevel > level) level = newLevel; //if the new level is greater than level, then level becomes newLevel
    

    }






    public void remove(int x){

        node curr = head;

        for(int i = level; i>=0; --i){

            while(curr.next[i] != null && curr.next[i].data < x) curr = curr.next[i];   //if the right node is less than current, then current becomes the right node

            if(curr.next[i] != null && curr.next[i].data == x) curr.next[i] = curr.next[i].next[i]; //if we reached a node where data == x, then remove it

        }while(level > 0 && head.next[level] == null) --level; //this updates the atribute level, in case it was changed by removing a node

    }







    public boolean search(int x){

        node curr = head;

        for(int i = level; i>=0; --i){

            while(curr.next[i] != null && curr.next[i].data < x) curr = curr.next[i];

            if(curr.next[i] != null && curr.next[i].data == x) return true;

        }return false;

    }




    

    

    public void display() {
        
        System.out.println("Skip List:");

        for (int i = level; i >= 0; i--) {

            node current = head;

            System.out.print("level " + i + ": ");

            while (current.next[i] != null) {
                System.out.print(current.next[i].data + " -> ");
                current = current.next[i];
            }
            System.out.println();
        }
        System.out.println();

    }

    




}
