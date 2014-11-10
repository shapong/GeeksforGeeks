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
        void get_range_keys(int,int,node*);
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

void Tree::get_range_keys(int a, int b, node* parent) {

    if(parent==NULL) return;
    if(parent->data > a) get_range_keys(a,b,parent->left);
    if(parent->data >= a && parent->data <= b) cout << parent->data << " ";
    if(parent->data < b) get_range_keys(a,b,parent->right);

}

int main() {

    Tree t;
    int num,N,a,b;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "What's the range of keys you want?" << endl;
    cin >> a >> b;

    cout << "The keys that are in the range... " << a << ":" << b << " inclusive are:" << endl;
    t.get_range_keys(min(a,b),max(a,b),t.root);
    cout << endl;

}
