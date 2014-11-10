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
        void make_preorder(node*,int*);
        bool internal_one_child(int*,int);
        bool internal_check_again(int*,int);
        bool internal_child_again(int*,int);
        bool internal_recur(node*);
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

void Tree::make_preorder(node* parent, int* pre) {

    static int ind = 0;
    if(!parent) return;
    pre[ind] = parent->data; ind++;
    make_preorder(parent->left,pre);
    make_preorder(parent->right,pre);
}

bool Tree::internal_one_child(int* bst, int n) {

    int gt=0;
    for(int i=0;i<n;i++) {
        gt = (bst[i+1] > bst[i]) ? 1 : 0;
        for(int j=i+1;j<n;j++) {
            //all must be greater...
            if(gt) {if(bst[j] <= bst[i]) return false; }
            else { if(bst[j] > bst[i]) return false; }
        }
    }
    return true;
}

bool Tree::internal_check_again(int* bst, int n) {

    int gt = 0;
    for(int i=0;i<n-1;i++) {
        gt = (bst[i+1] > bst[i]) ? 1 : 0;
        if(gt) { if(bst[n-1] <= bst[i]) return false; }
        else { if(bst[n-1] > bst[i]) return false; }
    }
    return true;
}

bool Tree::internal_child_again(int* bst, int n) {

    int minimum = min(bst[n-1],bst[n-2]);
    int maximum = max(bst[n-1],bst[n-2]);

    for(int i=n-3;i>=0;i--) {

        if(bst[i] <= minimum)
            minimum = bst[i];
        else if(bst[i] > maximum)
            maximum = bst[i];
        else return false;
    }

    return true;

}

bool Tree::internal_recur(node* parent) {

    if(parent->right && parent->left) return false;
    if(!parent->right && !parent->left) return true;

    if(parent->left)
        internal_recur(parent->left);
    else if(parent->right)
        internal_recur(parent->right);

}

int main() {

    Tree t;
    int N;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    int* a = new int[N];
    int* pre = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
        t.root = t.insert(t.root,a[i]);
    }

    cout << "The preorder traversal of the tree is:" << endl;
    t.make_preorder(t.root,pre);
    for(int i=0;i<N;i++) cout << pre[i] << " ";
    cout << endl;

    ///BELOW THREE METHODS...ONLY WORK IF GIVEN THE PREORDER TRAVERSAL!!!!!---------/////
    ///Works with a[] too since ancestors are all present before the descendent
    cout << "Do all internal nodes have only one child?" << endl;
    (t.internal_one_child(pre,N)) ? cout << "True" << endl : cout << "False" << endl;

    cout << "Do all internal nodes have only one child?" << endl;
    (t.internal_check_again(pre,N)) ? cout << "True" << endl : cout << "False" << endl;

    cout << "Do all internal nodes have only one child?" << endl;
    (t.internal_child_again(pre,N)) ? cout << "True" << endl : cout << "False" << endl;

    ///Recursive method for internal check....using tree not preorder
    cout << "Do all internal nodes have only one child?" << endl;
    (t.internal_recur(t.root)) ? cout << "True" << endl : cout << "False" << endl;

}
