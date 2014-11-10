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
        void pairwise_swap();

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

void linked_list::pairwise_swap() {
    node* curr=head->next, *temp = curr->next, *prev=head;
    while(curr!=NULL) {
        if(curr->next==NULL) break;
        curr->next = temp->next;
        temp->next = curr;
        prev->next = temp;
        ///Update pointers...
        prev = curr;
        curr = curr->next;
        temp = (curr!=NULL) ? curr->next : NULL;
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

    l.pairwise_swap();

    cout << "After the pairwise sawpping of elements the list is: " << endl;
    l.print_list();


}
