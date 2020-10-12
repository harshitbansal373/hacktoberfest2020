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
        if(node){
            queue<Node*> q,q1;
            q.push(node);
            Node* node1 = new Node(node->val);
            q1.push(node1);
            map<int, Node*> m;
            m[node->val]=node1;
            while(!q.empty()){
                Node* t = q.front();
                q.pop();
                Node* t1 = q1.front();
                q1.pop();
                for(auto i:t->neighbors){
                    if(m[i->val]==0){
                        Node* temp = new Node(i->val);
                        t1->neighbors.push_back(temp);
                        q1.push(temp);
                        q.push(i);
                        m[i->val]=temp;
                    } else{
                        t1->neighbors.push_back(m[i->val]);
                    }
                }
            }
            return node1;
        }
        return nullptr;
    }
};
