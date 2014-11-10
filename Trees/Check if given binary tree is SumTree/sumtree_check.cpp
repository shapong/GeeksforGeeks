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
        bool check_sumtree(node*);
        int check_sumtree_again(node*);
        int Sum(node*);
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

int Tree::Sum(node* parent) {
    if(!parent) return 0;
    return Sum(parent->left) + parent->data + Sum(parent->right);
}

bool Tree::check_sumtree(node* parent) {

    int left_sum,right_sum;
    if(!parent || (!parent->left && !parent->right)) return true;

    left_sum = Sum(parent->left);
    right_sum = Sum(parent->right);

    return (left_sum+right_sum==parent->data && check_sumtree(parent->left) && check_sumtree(parent->right));
}

int Tree::check_sumtree_again(node* parent) {

    int ls,rs;
    if(!parent || (!parent->right && !parent->left))
        return 1;

    if(check_sumtree_again(parent->left) && check_sumtree_again(parent->right)) {
        if(!parent->left) ls = 0;
        else if(!parent->left->left && !parent->left->right) ls = parent->left->data;
        else ls = 2*(parent->left->data);

        if(!parent->right) rs = 0;
        else if(!parent->right->left && !parent->right->right) rs = parent->right->data;
        else rs = 2*(parent->right->data);

        return (rs+ls==parent->data);
    }

    return 0;
}

int main() {

    Tree t;
    int num,N;

    cout << "Enter a tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "Is the tree a Sum Tree?" << endl;
    (t.check_sumtree(t.root)) ? cout << "Yes\n" : cout << "No\n";

    cout << "Is the tree a Sum Tree?" << endl;
    (t.check_sumtree_again(t.root)==1) ? cout << "Yes\n" : cout << "No\n";
}
