#include <iostream>
#include <queue>
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
        node* make_tree(int*,int,int);
        void postorder_print(node*);
        int height(node*);
        bool height_balanced(node*);
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

void Tree::postorder_print(node* parent) {

    if(!parent) return;
    postorder_print(parent->left);
    postorder_print(parent->right);
    cout << parent->data << " ";
}

node* Tree::make_tree(int* a, int low, int high) {

    if(low > high) return NULL;

    int mid = (low+high)/2;
    node* n = create_node(a[mid]);

    if(low==high) return n;

    n->left = make_tree(a,low,mid-1);
    n->right = make_tree(a,mid+1,high);

    return n;
}

int Tree::height(node* parent) {

    if(!parent) return 0;

    return 1 + max(height(parent->left),height(parent->right));
}

bool Tree::height_balanced(node* parent) {

    if(parent==NULL) return true;

    int lh,rh;
    lh = height(parent->left);
    rh = height(parent->right);

    return (abs(lh-rh)<=1) && height_balanced(parent->left) && height_balanced(parent->right);

}

int main() {

    Tree t;
    int num,N;

    cout << "Enter a sorted array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
    }

    t.root = t.make_tree(a,0,N-1);
    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "The postorder traversal of the tree is:" << endl;
    t.postorder_print(t.root);
    cout << endl;

    cout << "Is the tree balanced?" << endl;
    (t.height_balanced(t.root)) ? cout << "Yes\n" : cout << "No\n";

}
