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
        node* build_tree(int*,char*,int);
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

node* Tree::build_tree(int* pre, char* preLN, int n) {

    static int ind = 0;
    int temp=ind;

    if(ind==n) return NULL;

    node* new_node = create_node(pre[temp]);
    ind++;
    if(preLN[temp]=='N')
        return new_node;

    new_node->left = build_tree(pre,preLN,n);
    new_node->right = build_tree(pre,preLN,n);

    return new_node;

}

int main() {

    Tree t;
    int N;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    char* preLN = new char[N];
    int* pre = new int[N];
    cout << "Enter the preorder of the elements:" << endl;
    for(int i=0;i<N;i++) {
        cin >> pre[i];
    }
    cout << "Enter either N/L for the elements:" << endl;
    for(int i=0;i<N;i++) {
        cin >> preLN[i];
    }

    cout << "The preorder traversal of the tree is:" << endl;
    for(int i=0;i<N;i++) cout << pre[i] << " ";
    cout << endl;

    t.root = t.build_tree(pre,preLN,N);

    ///Note the function tries to make a complete tree as much as possible by filling both...
    ///...left and right children...THERE CAN BE OTHER TREES MADE from this preorder...
    cout << "After building the tree..the inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);

}
