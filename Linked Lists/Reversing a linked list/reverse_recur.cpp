#include <iostream>

using namespace std;

class linked_list {

    typedef struct list_node {
        int data;
        list_node* next;
    } node;

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
        void reverse_list(node*);
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

void linked_list::reverse_list(node* h) {

    node* first=h;
    if(first==NULL) return;

    node *rest=first->next;

    if(rest==NULL) { head->next = first; return; }

    reverse_list(rest);
    first->next->next = first;

    first->next = NULL;
}

int main() {

    linked_list l;
    int N,num;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cout << "The list is: " << endl;
    l.print_list();


    l.reverse_list(l.head->next);

    cout << "The reversed list is: " << endl;
    l.print_list();

}
