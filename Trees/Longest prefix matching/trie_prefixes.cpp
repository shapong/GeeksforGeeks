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
        int find_longest_prefix(char*);

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

int Trie::find_longest_prefix(char* key) {

    int max_prefix = 0,ind, key_length = strlen(key);
    node* curr = root;

    for(int i=0;i<=key_length;i++) {
        ind = (int)(key[i]) - (int)'a';
        if(curr && curr->value > 0) max_prefix = i;

        if(i==key_length || !curr->child[ind]) return max_prefix;
        curr = curr->child[ind];
    }

    //if(curr && curr->value > 0) return key_length;
    return max_prefix;

}

int main() {

    Trie t;
    int N;
    int ans;
    char* key = new char[100];
    cout << "How many keys do you want to enter?" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> key;
        t.insert(key);
    }

    cout << "How many keys do you want the longest prefix for?" << endl;
    cin  >> N;
    for(int i=0;i<N;i++) {
        cin >> key;
        ans = (t.find_longest_prefix(key));
        cout << "The longest prefix in the dictionary for " << key << " is:" << endl;
        if(ans==0) cout << "----NONE---" << endl;
        else {
            for(int i=0;i<ans;i++)
                cout << key[i];
            cout << endl;
        }
    }

}
