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
        int diff_between_levels();
        int diff_between_levels_again(node*);
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

int Tree::diff_between_levels() {

    node* parent = root;
    queue<node*> Q;
    Q.push(parent);

    int level = 0,temp,even_sum=0,odd_sum=0;
    while(!Q.empty()) {
        level++;
        temp = Q.size();
        while(temp > 0) {
            parent = Q.front(); Q.pop();
            if(level%2==1) odd_sum += parent->data;
            else even_sum += parent->data;
            if(parent->left) Q.push(parent->left);
            if(parent->right) Q.push(parent->right);
            temp--;
        }
    }
    cout << "The odd sum: " << odd_sum << " and the even sum: " << even_sum << endl;
    return odd_sum-even_sum;
}

int Tree::diff_between_levels_again(node* parent) {

    if(!parent) return 0;

    return parent->data - diff_between_levels_again(parent->left) - diff_between_levels_again(parent->right);

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

    cout << "The difference between the odd and even levels is:" << endl;
    cout << t.diff_between_levels() << endl;

    cout << "AGAIN: The difference between the odd and even levels is:" << endl;
    cout << t.diff_between_levels_again(t.root) << endl;
}
