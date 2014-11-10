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
        void left_view();
        void left_view_again(node*,int);
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

void Tree::left_view() {
    ///Level order traversal...
    queue<node*> Q;
    node* parent = root;
    Q.push(parent);

    int temp;
    while(!Q.empty()) {
        temp = Q.size();

        cout << Q.front()->data << endl;
        while(temp > 0) {
            parent = Q.front(); Q.pop();
            if(parent->left) Q.push(parent->left);
            if(parent->right) Q.push(parent->right);
            temp--;
        }
    }
}

void Tree::left_view_again(node* parent, int level) {
    static int max_level = 0;
    if(!parent) return;

    if(level > max_level) {
        cout << parent->data << endl;
        max_level = level;
    }
    left_view_again(parent->left,level+1);
    left_view_again(parent->right,level+1);

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

    cout << "The left view of the tree is:" << endl;
    t.left_view();

    cout << "AGAIN: The left view of the tree is:" << endl;
    t.left_view_again(t.root,1);
}
