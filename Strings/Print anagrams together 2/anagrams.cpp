#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Trie {

    typedef struct trie_node {
        list<int> str_list;
        trie_node* child[26];
    }node;
    int count;

    public:
        node* root;
        node* createNode() {
            node* newNode = new node;
            if(newNode) {
                for(int i=0;i<26;i++)
                    newNode->child[i] = NULL;
            }
            return newNode;
        }
        Trie() {
            root = createNode();
            count = 0;
        }
        void insert(string&,int);
        bool search(string&);
        void traverse(node*,vector<string>&);

};

void Trie::insert(string& key, int index) {

    int key_length = key.length(),ind;
    count++;
    node* curr = root;

    for(int i=0;i<key_length;i++) {
        ind = int(key[i]) - (int)'a';
        if(!curr->child[ind]) {
            curr->child[ind] = createNode();
        }
        curr = curr->child[ind];
    }
    curr->str_list.push_back(index);

}

void Trie::traverse(node* parent, vector<string>& v) {

    if(!parent) return;

    if(!parent->str_list.empty()) {
        for(list<int>::iterator it = parent->str_list.begin();it!=parent->str_list.end();it++)
            cout << v[*it] << endl;
    }

    for(int i=0;i<26;i++)
        traverse(parent->child[i],v);

}

int main() {

    int N;
    string str;
    Trie t;
    cout << "How many strings?" << endl;
    cin >> N;
    vector<string> orig_strs;
    for(int i=0;i<N;i++) {
        cin >> str;
        orig_strs.push_back(str);
        sort(str.begin(),str.end());
        t.insert(str,i);
    }
    cout << "The anagrams are:" << endl;
    t.traverse(t.root,orig_strs);
}
