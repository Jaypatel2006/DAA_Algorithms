#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int freq;
    Node* left;
    Node* right;
    Node(int f) {
        freq = f;
        left = right = nullptr;
    }
};

class Huffman {
public:
    class cmp {
    public:
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };

    Node* buildTree(vector<int>& freq) {
        priority_queue<Node*, vector<Node*>, cmp> pq;
        for(int f : freq) pq.push(new Node(f));
        while(pq.size() > 1) {
            Node* l = pq.top(); pq.pop();
            Node* r = pq.top(); pq.pop();
            Node* node = new Node(l->freq + r->freq);
            node->left = l;
            node->right = r;
            pq.push(node);
        }
        return pq.top();
    }

    int calculateCost(Node* root, int depth = 0) {
        if(!root->left && !root->right) return root->freq * depth;
        int ans = 0;
        if(root->left) ans += calculateCost(root->left, depth + 1);
        if(root->right) ans += calculateCost(root->right, depth + 1);
        return ans;
    }
};

int main() {
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    Huffman h;
    Node* root = h.buildTree(freq);
    cout << h.calculateCost(root);
}
