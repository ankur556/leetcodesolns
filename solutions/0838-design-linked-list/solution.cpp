class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int val) : val(val), next(nullptr) {}
        Node(int val, Node* next) : val(val), next(next) {}
    };

    Node *front, *tail;
    int size;

    Node* getNodeAt(int index) {
        Node* tmp = front;
        for (int i=0; i<index; i++) tmp = tmp->next;
        return tmp;
    }

public:
    MyLinkedList() : size(0) {
        front = nullptr;
        tail = nullptr;
    }
    ~MyLinkedList() {
        Node* curr = front;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
    
    int get(int index) {
        if (index>=0 && index<size) {
            Node* tmp = getNodeAt(index);
            return tmp->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val, front);
        front = newNode;
        if (!tail) tail = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            front = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) addAtHead(val);
        else if (index == size) addAtTail(val);
        else if (index>=0 and index<size) {
            Node* tmp = getNodeAt(index-1);
            Node* newNode = new Node(val, tmp->next);
            tmp->next = newNode;
            if (tmp == tail) tail = tmp->next;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0) {
            if (front) {
                Node* tmp = front;
                front = front->next;
                if (!front) tail = front;
                if (tail == tmp) tail = nullptr;
                delete tmp;
                size--;
            }
        }
        else if (index>=0 and index<size) {
            Node* prev = getNodeAt(index-1);
            // prev->next is guaranteed to be not null since prev can never be last
            Node* delNode = prev->next;
            prev->next = delNode->next;
            if (delNode == tail) tail = prev;
            if (front == delNode) front = nullptr;
            delete delNode;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
