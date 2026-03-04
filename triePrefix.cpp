#include <iostream> 
using namespace std;

struct Node {
    Node* next[26] = {};
    bool end = false;
};

void insert(Node* root, string s) {
    for(char c : s) {
        int i = tolower(c) - 'a';
        if(!root->next[i]) 
            root->next[i] = new Node();
        root = root->next[i];
    }
    root->end = true;
}

bool search(Node* root, string s) {
    for(char c : s) {
        int i = tolower(c) - 'a';
        if(!root->next[i]) 
            return false;
        root = root->next[i];
    }
    return root->end;
}

int main() {
    Node* root = new Node();

    string keys[] = {
        "and","bat","ball","book","cot","cotton",
        "internet","interview","joy","job",
        "king","lion","man","mango","manage"
    };

    for(string k : keys) 
        insert(root, k);

    string w;
    cin >> w;

    cout << (search(root, w) ? "Found" : "Not Found");
}
