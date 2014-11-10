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
        void iterPostorder();
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

void Tree::iterPostorder() {

    node* parent = root;
    stack<node*> s;
    do {
        while(parent) {
            if(parent->right) s.push(parent->right);
            s.push(parent);
            parent = parent->left;
        }
        parent = s.top(); s.pop();
        if(parent->right && !s.empty() && s.top()==parent->right) {
            s.pop();
            s.push(parent);
            parent = parent->right;
        }
        else {
            cout << parent->data << " ";
            parent = NULL;
        }
    } while(!s.empty());

}

int main () {

    Tree t;
    int N,num;
    cout << "Enter Tree:" << endl;

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The iterative postorder traversal of the tree is..." << endl;
    t.iterPostorder();

}
