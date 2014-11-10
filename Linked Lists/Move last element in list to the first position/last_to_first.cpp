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
        void move_last_first();

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

void linked_list::move_last_first() {
    node* curr = head->next, *secondLast = head;
    while(curr->next!=NULL) {
        curr = curr->next;
        secondLast = secondLast->next;
    }

    curr->next = head->next;
    head->next = curr;
    secondLast->next = NULL;

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

    l.move_last_first();

    cout << "After the last element has been moved to the beginning..." << endl;
    l.print_list();

    /*l.move_last_first();

    cout << "After the last element has been moved to the beginning..." << endl;
    l.print_list();*/
}
