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
        void convertToDLL(node*);
        node* make_next_pointers(node*);
        void print_DLL();
        bool find_triplet();
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

node* Tree::make_next_pointers(node* parent) {

    if(!parent) return NULL;
    node* prev = NULL;
    while(parent->right && parent)
        parent = parent->right;

    while(parent && parent->left) {
        prev = parent;
        parent = parent->left;
        parent->right = prev;
    }
    return parent;

}

void Tree::convertToDLL(node* parent) {

    static node* pre = NULL;
    if(parent) {
        convertToDLL(parent->left);
        parent->left = pre;
        pre = parent;
        convertToDLL(parent->right);
    }

    root = make_next_pointers(root);
}

void Tree::print_DLL() {

    node* parent = root;
    while(parent) {
        cout << parent->data << " ";
        parent = parent->right;
    }

}

bool Tree::find_triplet() {

    node* temp, *curr=root,*tail;
    while(curr->right) curr = curr->right;
    tail = curr;
    curr = root;

    int n;
    while(curr!=tail) {
        n = curr->data;
        temp = curr->right;
        while(temp!=tail && temp->data < tail->data) {
            if(temp->data + tail->data == -n) {
                cout << temp->data << " + " << tail->data << " + " << curr->data << " = 0" << endl;
                return true;
            }
            else if(temp->data + tail->data < -n) temp = temp->right;
            else tail = tail->left;
        }
        curr = curr->right;
    }
    return false;
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
    ///Here LEFT pointers are PREV pointers...and RIGHT pointers are NEXT pointers in the DLL...

    cout << "Does the tree have three values that sum up to zero?" << endl;
    t.convertToDLL(t.root);
    (t.find_triplet()) ? cout << "Yes\n" : cout << "No\n";

}
