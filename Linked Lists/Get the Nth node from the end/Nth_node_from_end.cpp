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
        }
        void push_node(int);
        node* create_node(int num) {
            node* n = new node;
            n->data = num;
            n->next = NULL;
            return n;
        }
        void print_list();
        void get_length();
        void Nth_from_end(int);
        int get_nth_again(int);

};

void linked_list::push_node(int num) {
    node* n = create_node(num);
    node* curr=head;
    while(curr->next!=NULL)
        curr = curr->next;
    curr->next = n;
}

void linked_list::print_list() {
    node* curr = head->next;
    while(curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void linked_list::get_length () {
    node* curr;
    curr = head->next;
    length = 0;
    while(curr!=NULL) {
        length++;
        curr = curr->next;
    }
}

void linked_list::Nth_from_end(int k) {

    get_length();

    node* curr = head->next;
    if(length - k < 0) { cout << "The node does not exist" << endl; return; }
    for(int i=0;i<length-k;i++) {
        //cout << curr->data << endl;
        curr = curr->next;
    }
    cout << curr->data << endl;

}

int linked_list::get_nth_again(int N) {

    node* n_ahead=head->next,*curr=head->next;
    while(N-1 > 0 && n_ahead!=NULL) {
        n_ahead = n_ahead->next;
        N--;
    }
    if(n_ahead==NULL) return -1;
    while(n_ahead->next!=NULL) {
        n_ahead = n_ahead->next;
        curr = curr->next;
    }
    return curr->data;

}

int main() {

    linked_list l;
    int N,num,k;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "The list is: " << endl;
    l.print_list();

    cout << "Get which node from the end?" << endl;
    cin >> k;

    cout << "The " << k << "th node from the end of the list is: " << endl;
    l.Nth_from_end(k);

    cout << "The " << k << "th node from the end of the list again is...: " << endl;
    cout << l.get_nth_again(k) << endl;

}
