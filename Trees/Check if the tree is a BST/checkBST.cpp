#include <iostream>
#include <cstdlib>
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
        bool checkBST(node*,int,int);
        bool checkAgain(node*);
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

bool Tree::checkBST(node* parent, int min, int max) {

    if(!parent) return true;

    if(parent->data > max || parent->data < min) return false;

    return checkBST(parent->left,min,parent->data-1) && checkBST(parent->right,parent->data,max);

    /*return checkBST(parent->left,min,parent->data-1)
    && checkBST(parent->right,parent->data,max)
    && (parent->data >= min && parent->data <= max);*/
}


/// Using the inorder traversal...
bool Tree::checkAgain(node* parent) {

    if(!parent) return true;

    node* prev = NULL;
    if(!checkAgain(parent->left)) return false;
    if(prev && parent->data < prev->data) return false;
    prev = parent;
    return checkAgain(parent->right);

}

int main() {

    Tree t;
    int num,N,a,b;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal is:" << endl;
    t.inorder_print(t.root); cout << endl;

    cout << "Is the tree a Binary Search Tree?" << endl;
    (t.checkBST(t.root,INT_MIN,INT_MAX)) ? cout << "Yes\n" : cout << "No\n";

    cout << "Is the tree a Binary Search Tree?" << endl;
    (t.checkAgain(t.root)) ? cout << "Yes\n" : cout << "No\n";

}
