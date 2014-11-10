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
        void alternating_delete();

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

void linked_list::alternating_delete() {
    node* a=head->next, *b = a->next;
    while(a!=NULL && b !=NULL) {
        if(b!=NULL) a->next = b->next;
        else a->next = NULL;

        b->next = NULL;
        delete (b);

        a = a->next;
        if(a!=NULL) b = a->next;
        else b = NULL;
    }

}

int main () {

    linked_list l;
    int N,num,M;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "The list is: "<< endl;
    l.print_list();

    l.alternating_delete();

    cout << "After deleting alternate nodes..." << endl;
    l.print_list();

}
