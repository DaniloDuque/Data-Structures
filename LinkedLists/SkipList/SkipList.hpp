template<typename T>
class SkipList {

    struct Node {
        T data;
        int height;
        Node **next;

        Node(T x, int level) {
            data = x;
            height = level;
            next = new Node*[level + 1](); 
        }

        ~Node() {
            delete[] next; 
        }
    };

    private:
        Node *head;
        int level;
        const int MAX_LEVEL = 32;

    public:
        SkipList() {
            head = new Node(static_cast<T>(-(1 << 30)), MAX_LEVEL);  
            level = 0;
        }

        ~SkipList() {
            Node *current = head;
            while (current) {
                Node *temp = current;
                current = current->next[0];
                delete temp;
            }
        }

        int getNewLevel() {
            int newLevel = 0;
            while (rand() & 1 && newLevel < MAX_LEVEL) newLevel++;
            return newLevel;
        }

        void insert(T x) {
            int newLevel = getNewLevel();
            Node *newNode = new Node(x, newLevel);
            Node *curr = head;

            for (int i = newLevel; i >= 0; --i) {
                while (curr->next[i] != nullptr && curr->next[i]->data < x)
                    curr = curr->next[i];
                
                newNode->next[i] = curr->next[i];
                curr->next[i] = newNode;
            }
            if (newLevel > level) level = newLevel;
        }

        void remove(T x) {
            Node *curr = head;

            for (int i = level; i >= 0; --i) {
                while (curr->next[i] != nullptr && curr->next[i]->data < x)
                    curr = curr->next[i];

                if (curr->next[i] != nullptr && curr->next[i]->data == x) {
                    Node *temp = curr->next[i];
                    curr->next[i] = temp->next[i];
                    delete temp;
                }
            }
            while (level > 0 && head->next[level] == nullptr) --level;
        }

        bool search(T x) {
            Node *curr = head;

            for (int i = level; i >= 0; --i) {
                while (curr->next[i] != nullptr && curr->next[i]->data < x)
                    curr = curr->next[i];
                
                if (curr->next[i] != nullptr && curr->next[i]->data == x)
                    return true;
            }
            return false;
        }

        void display() {
            std::cout << "Skip List:\n";
            for (int i = level; i >= 0; i--) {
                Node *current = head;
                std::cout << "level " << i << ": ";
                while (current->next[i] != nullptr) {
                    std::cout << current->next[i]->data << " -> ";
                    current = current->next[i];
                }
                std::cout << "NULL\n";
            }
            std::cout << "\n";
        }
};
