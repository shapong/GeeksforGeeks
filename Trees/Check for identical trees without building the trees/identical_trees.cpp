#include <iostream>
#include <climits>
#include <vector>

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
        bool areIdentical(vector<int>&,vector<int>&,int,int,int,int,int);
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

bool Tree::areIdentical(vector<int>& v, vector<int>& v1, int n, int i1, int i2, int min, int max) {

    int ind=i1,ind1=i2;

    while((v[ind] < min || v[ind] > max) && ind < n) { ind++; }
    while((v1[ind1] < min || v1[ind1] > max) && ind1 < n) { ind1++; }

    if(ind1==n && ind==n) return true;

    if((v[ind]!=v1[ind1]) || ((ind==n)^(ind1==n))) return false;

    return (areIdentical(v,v1,n,ind+1,ind1+1,v[ind],max) && areIdentical(v,v1,n,ind+1,ind1+1,min,v[ind]));


}

int main() {

    Tree t,t1;
    int num,N,M;
    cin >> N;
    vector<int> v,v1;
    for(int i=0;i<N;i++) {
        cin >> num;
        v.push_back(num);
    }
    cin >> M;
    for(int i=0;i<M;i++) {
        cin >> num;
        v1.push_back(num);
    }

    cout << "Are the trees identical?" << endl;
    if(M!=N) { cout << "No\n"; return 0; }
    (t.areIdentical(v,v1,v.size(),0,0,INT_MIN,INT_MAX)) ? cout << "Yes\n" : cout << "No\n";

}
