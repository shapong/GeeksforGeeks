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
        void print_ancestors(int);
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

void Tree::print_ancestors(int key) {

    stack<node*> s;
    node* curr = root;

    while(1) {
        while(curr && curr->data!=key) {
            s.push(curr);
            curr = curr->left;
        }

        if(curr && curr->data==key)
            break;

        if(s.top()->right==NULL) {
            curr = s.top(); s.pop();
            while(s.top()->right==curr && !s.empty()) {
                curr = s.top(); s.pop();
            }
        }

        //if(s.empty()) cout << "Node doesn't exist" << endl;
        curr = (s.empty()) ? NULL : s.top()->right;
    }

    while(!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

int main() {

    Tree t;
    int num,N,key;

    cout << "Enter a tree:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal of the tree is:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "For what key do you want all ancestors?" << endl;
    cin >> key;

    cout << "The ancestors in the tree are:" << endl;
    t.print_ancestors(key);

}
