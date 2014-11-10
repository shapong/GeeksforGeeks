#include <iostream>
#include <queue>

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
        void convertToDLL(node*);
        node* make_next_pointers(node*);
        void print_DLL();
};

node* Tree::insert(node* r, int num) {
    node* n = create_node(num);
    if(r==NULL)
        return n;
    if(num <= r->data)
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

node* Tree::make_next_pointers(node* parent) {
    cout << "heyy" << endl;

    if(!parent) return NULL;
    node* prev = NULL;
    while(parent->right && parent)
        parent = parent->right;

    while(parent && parent->left) {
        prev = parent;
        parent = parent->left;
        parent->right = prev;
    }
    return parent;

}

void Tree::convertToDLL(node* parent) {

    static node* pre = NULL;
    if(parent) {
        convertToDLL(parent->left);
        parent->left = pre;
        pre = parent;
        convertToDLL(parent->right);
    }
    else return;
    root = make_next_pointers(root);
}

void Tree::print_DLL() {

    node* parent = root;
    while(parent) {
        cout << parent->data << " ";
        parent = parent->right;
    }

}

int main () {

    Tree t;
    int num,N;

    cout << "Enter Tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }
    ///Here LEFT pointers are PREV pointers...and RIGHT pointers are NEXT pointers in the DLL...

    cout << "After converting the tree to a doubly linked list..." << endl;
    node* temp=NULL;
    t.convertToDLL(t.root);

    t.print_DLL();
}
