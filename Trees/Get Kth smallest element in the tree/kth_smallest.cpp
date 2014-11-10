#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct tree_node {
    int data;
    tree_node* right;
    tree_node* left;
}node;

class Tree {

    public:
        node* root;
        Tree() {
            root = new node;
            root = NULL;
        }
        node* create_node(int num) {
            node* n = new node;
            n->data = num;
            n->left = NULL;
            n->right = NULL;
            return n;
        }
        node* insert(node*, int);
        void inorder_print(node*);
        int kth_elem(node*,int);
};

node* Tree::insert(node* r, int num) {
    node* n = create_node(num);
    if(r==NULL)
        return n;
    if(num < r->data)
        r->left = insert(r->left,num);
    else
        r->right = insert(r->right,num);
    return r;
}

void Tree::inorder_print(node* parent) {
    if(parent==NULL) return;
    inorder_print(parent->left);
    cout << parent->data << " ";
    inorder_print(parent->right);
}

int Tree::kth_elem(node* parent, int k) {

    stack<node*> s;
    int n;
    node* curr = root;

    bool flag = true;
    while(k > 0) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        if(!curr && !s.empty()) {
            curr = s.top();
            //cout << curr->data << " ";
            n = curr->data;
            k--;
            curr = curr->right;
            s.pop();
        }
        else if(!curr && s.empty()) return -1;
    }
    return n;

}

int main() {

    ///Method 2 using RANKS in the tree is NOT shown here....

    Tree t;
    int num,N,k;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "Which Kth smallest element do you want?" << endl;
    cin >> k;

    cout << "Inorder traversal:" << endl;
    t.inorder_print(t.root); cout << endl;

    cout << "The Kth smallest element is:" << endl;
    cout << t.kth_elem(t.root,k) << endl;


    string s = "144";
    int a = atoi(s.c_str());
    cout << a << endl;
}
