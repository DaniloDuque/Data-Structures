#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

struct node {
    int data;
    node* next;
    node(int x) : data(x), next(nullptr) {}
    ~node() {}
};

class SingleLinkedList {
    private:
        node* head;
        void freeList();
        void appendnode(node*);
    public:
        SingleLinkedList() : head(nullptr) {}
        ~SingleLinkedList() {}
        void append(int);
        void insert(int, int);
        void push(int);
        void display();
        void shuffle();
        void sort(int);
        int remove(int);
        int size();
        node* getFirst();
};

void SingleLinkedList::freeList() {
    if (!head) return;
    node* current = head->next;
    while (current) {
        node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr; // Important: mark the head as NULL after freeing the nodes
}

//if asc != 0, sort in ascending order, else descending order
void SingleLinkedList::sort(int asc) {
    if (!head) return;
    SingleLinkedList less, greater;
    int x = head->data;
    for (node* current = head->next; current; current = current->next)
        (current->data < x) ? less.append(current->data) : greater.append(current->data);
    if (asc) {
        less.sort(asc);
        less.append(x);
        greater.sort(asc);
        less.appendnode(greater.getFirst());
        head = less.getFirst();
        return;
    }
    greater.sort(asc);
    greater.append(x);
    less.sort(asc);
    greater.appendnode(less.getFirst());
    head = greater.getFirst();
    return;
}

void SingleLinkedList::appendnode(node* newnode) {
    if (!head) {
        head = newnode;
        return;
    }
    node* current = head;
    while (current->next) current = current->next;
    current->next = newnode;
    newnode->next = nullptr;
}

node* SingleLinkedList::getFirst() {
    return head;
}

void SingleLinkedList::shuffle() {

    int count = size();
    node* current;
    std::uniform_int_distribution<int> dis(0, count);
    int times = dis(gen);
    times *= 20;
    for (int i = 0; i < times; i++) {
        current = head;
        int randomNumber = dis(gen);
        for (int j = randomNumber; j > 0; j--) {
            if (!current->next) {
                head->data ^= current->data;
                current->data ^= head->data;
                head->data ^= current->data;
            } else {
                current->data ^= current->next->data;
                current->next->data ^= current->data;
                current->data ^= current->next->data;
            }
            current = current->next;
        }
    }
}

int SingleLinkedList::remove(int index) {
    int value;
    node* toRemove, *current = head;
    if (!index) {
        value = current->data;
        toRemove = current;
        head = current->next;
        delete toRemove;
        return value;
    }
    for (index; index > 1; index--) {
        if (!current->next) {
            return -1;
        }
        current = current->next;
    }
    toRemove = current->next;
    if (!toRemove) {
        return -1;
    }
    value = toRemove->data;
    current->next = current->next->next;
    delete toRemove;
    return value;
}

void SingleLinkedList::push(int value) {
    node* newnode = new node(value);
    newnode->next = head;
    head = newnode;
}

void SingleLinkedList::insert(int index, int value) {
    if (!index) return push(value);
    node* newnode = new node(value);
    node* current = head;
    for (index; index > 1; index--) {
        if (!current->next) {
            current->next = newnode;
            return;
        }
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
}

int SingleLinkedList::size() {
    int count = 0;
    node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void SingleLinkedList::append(int value) {
    node* newnode = new node(value);
    if (!head) {
        head = newnode;
        return;
    }
    node* current = head;
    while (current->next) current = current->next;
    current->next = newnode;
    newnode->next = nullptr;
}

void SingleLinkedList::display() {
    if (!head) return;
    node* current = head;
    for (current; current->next; current = current->next) std::cout << current->data << " ";
    std::cout << current->data << std::endl;
}
