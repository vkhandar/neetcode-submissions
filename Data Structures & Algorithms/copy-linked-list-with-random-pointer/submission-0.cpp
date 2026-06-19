/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:


    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* curr = head;
        while(curr!=nullptr){
            
            Node* copyNode = new Node(curr->val);
            copyNode->next = curr->next;
            curr->next = copyNode;
            curr = copyNode->next;
        }

        
        
        
        curr = head;
        while(curr!=nullptr){
            Node* copyNode = curr->next;
            if(curr->random == nullptr){
                copyNode->random = nullptr;
            } else {
                copyNode->random = curr->random->next;
            }

            curr = curr->next->next;
            
            
        }
        Node* newhead = head->next;
        curr = head;
        while(curr!=nullptr){
            Node* copyNode = curr->next;
            Node* nextOG = copyNode->next;
            curr->next = nextOG;
            if (nextOG != nullptr) {
                copyNode->next = nextOG->next;
            } else {
                copyNode->next = nullptr;
            }
            curr = nextOG;

        }

        return newhead;

        
    }
};
