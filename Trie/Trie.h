class Trie {
private:
    class Node {
    public:
        char data;
        unordered_map<char, Node*> children;
        bool isEndOfWord;

        Node(char d) : data(d), isEndOfWord(false) {}
        ~Node() {}
    };

    Node* root;

    Node* findNode(const string& str) {
        Node* currentNode = root;
        for (char letter : str) {
            if (!currentNode->children[letter]) {
                return nullptr;
            }
            currentNode = currentNode->children[letter];
        }
        return currentNode;
    }

    void display(Node* currentNode, int level) {
        if (currentNode) {
            for (int i = 0; i < level; ++i) {
                cout << "  ";
            }
            if (currentNode->data == '\0') {
                cout << "-->NULL" << endl;
            } else {
                cout << "-->" << currentNode->data << endl;
            }

            for (auto& child : currentNode->children) {
                display(child.second, level + 1);
            }
        }
    }

public:
    Trie() { root = new Node('\0'); }

    void insert(const string& word) {
        Node* currentNode = root;
        for (char letter : word) {
            if (!currentNode->children[letter]) {
                currentNode->children[letter] = new Node(letter);
            }
            currentNode = currentNode->children[letter];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(const string& word) {
        Node* currentNode = findNode(word);
        return currentNode != nullptr && currentNode->isEndOfWord;
    }

    void display() {
        display(root, 0);
    }
};
