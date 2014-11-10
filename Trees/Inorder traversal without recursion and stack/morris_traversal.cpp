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
        void morris_traversal(node*);
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

void Tree::morris_traversal(node* parent) {

    node* current=parent,*pre;
    while(current!=NULL) {

        ///if left is NULL
        if(!current->left) {
            cout << current->data << " ";
            current = current->right;
        }
        ///if left is NOT NULL
        else {
            pre = current->left;
            while(pre->right!=NULL && pre->right!=current)
                pre = pre->right;
            ///---Predecessor has not been visited...
            if(pre->right!=current) {
                pre->right = current;
                current = current->left;
            }
            ///---Predecessor has been visited...
            else {
                cout << current->data  << " ";
                pre->right = NULL;
                current = current->right;
            }
        }
    }
}

int main() {

    Tree t;
    int num,N,sum;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    ///The Morris Traversal is the inorder traversal of a tree without using a stack or recursion...
    ///Instead this algo uses "threaded binary trees" where the LEFT & RIGHT pointers of leaves...
    ///...point to the PREV & NEXT nodes in the inorder traversal

    cout << "The Morris Traversal of the tree is:" << endl;
    t.morris_traversal(t.root);
    cout << endl;

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

}
