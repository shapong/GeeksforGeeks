#include <iostream>

using namespace std;

class linked_list {

    typedef struct list_node {
        int data;
        list_node* next;
    } node;
    node* head;

    public:
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
        void reverse_print(node*);
        void delete_dups();
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

void linked_list::delete_dups() {

    node *prev=head->next;
    if(prev==NULL) return;
    node *curr=prev->next;
    while(curr!=NULL) {
        if(curr->data > prev->data) {
            curr = curr->next;
            prev = prev->next;
        }

        ///else the element will be equal...since it is sorted...(>=)
        else {
            prev->next = curr->next;
            delete(curr);
            curr = prev->next;
        }
    }
}

int main() {

    linked_list l;
    int N,num,k;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cout << "The sorted list is: " << endl;
    l.print_list();

    l.delete_dups();
    cout << "The sorted list after deleting duplicates is: " << endl;

    l.print_list();

}
