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
        int get_level(int,node*);
        int get_level_util(int,node*,int);
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

int Tree::get_level_util(int k, node* p, int level) {

    if(p==NULL)  return 0;

    if(p->data ==k) return level;

    return max(get_level_util(k,p->left,level+1),get_level_util(k,p->right,level+1));
}

int Tree::get_level(int k, node* parent) {

    return get_level_util(k,parent,1);
}

int main() {

    Tree t;
    int num,N,key;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "For which key do you want know its level?" << endl;
    cin >> key;

    cout << "The level of the key " << key << " is:" << endl;

    if(t.get_level(key,t.root)==0)
        cout << "The key does not exist in the tree" << endl;
    else
        cout << t.get_level(key,t.root) << endl;

}
