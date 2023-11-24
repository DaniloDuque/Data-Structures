import java.util.List;
import java.util.ArrayList;

public class FenwickTree{


    private int size;

    private int Tree[];

    private int sum(int index){

        int s = 0;
        while(index > 0){

            s+=Tree[index];
            index -= (index&-index);  //this removes the less significant bit

        }return s;

    }


    //this method converts a vector to a FenwickTree
    private void build(){

        int par;
        for(int i = 1; i<size; ++i){

            par = i + (i&-i);  //this converts par in the next power of two
            if(par < size) Tree[par] += Tree[i];

        }


    }


    public FenwickTree(List<Integer> vector){

        size = vector.size()+1;

        Tree = new int[size];

        for(int i = 1; i<size; ++i) Tree[i] = vector.get(i-1);

        build();

    }


    public void add(int index, int x){

        while(index < size){   //this while updates the value at index, also updating the path

            Tree[index] += x;
            index += (index&-index);

        }

    }



    public int sum(int start, int finish){
        return sum(finish) - sum(start-1);
    }


    
}