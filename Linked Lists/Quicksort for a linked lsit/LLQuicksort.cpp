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
        node* getTail();
        void partition(node*,node*);
        void quicksort(node*,node*);
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

node* linked_list::getTail() {

    node* curr=head;
    while(curr->next) {
        curr = curr->next;
    }
    return curr;
}

node* linked_list::partition(node* s, node* e) {

    int compare=e->data;

}

void linked_list::quicksort(node* start, node* end) {

    node* p;
    p = partition();
    quicksort(start,p);
    quicksort(p->next->next,end);

}

int main() {

    linked_list l;
    int N,num;
    cout << "Enter a list:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "After Quicksort on the linked:" << endl;
    l.quicksort(l.head,l.getTail());
    l.print_list();

}
