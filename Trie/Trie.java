import java.util.HashMap;


public class Trie{


    private class node{
        
        char data;
        boolean isEnd;
        HashMap<Character,node> children;

        node(char data){
            this.data = data;
            this.isEnd = false;
            this.children = new HashMap<>();
        }

    }

    private node root;

    public Trie(){
            
        this.root = new node('\0');

    }


    public void insert(String word){

        node curr = root;

        for(int i = 0; i<word.length(); i++){

            char ch = word.charAt(i);

            if(!curr.children.containsKey(ch))
                
                curr.children.put(ch,new node(ch));

            curr = curr.children.get(ch);
            
        }curr.isEnd = true;

    }



    public boolean search(String word){

        node curr = root;

        for(int i = 0; i<word.length(); i++){

            char ch = word.charAt(i);

            if(!curr.children.containsKey(ch))
                
                return false;

            curr = curr.children.get(ch);
            
        }return curr.isEnd;

    }



}

