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
        node* getLeaves(node*,node**);
        void printDLL(node*);
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

node* Tree::getLeaves(node* parent, node** head) {

    if(!parent) return NULL;

    if(!parent->left && !parent->right) {

        parent->right = *head;
        if(*head) (*head)->left = parent;
        *head = parent;

        return NULL;
    }
    parent->right = getLeaves(parent->right,head);
    parent->left = getLeaves(parent->left,head);
    return parent;
}

void Tree::printDLL(node* parent) {

    node* curr=parent,*tail=NULL;
    while(curr) {
        cout << curr->data << " ";
        if(!curr->right) tail = curr;
        curr = curr->right;
    }
    cout << endl;

    cout << "The reverse print of the DLL is:" << endl;
    while(tail) {
        cout << tail->data << " ";
        tail = tail->left;
    }
    cout << endl;
}

int main() {

    Tree t,t1;
    int num,N;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    node* head=NULL;
    cout << "The tree (without its leaves) is:" << endl;
    t.getLeaves(t.root,&head);
    t.inorder_print(t.root);
    cout << endl;

    cout << "The DLL of the extracted leaves is:" << endl;
    t.printDLL(head);

}
