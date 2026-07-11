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
    Node* cloneGraph(Node* node){
        if(!node) return nullptr; // base case, when the nput graph node is null

        unordered_map<Node*, Node*> cloned; // map to keep track of the original node -> cloned node

        queue<Node*> q; // BFS at-a-breadth element container
        q.push(node);

        cloned[node] = new Node(node->val);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for (Node* nbd : curr->neighbors){
                if(cloned.find(nbd) == cloned.end()){ // havent cloned this node yet
                    cloned[nbd] = new Node(nbd->val); // create a new clone
                    q.push(nbd); // add original node's neighbors
                }
                cloned[curr]->neighbors.push_back(cloned[nbd]); // connect cloned current node to cloned neighbour node
            }
        }
        return cloned[node];
    }
};
