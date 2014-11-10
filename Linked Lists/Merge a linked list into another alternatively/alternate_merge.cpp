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
        void alternate_merge(node*);
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

void linked_list::alternate_merge(node* list) {

    list = list->next;
    node* curr=head->next,*cNext=curr->next,*lNext=list->next;

    while(curr->next && list) {
        curr->next = list;
        list->next = cNext;
        curr = cNext;
        if(curr) cNext = curr->next;
        list = lNext;
        if(list) lNext = list->next;
    }

    if(list) curr->next = list;

}

int main() {

    linked_list l,l1;
    int N,num;
    cout << "Enter a list:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "Enter another list to merge with the other one:" << endl;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l1.push_node(num);
    }

    cout << "The merged linked list is:" << endl;
    l.alternate_merge(l1.head);
    l.print_list();

    delete(l1.head);

}
