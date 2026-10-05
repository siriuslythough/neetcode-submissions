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
        unordered_map<int, Node*> cloned;
        queue<Node*> q;
        q.push(node);
        cloned[node->val] = new Node(node->val);
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            for(Node* nbd : curr->neighbors){
                if(!cloned.count(nbd->val)){ // haven't cloned this one (not visited)
                    cloned[nbd->val] = new Node(nbd->val);
                    q.push(nbd);
                } 
                cloned[curr->val]->neighbors.push_back(cloned[nbd->val]); 
            }
        }
        return cloned[node->val];
    }
};
