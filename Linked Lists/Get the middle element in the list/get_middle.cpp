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
        void check_identical(linked_list&);
        int get_middle();
        int get_middle_again();

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

int linked_list::get_middle() {

    node* mid=head->next, *fast=head->next;
    int count = 1;
    while(fast->next!=NULL) {
        if(count%2==1)
            mid = mid->next;

        count++;
        fast = fast->next;
    }
    return mid->data;

}

///Works better....
int linked_list::get_middle_again() {

    node *fast=head->next, *slow=head->next;
    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;

}

int main() {

    linked_list l;
    int N,num;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "The middle element is: " << endl;
    cout << l.get_middle() << endl;

    //Works better...
    cout << l.get_middle_again() << endl;

}
