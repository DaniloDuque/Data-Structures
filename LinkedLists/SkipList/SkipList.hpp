#include <iostream>
#include <cstdlib>  // For malloc and rand

struct node {

    int data, height;
    node **next;

    node(int x, int level) {
        data = x;
        height = level;
        next = (node **)malloc((level + 1) * sizeof(node *));
    }

    ~node() {
        free(next);
    }
};

class SkipList {

    private:

        node *head;
        int level;
        const int MAX_LEVEL = 32;

    public:


        SkipList() {
            head = new node(-(1<<30), MAX_LEVEL);
            level = 0;
        }


        int getNewLevel() {

            int newLevel = 0;
            while (rand()&1 && newLevel < MAX_LEVEL) newLevel++;
            return newLevel;

        }



        void insert(int x) {

            int newLevel = getNewLevel();
            node *newNode = new node(x, newLevel);
            node *curr = head;

            for (int i = newLevel; i >= 0; --i) {

                while (curr->next[i] != nullptr && curr->next[i]->data < x) curr = curr->next[i];
                
                newNode->next[i] = curr->next[i];
                curr->next[i] = newNode;

            }if (newLevel > level) level = newLevel;
            
        }



        void remove(int x) {

            node *curr = head;

            for (int i = level; i >= 0; --i) {

                while (curr->next[i] != nullptr && curr->next[i]->data < x) curr = curr->next[i];

                if (curr->next[i] != nullptr && curr->next[i]->data == x) {
                    node *temp = curr->next[i];
                    curr->next[i] = temp->next[i];
                    delete temp;
                }
            }while (level > 0 && head->next[level] == nullptr) --level;
            
        }






        bool search(int x) {

            node *curr = head;

            for (int i = level; i >= 0; --i) {

                while (curr->next[i] != nullptr && curr->next[i]->data < x) curr = curr->next[i];
                
                if(curr->next[i] != nullptr && curr->next[i]->data == x) return true;
                
            }return false;
        }






        void display() {

            std::cout << "Skip List:\n";

            for (int i = level; i >= 0; i--) {
                node *current = head;
                std::cout << "level " << i << ": ";
                while (current->next[i] != nullptr) {
                    std::cout << current->next[i]->data << " -> ";
                    current = current->next[i];
                }std::cout << "\n";
            }std::cout << "\n";
        }




};




