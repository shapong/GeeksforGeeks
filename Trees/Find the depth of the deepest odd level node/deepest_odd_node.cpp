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
        int deepest_odd_node();
        int depthOfOddLeafUtil(node*,int);
        int depthOfOddLeaf();
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

int Tree::deepest_odd_node() {

    node* parent = root;
    queue<node*> Q;
    Q.push(parent);

    int depth = 0,max,temp,md;
    while(!Q.empty()) {
        depth++;
        temp = Q.size();
        if(depth%2==1) {
            max = Q.front()->data;
            md = depth;
        }
        while(temp > 0) {
            parent = Q.front(); Q.pop();
            if(parent->left) Q.push(parent->left);
            if(parent->right) Q.push(parent->right);
            temp--;
        }
    }
    cout << max << " is the deepest ODD level node" << endl;
    return md;
}

int Tree::depthOfOddLeafUtil(node* parent, int level) {

    if(!parent) return 0;

    if(!parent->left && !parent->right && level%2==1) return level;

    return max(depthOfOddLeafUtil(parent->left,level+1),depthOfOddLeafUtil(parent->right,level+1));

}

int Tree::depthOfOddLeaf() {
    return depthOfOddLeafUtil(this->root,1);
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

    cout << "The depth of the deepest odd level node is (depth starting at 1):" << endl;
    cout << t.deepest_odd_node() << endl;

    cout << "AGAIN: The depth of the deepest odd level node is (depth starting at 1):" << endl;
    cout << t.depthOfOddLeaf() << endl;

}
