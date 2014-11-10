#include <iostream>
#include <queue>

using namespace std;

typedef struct list_node {
        int data;
        list_node* next;
} lnode;

class linked_list {

    public:
        lnode* head;
        linked_list () {
            head = new lnode;
            head->next = NULL;
        }
        void push_node(int);
        lnode* create_node(int num) {
            lnode* n = new lnode;
            n->data = num;
            n->next = NULL;
            return n;
        }
        void print_list();

};

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
        node* prune_paths(node*,int,int*);
        node* convert_binary_tree(linked_list);
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

void linked_list::push_node(int num) {
    lnode* n = create_node(num);
    lnode* curr;
    curr = head;
    while(curr->next!=NULL)
        curr = curr->next;
    curr->next = n;
}

void linked_list::print_list() {
    lnode* curr;
    curr = head->next;
    while(curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

node* Tree::convert_binary_tree(linked_list l) {

    node* tnode, *parent;
    queue<node*> Q;
    lnode* curr = l.head->next->next;
    Q.push(create_node(l.head->next->data));
    parent = Q.front();

    while(curr) {
        tnode = Q.front();
        tnode->left = create_node(curr->data);
        curr = curr->next;
        if(!curr) break;
        tnode->right = create_node(curr->data);
        curr = curr->next;
        if(!curr) break;
        Q.pop();
        Q.push(tnode->left);
        Q.push(tnode->right);
    }

    return parent;
}

int main() {

    Tree t;
    linked_list l;
    int N,num;
    cout << "Enter a list" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "The list is: "<< endl;
    l.print_list();

    cout << "After making the linked list into a complete binary tree..." << endl;
    t.root = t.convert_binary_tree(l);

    t.inorder_print(t.root);

}
