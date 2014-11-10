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
        bool path_sum(int,int,node*);
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

bool Tree::path_sum(int sum_so_far, int sum, node* parent) {

    //Only cases in which intial parent is NULL...not a base case for recursion
    if(parent==NULL) return (sum_so_far==sum);

    if((sum==sum_so_far+parent->data) && (!parent->left) && (!parent->right)) {
        cout << sum_so_far << endl;
        return true;
    }

    //cout << "Parent: " << parent->data << " and sum is here: " << sum_so_far << endl;

    bool ans=false;
    int temp = sum_so_far + parent->data;
    ans = path_sum(temp,sum,parent->left);
    ans = ans || path_sum(temp,sum,parent->right);

    return ans;
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

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "What path-sum do you want to find?" << endl;
    cin >> sum;
    (t.path_sum(0,sum,t.root)) ? cout << "Has the path sum..." : cout << "Doesn't have path sum...";
    cout << " " << sum << endl;

}
