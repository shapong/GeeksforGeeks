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
        bool check_subtree(Tree&);
        bool check(node*,node*);
        bool identical(node*,node*);
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

bool Tree::identical(node* t1, node* t2) {

    if(t1==NULL && t2==NULL) return true;
    if(t1==NULL || t2==NULL) return false;

    return ((t1->data == t2->data) && identical(t1->left,t2->left) && identical(t1->right,t2->right));
}

bool Tree::check(node* t1, node* t2) {

    if(t2==NULL) return true;    ///subtree (smaller tree)
    if(t1==NULL) return false;

    if(identical(t1,t2)) return true;
    return check(t1->left,t2) || check(t1->right,t2);
}

bool Tree::check_subtree(Tree& t2) {
    return check(root,t2.root);
}

int main() {

    Tree t,t1;
    int num,N,M;

    cout << "Enter Tree 1:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "Enter Tree 2:" << endl;
    cin >> M;
    for(int i=0;i<M;i++) {
        cin >> num;
        t1.root = t1.insert(t1.root,num);
    }

    cout << "Is Tree2 a subtree of Tree1?" << endl;
    (t.check(t.root,t1.root)) ? cout << "Yes\n" : cout << "No\n";

}
