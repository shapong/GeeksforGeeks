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
        int getWidth(node*);
        void getMaxWidth(node*,int*,int);
        int getWidthAgain();
        int height(node*);
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

    return max(height(parent->left),height(parent->right))+1;
}

int Tree::getWidth(node* parent) {

    queue<node*> Q;
    Q.push(parent);

    int temp=0,max_width = 0;
    while(!Q.empty()) {
        temp = Q.size();
        if(temp > max_width) max_width = temp;

        while(temp > 0) {
            parent = Q.front(); Q.pop();
            if(parent->left) Q.push(parent->left);
            if(parent->right) Q.push(parent->right);
            temp--;
        }
    }
    return max_width;

}

void Tree::getMaxWidth(node* parent, int* count, int level) {

    if(!parent) return;

    count[level]++;
    //cout << level << endl;
    getMaxWidth(parent->left,count,level+1);
    getMaxWidth(parent->right,count,level+1);
}

int Tree::getWidthAgain() {

    int h = height(root),maxw=0;
    int* count = new int[h];
    for(int i=0;i<h;i++) count[i]= 0;
    getMaxWidth(root,count,0);

    for(int i=0;i<h;i++)
        if(count[i] > maxw) maxw = count[i];
    return maxw;

}

int main() {

    Tree t;
    int num,N,a,b;
    cout << "Enter the number of nodes:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "The inorder traversal:" << endl;
    t.inorder_print(t.root);
    cout << endl;

    cout << "The width < widest part of the tree > is:" << endl;
    cout << t.getWidth(t.root) << endl;

    cout << "The width < widest part of the tree > is:" << endl;
    cout << t.getWidthAgain() << endl;

}
