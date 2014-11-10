#include <iostream>

using namespace std;

class doubly_linked_list {

    typedef struct list_node {
        int data;
        list_node* next;
        list_node* prev;
    } node;
    node* head, *middle;
    int stack_count;

    public:
        doubly_linked_list() {
            head = new node;
            head->next = NULL;
            head->prev = NULL;
            middle = head;
            stack_count = 0;
        }
        node* create_node(int num) {
            node* n = new node;
            n->data = num;
            n->next = NULL;
            n->prev = NULL;
            return n;
        }
        void push(int);
        void pop();
        void delete_middle();
        int get_middle();
        void print_list();
};

void doubly_linked_list::print_list() {
    node* curr;
    curr = head->next;
    while(curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void doubly_linked_list::push(int num) {

    node* n = create_node(num);
    node* temp = head->next;
    if(temp!=NULL) {
        n->next = temp;
        temp->prev = n;
    }
    head->next = n;
    n->prev = head;
    stack_count++;

    if(stack_count==1)
        middle = head->next;

    else if(stack_count%2==0)
        middle = middle->prev;
}

int doubly_linked_list::get_middle() {
    if(stack_count==0) { cout << "Empty List" << endl; return -1; }
    return middle->data;
}

void doubly_linked_list::pop() {

    node* first = head->next;
    if(first==NULL) return;

    head->next = first->next;

    if(first->next!=NULL) first->next->prev = head;
    delete(first);
    stack_count--;

    if(stack_count==1)
        middle = head->next;
    else if(stack_count%2==1)
        middle = middle->next;

}

void doubly_linked_list::delete_middle() {

    if(stack_count==0) return;
    node* temp_prev = middle->prev;
    temp_prev->next = middle->next;

    if(middle->next!=NULL) middle->next->prev = temp_prev;
    delete(middle);
    stack_count--;

    if(stack_count==0)
        middle = head;
    else if(stack_count%2==0)
        middle = temp_prev;
    else if(stack_count%2==1)
        middle = temp_prev->next;

}

int main() {

    doubly_linked_list l;
    string op;
    int N,num;
    cout << "How many operations do you want to make" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> op;
        if(op.compare("pop")==0) l.pop();
        else if(op.compare("push")==0) { cin >> num; l.push(num); }
        else if(op.compare("middle")==0) cout << "The middle element is: " << l.get_middle() << endl;
        else if(op.compare("delete_mid")==0) l.delete_middle();
        else cout << "ERROR: Incorrect command...try ( middle, push, pop, delete_mid )" << endl;
        cout << "The list is: "; l.print_list();
    }

    cout << "After the operations the doubly linked list is:" << endl;
    l.print_list();

}
