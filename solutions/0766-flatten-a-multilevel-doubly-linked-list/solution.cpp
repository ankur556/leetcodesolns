/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // Helper: Collects Node pointers in the correct order (DFS)
    void helper(vector<Node*>& sol, Node* head) {
        if (!head) return;

        sol.push_back(head);
        
        // 1. Process Child first
        helper(sol, head->child);
        // 2. Process Next second
        helper(sol, head->next);
    }

    Node* flatten(Node* head) {
        if (!head) return nullptr;

        // Step 1: Linearize the nodes into a vector
        vector<Node*> sol;
        helper(sol, head); 

        // Step 2: Re-link the list using the vector order
        for(int i = 0; i < sol.size() - 1; i++) {
            Node* curr = sol[i];
            Node* nextNode = sol[i + 1];

            // Connect current to next
            curr->next = nextNode;
            curr->child = nullptr; // Important: Clear child pointer!
            
            // Connect next back to current
            nextNode->prev = curr;
        }

        // Ensure the last node is clean
        sol.back()->next = nullptr;
        sol.back()->child = nullptr;

        return sol[0];
    }
};
