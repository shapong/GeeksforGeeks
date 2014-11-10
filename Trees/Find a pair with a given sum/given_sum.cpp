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
        bool has_sum(int);
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

bool Tree::has_sum(int sum) {

    node* curr = root,*curr1 = root;
    stack<node*> s,s1;
    bool flag = true, flag1 = true;
    int ind = 0,low,high,val1,val2;

    while(1) {
        while(flag) {
            if(curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                if(!s.empty()) {
                    curr = s.top(); s.pop();
                    //cout << "FIRST " << curr->data << " ";
                    val1 = curr->data;
                    flag = false;
                    curr = curr->right;
                }
                else flag = false;
            }
        }

        while(flag1) {
            if(curr1) {
                s1.push(curr1);
                curr1 = curr1->right;
            }
            else {
                if(!s1.empty()) {
                    curr1 = s1.top(); s1.pop();
                    //cout << "SECOND " << curr1->data << " ";
                    val2 = curr1->data;
                    flag1 = false;
                    curr1 = curr1->left;
                }
                else flag1 = false;
            }
        }
        if(val1+val2==sum) {
            cout << val1 << " + " << val2 << " = " << sum << endl;
            return true;
        }
        else if(val1+val2 < sum) flag = true;
        else if(val1+val2 > sum) flag1 = true;
        if(val1 > val2 || curr==curr1) {
            cout << "There are no two elements that add up to " << sum << endl;
            return false;
        }
    }
    return true;

}

int main () {

    Tree t;
    int N,num,sum;
    cout << "Enter Tree:" << endl;

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        t.root = t.insert(t.root,num);
    }

    cout << "What sum do you want to find?" << endl;
    cin >> sum;

    cout << "Does the tree have two nodes that add up to " << sum << "?" << endl;
    (t.has_sum(sum)) ? cout << "Yes\n" : cout << "No\n";

}
