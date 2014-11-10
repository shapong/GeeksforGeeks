#include <iostream>
#include <stack>

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
        node* prune_paths(node*,int,int*);
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

node* Tree::prune_paths(node* parent, int k, int* sum) {

    if(!parent) return NULL;

    int lsum,rsum;
    lsum = *sum + parent->data;
    rsum = lsum;

    parent->left = prune_paths(parent->left,k,&lsum);
    parent->right = prune_paths(parent->right,k,&rsum);

    *sum = max(lsum,rsum);

    if(*sum < k) {
        delete(parent);
        parent = NULL;
    }

    return parent;
}

int main () {

    Tree t;
    int N,num,k;
    cout << "Enter Tree:" << endl;

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "What is k?" << endl;
    cin >> k;

    int sum = 0;
    t.prune_paths(t.root,k,&sum);
    cout << "After removing the nodes that lie on a path with sum less than " << k << endl;
    t.inorder_print(t.root);

}
