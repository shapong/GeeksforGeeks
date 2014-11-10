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
        void delete_node_k(int);
        void delete_node(node*);

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

void linked_list::delete_node(node* d) {
    node* temp;
    temp = d->next;
    if(temp==NULL) {
        d = NULL;
    }
    d->data = temp->data;
    d->next = temp->next;
    delete(temp);

}

void linked_list::delete_node_k(int k) {
    node* curr = head->next;
    int count = 1;
    while(count<k && curr!=NULL) {
        curr = curr->next;
        count++;
    }

    //cout << curr->data << endl;
    if(curr==NULL || count!=k) return;
    delete_node(curr);

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

    /// Doesn't delete the last node in the list...

    cout << "Which Kth node do you want to delete?" << endl;
    cin >> k;

    l.delete_node_k(k);
    l.print_list();

}
