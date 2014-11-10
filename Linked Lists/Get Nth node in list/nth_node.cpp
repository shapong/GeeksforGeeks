#include <iostream>

using namespace std;

class linked_list {

    typedef struct list{
        int data;
        struct list* next;
    }node;
    node* head;

    public:
        linked_list() {
            head = new node;
            head->next = NULL;
        }
        node* create_node(int num) {
            node* n = new node;
            n->data = num;
            n->next = NULL;
            return n;
        }
        void push_node(int);
        void print_list();
        int get_nth_node(int);

};

void linked_list::push_node(int num) {
    node* n = create_node(num);
    node* curr = head;
    while(curr->next!=NULL)
        curr = curr->next;
    curr->next = n;
}

void linked_list::print_list() {
    node* curr = head->next;
    while(curr!=NULL) {
        cout << curr->data << " ";
        curr=curr->next;
    }
    cout << endl;
}

int linked_list::get_nth_node(int N) {
    node* curr = head->next;
    while(N-1 > 0 && curr!=NULL) {
        curr = curr->next;
        N--;
    }
    return (curr!=NULL) ? curr->data : -1;
}

int main() {

    linked_list l;
    int N,nth,num;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cout << "Enter N: " << endl;
    cin >> nth;

    cout << "The " << nth << "th node in the list is:" << endl;
    cout << l.get_nth_node(nth) << endl;

}
