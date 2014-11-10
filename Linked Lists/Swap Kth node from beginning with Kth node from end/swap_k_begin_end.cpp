#include <iostream>

using namespace std;

//class object creates a new list
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
        void get_length();
        void swap_kth(int);

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

void linked_list::get_length () {
    node* curr;
    curr = head->next;
    length = 0;
    while(curr!=NULL) {
        length++;
        curr = curr->next;
    }
}

void linked_list::swap_kth(int k) {

    get_length();
    //cout << "length: " << length << endl;

    /// list is shorter and has no Kth node...
    if(length < k || k<=0) return;

    /// Kth node from begining and end is the same so K is in the middle...
    if(2*k -1 == length) return;

    node *x = head, *y = head, *y_prev = NULL, *x_prev = NULL, *temp;
    for(int i=0;i<max(k,length-k+1);i++) {
        if(i<min(k,length-k+1)) {
            x_prev = x;
            x = x->next;
        }
        y_prev = y;
        y = y->next;
    }

    //cout << "X: " << x->data << " Y: " << y->data << endl; are being swapped...

    if(x_prev) x_prev->next = y;
    if(y_prev) y_prev->next = x;

    temp = x->next;
    x->next = y->next;
    y->next = temp;
}

int main() {

    linked_list l;
    int N,num;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    int k;
    l.print_list();

    cout << "Which two Kth elements (beginning and end) do you want to swap: " << endl;
    cin >> k;
    l.swap_kth(k);
    cout << "After swapping the " << k << "element from the beginning and the " << k << "element from the end..." << endl;
    l.print_list();

    cout << "Which two Kth elements (beginning and end) do you want to swap: " << endl;
    cin >> k;
    l.swap_kth(k);
    cout << "After swapping the " << k << "element from the beginning and the " << k << "element from the end..." << endl;
    l.print_list();
    return 0;
}
