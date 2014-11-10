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
        void reverse_print(node*);
        node* kth_delete(int n) {
            node* curr=head->next;
            while(n-1 > 0 && curr!=NULL) {
                curr = curr->next;
                n--;
            }
            return curr;
        }

        void delete_node(node*,int);
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

void linked_list::delete_node(node* first, int k) {
    node* pointer = kth_delete(k);
    node* temp = first;
    if(pointer==NULL) return;

    if(pointer==first) {
            temp = pointer->next;
            first->data = temp->data;
            first->next = temp->next;
            delete(temp);
    }
    else {
        while(first->next!=pointer && first!=NULL) {
            first = first->next;
        }
        if(first) first->next = pointer->next;
        else return;
        delete(pointer);
    }
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

    cout << "Enter kth node to delete: " << endl;
    cin >> k;
    l.delete_node(l.head->next,k);

    cout << "After deleting the " << k << "th node: " << endl;
    l.print_list();

}
