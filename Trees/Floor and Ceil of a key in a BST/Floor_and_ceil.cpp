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
        int find_ceil(node*,int);
        int find_floor(node*,int);
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

int Tree::find_ceil(node* parent, int key) {

    if(!parent) return -1;

    if(key == parent->data) return key;
    else if(key > parent->data)
        return find_ceil(parent->right,key);

    int ceil = find_ceil(parent->left,key);
    return (ceil >= key) ? ceil : parent->data;
}

int Tree::find_floor(node* parent, int key) {

    if(!parent) return -1;

    if(key == parent->data) return key;
    else if(key < parent->data)
        return find_floor(parent->left,key);

    int floor = find_floor(parent->right,key);
    return (floor <= key && floor!=-1) ? floor : parent->data;

}

int main() {

    Tree t;
    int num,N,key;

    cout << "Enter a tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "Enter a key to find its floor and ceiling:" << endl;
    cin >> key;

    cout << "The Ceil of " << key << " is:" << endl;
    cout << t.find_ceil(t.root,key) << endl;

    cout << "The Floor of " << key << " is:" << endl;
    cout << t.find_floor(t.root,key) << endl;

}
