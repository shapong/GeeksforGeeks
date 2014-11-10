#include <iostream>
#include <climits>

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
        node* preorder_build(int*,int,int,int);
        node* another_preorder_build(int*,int,int,int);
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

node* Tree::preorder_build(int* pre, int n, int min, int max) {

    static int preIndex = 0;

    if(preIndex >= n) return NULL;

    int key = pre[preIndex];

    node* root = NULL;

    if(key > min && key < max) {

        root = create_node(key);
        preIndex++;

        if(preIndex < n) {
            root->left = preorder_build(pre,n,min,key);
            root->right = preorder_build(pre,n,key,max);
        }
    }

    return root;
}

node* Tree::another_preorder_build(int* pre, int n, int low, int high) {

    static int preIndex=0;

    if(low > high || preIndex >= n) return NULL;

    node* root = create_node(pre[preIndex]);
    preIndex++;

    if(low==high) return root;

    int i;
    for(i=low;i<=high;i++)
        if(pre[i] > root->data) break;

    root->left = another_preorder_build(pre,n,preIndex,i-1);
    root->right = another_preorder_build(pre,n,i,high);
    return root;

}

int main() {

    Tree t,t1;
    int N;
    cout << "Enter the preorder traversal of a tree:" << endl;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    cout << "--> After building the tree using the preorder traversal..." << endl;
    t.root = t.preorder_build(a,N,INT_MIN,INT_MAX);

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "--> Using another method to build the tree with the preorder traversal..." << endl;
    t1.root = t1.another_preorder_build(b,N,0,N-1);

    cout << "The inorder traversal of the tree is:" << endl;
    t1.inorder_print(t1.root);
    cout << endl;
}
