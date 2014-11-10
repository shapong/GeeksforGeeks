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
        int height(node*);
        int diameter(node*);
        int diameterOpt(node*, int*);
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

int Tree::height(node* parent) {

    if(!parent) return 0;

    return 1 + max(height(parent->left),height(parent->right));
}

int Tree::diameter(node* parent) {

    if(!parent) return 0;

    int ld,rd;
    ld = diameter(parent->left);
    rd = diameter(parent->right);

    return max(max(ld,rd),height(parent->left)+height(parent->right)+1);
}

int Tree::diameterOpt(node* parent, int* height) {

    if(!parent) {*height=0; return 0; }
    int lh=0,rh=0;

    int ld=0,rd=0;
    ld = diameterOpt(parent->left,&lh);
    rd = diameterOpt(parent->right, &rh);

    *height = max(lh,rh) + 1;

    return max(max(ld,rd),lh+rh+1);

}

int main() {

    Tree t;
    int num,N,sum;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "Inorder:" << endl;
    t.inorder_print(t.root); cout << endl;
    cout << "The diameter (i.e. the farthest dist. b/w 2 leaves) of the tree is:" << endl;
    cout << t.diameter(t.root) << endl;

    cout << "The diameter (i.e. the farthest dist. b/w 2 leaves) of the tree is:" << endl;
    int ht = 0;
    cout << t.diameterOpt(t.root, &ht) << endl;
    cout << ht << endl;

}
