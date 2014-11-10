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
        node* make_full_tree(int*,int*,int,int,int);
        void postorder_print(node*);
        void preorder_print(node*);
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

void Tree::preorder_print(node* parent) {
    if(!parent) return;
    cout << parent->data << " ";
    preorder_print(parent->left);
    preorder_print(parent->right);
}

node* Tree::make_full_tree(int* pre, int* post, int low, int high, int n) {

    static int preIndex = 0;
    if(low > high || preIndex > n-1) return NULL;
    node* new_node = create_node(pre[preIndex]);
    preIndex++;

    if(low==high) return new_node;

    int next,ind;
    next = pre[preIndex];

    for(ind=low;ind<=high;ind++)
        if(post[ind]==next) break;

    ///everything to the right of ind...and not including
    new_node->left = make_full_tree(pre,post,low,ind,n);
    new_node->right = make_full_tree(pre,post,ind+1,high-1,n);

    return new_node;

}

int main() {

    Tree t;
    int num,N;

    cout << "Enter the preorder traversal:" << endl;
    cin >> N;
    int* pre = new int[N];
    int* post = new int[N];
    for(int i=0;i<N;i++)
        cin >> pre[i];

    cout << "Enter the postorder traversal:" << endl;
    for(int i=0;i<N;i++)
        cin >> post[i];

    cout << endl;
    t.root = t.make_full_tree(pre,post,0,N-1,N);
    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;
    cout << endl;

    cout << "The preorder traversal of the tree is:" << endl;
    t.preorder_print(t.root);
    cout << endl;

    cout << "The postorder traversal of the tree is:" << endl;
    t.postorder_print(t.root);
    cout << endl;

}
