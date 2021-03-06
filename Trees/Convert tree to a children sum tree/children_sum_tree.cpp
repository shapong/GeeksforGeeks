#include <iostream>
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
        void increment(node*,int);
        void childSum(node*);
        node* build_tree(int*,int*,int,int);
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

void Tree::increment(node* parent, int d) {

    if(parent->left) {
        parent->left->data+=d;
        increment(parent->left,d);
    }
    else if(parent->right) {
        parent->right->data+=d;
        increment(parent->right,d);
    }
}

void Tree::childSum(node* parent) {

    if(!parent || (!parent->left && !parent->right))
        return;

    int lsum=0,rsum=0;

    childSum(parent->left);
    childSum(parent->right);

    if(parent->left) lsum = parent->left->data;
    if(parent->right) rsum = parent->right->data;

    int diff = (lsum+rsum) - parent->data;
    //cout << "DIFF: " << diff << endl;

    if(diff > 0) parent->data += diff;

    else if(diff < 0) increment(parent,-diff);

}

node* Tree::build_tree(int* in, int* pre, int start, int end) {

    if(start > end) return NULL;

    //Is intialized only once during entire program (i.e. all calls to the func dont reinitialize...)
    static int preIndex =0;

    int inIndex=0, data = pre[preIndex];
    node* new_node = create_node(data);
    preIndex++;

    if(start==end) return new_node;

    for(int i=start;i<=end;i++)
        if(in[i]==data) inIndex=i;
//    cout << "InIndex: " << inIndex << endl;

    new_node->left = build_tree(in,pre,start,inIndex-1);
    new_node->right = build_tree(in,pre,inIndex+1,end);

    return new_node;

}

int main() {

    Tree t;
    int num,N;
    cout << "How many nodes are in the tree:" << endl;
    cin >> N;
    cout << "The inorder traversal of the tree is:" << endl;
    int* in = new int[N];
    int* pre =  new int[N];
    for(int i=0;i<N;i++) {
        cin >> num;
        in[i] = num;
    }
    cout << "The preorder traversal of the double tree is:" << endl;
    for(int i=0;i<N;i++) {
        cin >> num;
        pre[i] = num;
    }

    t.root = t.build_tree(in,pre,0,N-1);
    cout << "After building the tree...the inorder traversal is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "After converting it to a tree with the children sum property:" << endl;
    t.childSum(t.root);
    t.inorder_print(t.root);

}
