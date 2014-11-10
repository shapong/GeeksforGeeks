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
        linked_list alternating_split();

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

linked_list linked_list::alternating_split() {
    linked_list l2;
    node *a=head->next, *b=a->next, *c=l2.head;
    while(a!=NULL && b!=NULL) {
        a->next = b->next;
        c->next = b;
        b->next = NULL;
        ///Update pointers
        c = c->next;
        a = a->next;
        if(a!=NULL) b = a->next;
        else b = NULL;
    }
    return l2;

}

int main() {

    linked_list l,l2, l3;
    int N,num,M;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "The list is: "<< endl;
    l.print_list();

    l2 = l.alternating_split();
    cout << "After the list has been split up alternatively, the lists are: " << endl;

    l.print_list();
    l2.print_list();

    //l3 = l2.alternating_split();
    //l3.print_list();

}
