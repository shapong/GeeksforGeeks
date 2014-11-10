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
            //root = new node;
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
        void preorder_print(node*);
        void postorder_print(node*);

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

void Tree::postorder_print(node* parent) {
    if(parent==NULL) return;
    postorder_print(parent->left);
    postorder_print(parent->right);
    cout << parent->data << " ";
}

void Tree::preorder_print(node* parent) {
    if(parent==NULL) return;
    cout << parent->data << " ";
    preorder_print(parent->left);
    preorder_print(parent->right);
}

int main() {

    Tree t;
    int num,N;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "Inorder print: " << endl;
    t.inorder_print(t.root); cout << endl;
    cout << "Preorder print: " << endl;
    t.preorder_print(t.root); cout << endl;
    cout << "Postorder print: " << endl;
    t.postorder_print(t.root);


}
