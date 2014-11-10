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
        bool identical(node*,node*);

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

void linked_list::check_identical(linked_list& l2) {

    node *curr1 = head->next, *curr2 = l2.head->next;
    while(curr1!=NULL && curr2!=NULL) {
        if(curr1->data!=curr2->data) break;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if(curr1 != NULL || curr2 != NULL)
        cout << "They are not identical" << endl;
    else
        cout << "They are identical" << endl;

    return;
}

///Recursive approach...
/*bool linked_list::identical(node* l1, node* l2) {
    if(l1==NULL && l2 != NULL)
        return 0;
    else if(l1!=NULL && l2==NULL)
        return 0;
    else if(l1->data != l2->data)
        return 0;
    else if(l1==NULL & l2==NULL)
        return 1;

    return identical(l1->next,l2->next);

}*/

int main() {

    linked_list l,l2;
    int N,num,M;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cin >> M;
    for(int i=0;i<M;i++) {
        cin >> num;
        l2.push_node(num);
    }
    cout << "The lists are: " << endl;
    l.print_list();
    l2.print_list();

    l.check_identical(l2);

}
