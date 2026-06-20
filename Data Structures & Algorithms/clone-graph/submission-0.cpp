/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> match;
        //Use BFS
        queue<Node*> q;
        q.push(node);


        while(!q.empty()){
            Node* removed = q.front();
            q.pop();
            if(match.contains(removed)) continue;
            Node* newNode = new Node(removed->val);
            match[removed] = newNode;
            for(Node* neigh: removed->neighbors){
                q.push(neigh);
            }
        }
        unordered_set<Node*> visited;
        q.push(node);
        while(!q.empty()){
            Node* removed = q.front();
            q.pop();
            if(visited.contains(removed)){
                continue;
            }
            visited.insert(removed);

            
            for(Node* neigh: removed->neighbors){
                match[removed]->neighbors.push_back(match[neigh]);
                q.push(neigh);
            }

            

        }

        return match[node];
        
    }
};
