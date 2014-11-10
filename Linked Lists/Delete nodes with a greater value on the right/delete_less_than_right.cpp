#include <iostream>


using namespace std;

class linked_list {

    typedef struct list_node {
        int data;
        list_node* next;
    } node;
    node* head;
    int length;

    public:
        linked_list () {
            head = new node;
            head->next = NULL;
            length = 0;
        }
        void push_node(int);
        node* create_node(int num) {
            node* n = new node;
            n->data = num;
            n->next = NULL;
            return n;
        }
        void print_list();
        void reverse_list();
        void delete_smaller_nodes();

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

void linked_list::reverse_list() {
    node *a,*b,*c;
    a = NULL;
    b = head->next;
    c = b->next;
    while(c!=NULL) {
        b->next = a;
        a = b;
        b = c;
        c = c->next;
    }
    b->next = a;
    head->next = b;

}

void linked_list::delete_smaller_nodes() {
    reverse_list();

    node *prev=head, *curr = head->next;
    int max = curr->data;
    while(curr!=NULL) {
        if(curr->data >= max)  {
            max = curr->data;
            curr = curr->next;
            prev = prev->next;
        }
        else {
            prev->next = curr->next;
            curr->next = NULL;
            delete (curr);
            curr = prev->next;
        }
    }

    reverse_list();
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

    l.delete_smaller_nodes();

    cout << "After deleting all elements that have a greater element to the right: " << endl;
    l.print_list();

}
