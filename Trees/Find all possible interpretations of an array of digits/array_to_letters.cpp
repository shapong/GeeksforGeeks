#include <iostream>
#include <vector>

using namespace std;

typedef struct tree_node {
    string data;
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
        node* create_node(string& s) {
            node* n = new node;
            n->data.assign(s);
            n->left = NULL;
            n->right = NULL;
            return n;
        }
        void inorder_print(node*);
        void print_interpretations(node*);
        node* alphabetize(node*,int,int,vector<int>&,string);
};

void Tree::inorder_print(node* parent) {
    if(parent==NULL) return;
    inorder_print(parent->left);
    cout << parent->data << " ";
    inorder_print(parent->right);
}

node* Tree::alphabetize(node* parent, int low, int high, vector<int>& v, string s) {

    int length = v.size();
    if((low >= length) || (high >= length)) return NULL;

    if((low==high) && (low >=0) && v[low] > 0) s.push_back(char(v[low]+96));
    else if(low==high && v[low]==0) return NULL;
    else if(low!=high) {
        int temp=0;
        if((low < length) && (high < length)) {
            temp = (10*v[low]) + v[high];
            if(temp <= 26) s.push_back(char(temp+96));
            else return NULL;
        }
    }
    parent = create_node(s);

    parent->left = alphabetize(parent->left,high+1,high+1,v,s);
    parent->right = alphabetize(parent->right,high+1,high+2,v,s);

    return parent;

}

void Tree::print_interpretations(node* parent) {

    if(!parent) return;
    if(!parent->left && !parent->right) {
        cout << parent->data << " ";
    }

    print_interpretations(parent->left);
    print_interpretations(parent->right);
}

int main () {

    Tree t;
    int num,N;

    cout << "Enter an array <No zeros>:" << endl;
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++) {
        cin >> num;
        v.push_back(num);
    }

    string s="";
    cout << "The possible interpretaions of the given vector using the alphabet are:" << endl;
    t.root = t.alphabetize(t.root,-1,-1,v,s);

    t.print_interpretations(t.root);
    cout << endl;

    cout << "The inorder of the whole tree traversal is:" << endl;
    t.inorder_print(t.root);
}
