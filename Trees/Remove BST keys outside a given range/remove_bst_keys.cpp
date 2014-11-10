#include <iostream>
#include <queue>

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
        node* remove_range_keys(node*,int,int);
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

node* Tree::remove_range_keys(node* parent, int low, int high) {

    if(!parent) return NULL;
    node* temp;

    parent->left = remove_range_keys(parent->left,low,high);
    parent->right = remove_range_keys(parent->right,low,high);

    if(parent->data < low) {
        //everything to the left of parent has been deleted...
        temp = parent->right;
        delete parent;
        return temp;
    }
    else if(parent->data > high) {
        //everything to the right of parent has been deleted...
        temp = parent->left;
        delete parent;
        return temp;
    }

    return parent;
}

int main() {

    Tree t;
    int num,N,lower,upper;
    cout << "Enter a tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "Enter a range for the keys outside which you want the node to be removed:" << endl;
    cin >> lower >> upper;

    cout << "After removing keys outside the range: " << lower << ":" << upper << " the tree is:" << endl;
    t.remove_range_keys(t.root,lower,upper);
    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

}
