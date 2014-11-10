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
        void print_postorder(int*,int*,int);
        int search(int*,int,int);
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

int Tree::search(int* arr, int num, int n) {

    for(int i=0;i<n;i++)
        if(arr[i]==num) return i;

    return -1;
}

void Tree::print_postorder(int in[], int pre[], int n) {

    int ind = search(in,pre[0],n);

    if(ind!=0) print_postorder(in,pre+1,ind);

    if(ind!=n-1) print_postorder(in+ind+1,pre+ind+1,n-ind-1);

    cout << pre[0] << " ";

}

int main () {

    Tree t;
    int N;
    cout << "How many nodes in the tree?" << endl;
    cin >> N;
    int* in = new int[N];
    int* pre = new int[N];

    cout << "Enter the inorder traversal" << endl;
    for(int i=0;i<N;i++)
        cin >> in[i];
    cout << "Enter the preorder traversal" << endl;
    for(int i=0;i<N;i++)
        cin >> pre[i];

    cout << "The postorder for this tree is:" << endl;
    t.print_postorder(in,pre,N);

}
