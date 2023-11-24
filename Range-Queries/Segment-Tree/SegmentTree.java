import java.util.List;
import java.util.ArrayList;


public class SegmentTree{


    private int Tree[];

    private int size;

    public SegmentTree(List<Integer> vector){

        size = vector.size();
        Tree = new int[size<<1]; //for a segment tree we need 2n-1 size array, n being the size of vector

        for(int i = size; i<size<<1; ++i) Tree[i] = vector.get(i-size);    //We set the leaves of the segment tree, to be the values of the initial vector

        for(int i = size-1; i>0; --i)  Tree[i] = Math.max(Tree[i<<1], Tree[(i<<1)+1]);  // makes the predecessor of Tree[2i] and Tree[2i+1] = maximum between both

    }



    public void update(int index, int x){

        index += size;
        Tree[index] = x;

        while(index > 0){

            index >>= 1;

            int newV = Math.max(Tree[index<<1], Tree[(index<<1) + 1]);

            if(Tree[index] == newV) return; ///if the value updated, is not global max, then it reaches a point, where no more change needs to be made

            Tree[index] = newV;

        }
        

    }



    public int max(int start, int finish){

        int max = -(1<<30);
        start += size;
        finish += size;

        while (start < finish) {

        if (start%2 == 1) {
            max = Math.max(max, Tree[start]);
            start++;
        }
        if (finish%2 == 1) {
            finish--;
            max = Math.max(max, Tree[finish]);
        }
        start >>= 1;
        finish >>= 1;
        
        }return max;


    }





}