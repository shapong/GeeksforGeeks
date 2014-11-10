#include <iostream>

using namespace std;

typedef struct list_node {
    int data;
    list_node* next;
} node;

class linked_list {

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
        node* reverse_list_k(node*,int);

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

node* linked_list::reverse_list_k(node* h, int k) {

    if(h==NULL) return h;

    node *prev=NULL,*curr=h,*next=curr->next;
    int count=1;
    while(next!=NULL && count < k) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
        count++;
    }
    curr->next = prev;
    head->next->next = reverse_list_k(next,k);;
    head->next = curr;


//    if(next!=NULL) {
  //      reverse_list_k(next,k);
    //}

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

    cout << "Enter K: " << endl;
    cin >> k;
    l.reverse_list_k(l.head->next,k);

    cout << "The reversed list is: " << endl;
    l.print_list();

    /*l.reverse_list();

    cout << "The reversed list is: " << endl;
    l.print_list();*/

}
