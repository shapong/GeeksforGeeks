#include <iostream>
#include <vector>

using namespace std;

typedef struct list_node {
        char data;
        list_node* next;
        list_node* prev;
} node;

class doubly_linked_list {
    node* head;

    public:
        doubly_linked_list() {
            head = new node;
            head->next = NULL;
            head->prev = NULL;
        }
        node* create_node(char num) {
            node* n = new node;
            n->data = num;
            n->next = NULL;
            n->prev = NULL;
            return n;
        }
        void push(char);
        void pop();
        void print_list();
        void find_non_repeat(char,node* d[],vector<bool>&);
};

void doubly_linked_list::print_list() {
    node* curr;
    curr = head->next;
    while(curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void doubly_linked_list::push(char c) {

    node* n = create_node(c);
    node* temp = head->next;
    if(temp!=NULL) {
        n->next = temp;
        temp->prev = n;
    }
    head->next = n;
    n->prev = head;
}

void doubly_linked_list::pop() {

    node* first = head->next;
    if(first==NULL) return;

    head->next = first->next;

    if(first->next!=NULL) first->next->prev = head;
    delete(first);

}

void doubly_linked_list::find_non_repeat(char x, node* inDL[], vector<bool>& v) {

    if(v[x-'0']) {
        cout << head->next->data << endl;
        return;
    }

}

int main(){

    int n;
    cin >> n;

    doubly_linked_list dl;
    node* inDL[256];
    for(int i=0;i<256;i++) inDL[i] = NULL;
    vector<bool> visited (256,false);
    char c;
    for(int i=0;i<n;i++) {
        cin >> c;
        dl.find_non_repeat(c,inDL,visited);
    }
}
