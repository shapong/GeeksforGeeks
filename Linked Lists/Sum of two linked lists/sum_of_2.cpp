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
        linked_list getSum();
        linked_list addSame(node*,node*,int*);

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

node* linked_list::addSame(node* l1, node* l2, int* carry) {


}

linked_list::getSum(linked_list& l1) {

    int carry = 0;
    addSame(this,l1,&carry);

}

int main() {

    linked_list l,l1,l2;
    int N,num;
    cout << "Enter two linked lists:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l1.push_node(num);
    }

    l2 = l.getSum(l1);

    return 0;
}
