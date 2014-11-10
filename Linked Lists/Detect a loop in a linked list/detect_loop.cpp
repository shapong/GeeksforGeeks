#include <iostream>

using namespace std;

typedef struct list_node {
        int data;
        list_node* next;
} node;

class linked_list {

    public:
        node* head;
        linked_list () {
            head = new node;
            head->next = NULL;
        }
        void push_node(int);
        node* create_node(int num) {
            node* n = new node;
            n->data = num;
            n->next = NULL;
            return n;
        }
        void print_list();
        bool detectLoop();
        void make_loop(int);
};

void linked_list::push_node(int num) {
    node* n = create_node(num);
    node* curr;
    curr = head;
    while(curr->next!=NULL)
        curr = curr->next;
    curr->next = n;
}

void linked_list::print_list() {
    node* curr;
    curr = head->next;
    while(curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

bool linked_list::detectLoop() {

    node* slow=head,*fast=head->next;
    while(fast!=slow && fast) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) return true;
    return false;
}

void linked_list::make_loop(int l) {

    if(l==-1) return;
    node* curr = head->next,*tail;
    while(curr->next) {
        curr = curr->next;
    }
    tail = curr;
    curr = head->next;
    while(curr->data!=l && curr) {
        curr = curr->next;
    }
    tail->next = curr;

}

int main() {

    linked_list l;
    int N,num,loop;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "Where is the loop?" << endl;
    cin >> loop;
    l.make_loop(loop);

    cout << "Is there a loop in the linked list?" << endl;
    bool ans = l.detectLoop();
    (ans) ? cout << "Yes\n" : cout << "No\n";

    if(!ans) {
        cout << "The list is:" << endl;
        l.print_list();
    }
}
