#include <iostream>

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
        bool get_ancestors(int,node*);
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

bool Tree::get_ancestors(int key, node* parent) {

    if(parent==NULL) return false;

    else if(key==parent->data) return true;

    ///It is an ancestor of an element...if it is in either its left or right subtree
    if(get_ancestors(key,parent->left) || get_ancestors(key,parent->right)) {
        cout << parent->data << " ";
        return true;
    }

    else return false;

}

int main() {

    Tree t;
    int num,N,key;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "For which key do you want all ancestors?" << endl;
    cin >> key;

    if(!t.get_ancestors(key,t.root))
        cout << "Key does not exist" << endl;

}
