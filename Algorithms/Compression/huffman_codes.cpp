#include <bits/stdc++.h>
using namespace std;

struct Node {
    string ch;
    Node *left, *right;
    long long freq;

    Node(string c, long long f, Node *x = NULL, Node *y = NULL) {
        this->ch = c;
        this->freq = f;
        left = x;
        right = y;
    } 

    bool isLeaf() { return left == NULL && right == NULL; }
};

struct compareNode {
    bool operator() (Node* n1, Node* n2) { return n1->freq > n2->freq; }
};

Node* huffman(priority_queue<Node*, vector<Node*>, compareNode> pq) {
    while(pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node("$", left->freq + right->freq, left, right);
        pq.push(parent);
    }

    return pq.top();
}

void buildMap(map<string, string>& mp, string s, Node* x) {
    if(x->ch != "$") {
       mp[x->ch] = s;
       return;
    } else {
        buildMap(mp, s + "0", x->left);
        buildMap(mp, s + "1", x->right);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, f;
    string c;
    priority_queue<Node*, vector<Node*>, compareNode> pq;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> f;
        pq.push(new Node(to_string(i), f));
    }

    Node* root = huffman(pq);
    map<string, string> mp;
    buildMap(mp, "", root);

    for(auto it = mp.begin(); it != mp.end(); it++) 
        cout << it->first << ' ' << it->second << '\n';

    return 0;
}