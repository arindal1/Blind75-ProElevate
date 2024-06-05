class Solution {
private:
    unordered_map<Node*, Node*>seen;
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        
        if(seen.find(node) != seen.end()) {
            return seen[node];
        }
        Node* newNode = new Node(node->val, {});
        seen[node] = newNode;
        for(auto neighbor: node->neighbors){
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return newNode;
    }
};