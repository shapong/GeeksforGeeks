#include <iostream>

using namespace std;

class linked_list {

    typedef struct list_node {
        int data;
        list_node* next;
    } node;
    node* head;
    int n0,n1,n2;

    public:
        linked_list () {
            head = new node;
            head->next = NULL;
            n0=0; n1=0; n2=0;
        }
        void push_node(int);
        node* create_node(int num) {
            node* n = new node;
            n->data = num;
            n->next = NULL;
            return n;
        }
        void print_list();
        void get_counts();
        void sort_list();

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

void linked_list::get_counts() {
    node* curr;
    curr = head->next;
    n0=0,n1=0,n2=0;
    while(curr!=NULL) {
        switch(curr->data) {
            case 0:
                n0++; break;
            case 1:
                n1++; break;
            case 2:
                n2++; break;
        }
        curr = curr->next;
    }
}

void linked_list::sort_list() {
    node* curr = head->next;
    while(curr!=NULL) {
        while(n0 > 0) { curr->data = 0; n0--; curr = curr->next; }
        while(n1 > 0) { curr->data = 1; n1--; curr = curr->next; }
        while(n2 > 0) { curr->data = 2; n2--; curr = curr->next; }
    }
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

    l.get_counts();
    l.sort_list();

    cout << "After sorting only the zeros, ones, and twos...: " << endl;
    l.print_list();

}
