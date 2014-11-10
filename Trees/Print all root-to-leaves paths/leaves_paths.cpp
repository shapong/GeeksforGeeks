#include <iostream>
#include <vector>

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
        void print_leaves_paths(node*,vector<int>);
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

void Tree::print_leaves_paths(node* parent, vector<int> v) {

    if(parent==NULL) return;

    else
        v.push_back(parent->data);

    if(parent->right==NULL && parent->left==NULL) {
        for(int i=0;i<v.size();i++) cout << v[i] << " ";
        cout << endl;
    }
    else {
        print_leaves_paths(parent->left,v);
        print_leaves_paths(parent->right,v);
    }
}

int main() {

    Tree t;
    int num,N;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    vector<int> v;
    cout << "The paths to the leaves are:" << endl;
    t.print_leaves_paths(t.root,v);

}
