#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


struct node{

    char data;
    unordered_map<char, node*> nxt;
    bool end;
    node(char d): data(d), end(false){}
    ~node(){}

};






class Trie{

    private:

        node * root;
        void display(node *, int);


    public:

        Trie(){root = new node('\0');}
        void insert(string);
        bool search(string);
        void mostrar(){return display(root, 0);}



        
};









void Trie::insert(string str){

    node * curr = root;
    for(int i = 0; i<str.size(); i++){

        char letter = str[i];
        if(!curr->nxt[letter]) curr->nxt[letter] = new node(letter);
        curr = curr->nxt[letter];

    }curr->end = true;

}







bool Trie::search(string s){

    node * curr = root;
    for(int i = 0; i<s.size(); i++){

        char letter = s[i];
        if(!curr->nxt[letter]) return false;
        curr = curr->nxt[letter];

    }return curr->end;


}





















void Trie::display(node* r, int niv) {

    if (r) {

        for (int i = 0; i < niv; i++) {
            cout << "  ";
        }
        if (r->data == '\0') {
            cout << "-->NULL" << endl;
        } else {
            cout << "-->" << r->data << endl;
        }

        for (int i = 0; i < 27; ++i) {
            display(r->nxt[i], niv + 1);
        }
    }
}

