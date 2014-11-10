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
        bool isIsomorphic(node*,node*);

};

node* Tree::insert(node* r, int num) {
    node* n = create_node(num);
    if(r==NULL)
        return n;
    if(num <= r->data)
        r->left = insert(r->left,num);
    if(num > r->data)
        r->right = insert(r->right,num);
    return r;
}

void Tree::inorder_print(node* parent) {

    if(parent==NULL) return;
    inorder_print(parent->left);
    cout << parent->data << " ";
    inorder_print(parent->right);
}

bool Tree::isIsomorphic(node* n1, node* n2) {

    if(!n1 && !n2) return true;
    else if((!n1 && n2) || (!n2 && n1)) return false;

    return (n1->data==n2->data) && ((isIsomorphic(n1->right,n2->left) && isIsomorphic(n1->left,n2->right)) ||
            (isIsomorphic(n1->left,n2->left) && (isIsomorphic(n1->right,n2->right))));


}

int main() {

    Tree t,t1;
    int num,N,M;
    cout << "Enter a tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "Enter a tree:" << endl;
    cin >> M;
    for(int i=0;i<M;i++) {
        cin >> num;
        t1.root = t1.insert(t1.root,num);
    }

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "The inorder traversal of the tree is:" << endl;
    t1.inorder_print(t1.root);
    cout << endl;

    cout << "Are the two trees isomorphic?" << endl;
    (t.isIsomorphic(t.root,t1.root)) ? cout << "Yes" << endl : cout << "No" << endl;

}
