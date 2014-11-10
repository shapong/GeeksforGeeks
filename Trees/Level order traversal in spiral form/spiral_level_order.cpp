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
        int height(node*);
        void printLevelOrder(node*);
        void printGivenLevel(int,node*,int);
        void spiralLevelOrder();
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

void Tree::printLevelOrder(node* parent) {

    bool dir=0;
    for(int i=1;i<=height(parent);i++) {
        printGivenLevel(i,parent,dir);
        dir = !dir;
        //cout << "hey " << dir << endl;
    }
}

void Tree::printGivenLevel(int level,node* parent, int dir) {

    if(!parent) return;

    if(level==1)
        cout << parent->data << " ";

    else if(level > 1) {
        if(dir) {
            printGivenLevel(level-1,parent->right,dir);
            printGivenLevel(level-1,parent->left,dir);
        }
        else {
            printGivenLevel(level-1,parent->left,dir);
            printGivenLevel(level-1,parent->right,dir);
        }
    }
}

void Tree::spiralLevelOrder() {

    node* curr = root;
    stack<node*> s1,s2;
    s1.push(curr);

    while(!s1.empty() || !s2.empty()) {

        while(!s1.empty()) {
            curr = s1.top(); s1.pop();
            cout << curr->data << " ";
            if(curr->left) s2.push(curr->left);
            if(curr->right) s2.push(curr->right);
        }

        while(!s2.empty()) {
            curr = s2.top(); s2.pop();
            cout << curr->data << " ";
            if(curr->right) s1.push(curr->right);
            if(curr->left) s1.push(curr->left);
        }
    }
    cout << endl;
    return;
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

    cout << "The spiral level order traversal of the tree is: " << endl;
    t.printLevelOrder(t.root);
    cout << endl;

    cout << "The better sprial level order traversal is:" << endl;
    t.spiralLevelOrder();

}
