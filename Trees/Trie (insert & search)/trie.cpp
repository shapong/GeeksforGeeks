#include <iostream>
#include <cstring>

using namespace std;

class Trie {

    typedef struct trie_node {
        int value;
        trie_node* child[26];
    }node;
    int count;
    node* root;

    public:
        node* createNode() {
            node* newNode = new node;
            if(newNode) {
                newNode->value = 0;
                for(int i=0;i<26;i++)
                    newNode->child[i] = NULL;
            }
            return newNode;
        }
        Trie() {
            root = createNode();
            count = 0;
        }
        void insert(char*);
        bool search(char*);

};

void Trie::insert(char* key) {

    int key_length = strlen(key),ind;
    count++;
    node* curr = root;

    for(int i=0;i<key_length;i++) {
        ind = int(key[i]) - (int)'a';
        if(!curr->child[ind]) {
            curr->child[ind] = createNode();
        }
        curr = curr->child[ind];
    }
    curr->value = count;

}

bool Trie::search(char* key) {

    int key_length = strlen(key),ind;
    node* curr = root;

    for(int i=0;i<key_length;i++) {
        ind = int(key[i]) - (int)'a';
        if(!curr->child[ind]) return false;
        else
            curr = curr->child[ind];
    }
    if(curr && curr->value!=0) return true;
    return false;

}

int main() {

    Trie t;
    int N;
    bool ans;
    char* key = new char[100];
    cout << "How many keys do you want to enter?" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> key;
        t.insert(key);
    }

    cout << "How many keys do you want to search for?" << endl;
    cin  >> N;
    for(int i=0;i<N;i++) {
        cin >> key;
        ans = (t.search(key));
        if(ans) cout << "--> '" << key << "' was Found in the Trie\n";
        else cout << "--> '" << key << "' was Not Found in the Trie\n";
    }

}
