#include <unordered_map>

using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int key;    // Changed from 'value' for clarity
    int val;    // Changed from 'count' for clarity

    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    void move_to_front(Node* node) {
        if (node == head)
            return;

        // Disconnect node from its current position
        remove1(node);

        // If the list became empty (shouldn't happen here, but safe to check)
        if (head == nullptr) {
            head = tail = node;
            node->next = node->prev = node;
            return;
        }

        // Re-insert at the front of the circular DLL
        node->next = head;
        node->prev = tail;
        head->prev = node;
        tail->next = node;

        head = node;
    }

    void add_front(int key, int val) {
        Node* temp = new Node(key, val);
        
        if (head == nullptr) {
            head = temp;
            tail = head;
            head->next = head;
            head->prev = head;
            return;
        }

        temp->next = head;
        temp->prev = tail;

        head->prev = temp;
        tail->next = temp;

        head = temp;
    }

    // Helper to disconnect a node without deleting it from memory
    void remove1(Node* node) {
        if (node == head && node == tail) {
            head = nullptr;
            tail = nullptr;
            return;
        }
        
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;

        if (node == head)
            head = next;

        if (node == tail)
            tail = prev;
    }

    // Removes the least recently used node (tail) and frees memory
    void remove_back() {
        if (head == nullptr) return; // Safety check

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node* temp = tail->prev;

        temp->next = head;
        head->prev = temp;

        delete tail;
        tail = temp;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int capacity;
    DLL dll;

    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        // Move the accessed node to the front (mark as recently used)
        dll.move_to_front(mp[key]);

        return mp[key]->val;
    }

    void put(int key, int value) {
        // Case 1: Key already exists. Update value and move to front.
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value; // Fixed: Now correctly updating the value
            dll.move_to_front(mp[key]);
            return;
        }

        // Case 2: Key does not exist. Check capacity.
        if (mp.size() >= capacity) {
            // Fixed: Erase using the key, not the value
            mp.erase(dll.tail->key);
            dll.remove_back();
        }

        // Add the new key-value pair
        dll.add_front(key, value);
        mp[key] = dll.head;
    }
};