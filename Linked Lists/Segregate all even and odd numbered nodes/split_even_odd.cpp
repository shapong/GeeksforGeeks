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
        void split_even_odd();

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

void linked_list::split_even_odd() {

    node* end = head->next;
    while(end->next!=NULL)
        end = end->next;

    node* newend = end, *odd=head->next, *prev_odd = head;

    while(odd != end) {
        /// We found an odd number...so move it to the end...
        if(odd->data%2==1) {
            newend->next = odd;
            prev_odd->next = odd->next;
            odd->next = NULL;
            ///only happen when a switch is made...
            odd = prev_odd->next;
            newend = newend->next;
        }
        else {
            odd = odd->next;
            prev_odd = prev_odd->next;
        }
    }

    ///the last node is odd....
    node *lasteven = head;
    if(end->data%2==1) {
        while(lasteven->next!=end)
            lasteven = lasteven->next;
        newend->next = end;
        lasteven->next = end->next;
        end->next = NULL;
    }

}

int main () {

    linked_list l;
    int N,num;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cout << "The list is: " << endl;
    l.print_list();

    l.split_even_odd();

    cout << "After spliting the odd and even valued elements the list is: " << endl;
    l.print_list();

    l.split_even_odd();

    cout << "After spliting the odd and even valued elements the list is: " << endl;
    l.print_list();

}
