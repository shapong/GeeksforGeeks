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
        bool check_identical(node*,node*);
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

bool Tree::check_identical(node* t1, node* t2) {

    if(t1==NULL && t2==NULL)
        return true;

    if(t1 && t2)
        return (t1->data==t2->data) &&
                check_identical(t1->left,t2->left) &&
                check_identical(t1->right, t2->right);
    else
        return false;
}

int main() {

    Tree t,t1;
    int num,N;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t1.root = t1.insert(t1.root,num);
    }

    if(t.check_identical(t.root,t1.root))
        cout << "They are identical trees" << endl;
    else
        cout << "They are not identical trees" << endl;


}
