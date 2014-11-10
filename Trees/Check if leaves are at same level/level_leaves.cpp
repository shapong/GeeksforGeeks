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
        bool leafsAtSameLevel(node*,int);
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

bool Tree::leafsAtSameLevel(node* parent, int level) {

    static int leafLevel = 0;
    if(!parent) return true;

    if(!parent->right && !parent->left) {
        if(leafLevel==0) {
            leafLevel = level;
            return true;
        }
        return (level == leafLevel);
    }

    return leafsAtSameLevel(parent->left,level+1) && leafsAtSameLevel(parent->right,level+1);

}

int main () {

    Tree t;
    int num,N;

    cout << "Enter Tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "Are all the leaves at the same level?" << endl;
    (t.leafsAtSameLevel(t.root,0)) ? cout << "Yes\n" : cout << "No\n";
}
