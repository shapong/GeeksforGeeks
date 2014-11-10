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
        linked_list merge(linked_list&);
        node* merge_recur(node*,node*);
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

node* linked_list::merge_recur(node* a, node* b) {

    node* result = NULL;
    if(a==NULL) return b;
    else if(b==NULL) return a;

    if(a->data < b->data) {
        result = a;
        result->next = merge_recur(a->next,b);
    }
    else {
        result = b;
        result->next = merge_recur(a,b->next);
    }
    return result;

}

linked_list linked_list::merge(linked_list& l) {

    linked_list result;
    node* end = result.head;
    node* curr = head->next, *curr1=l.head->next;

    while(curr!=NULL && curr1!=NULL) {
        if(curr->data < curr1->data) {
            end->next = create_node(curr->data);
            curr = curr->next;
        }
        else {
            end->next= create_node(curr1->data);
            curr1 = curr1->next;
        }
        end = end->next;
    }

    if(curr==NULL && curr1!=NULL) {
        while(curr1!=NULL) {
            end->next = create_node(curr1->data);
            end = end->next;
            curr1 = curr1->next;
        }
    }
    else if(curr1==NULL && curr!=NULL) {
        while(curr!=NULL) {
            end->next = create_node(curr->data);
            end = end->next;
            curr = curr->next;
        }
    }
    return result;
}

int main() {

    linked_list l,l1,res;
    int N,num,M;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cin >> M;
    for(int i=0;i<M;i++) {
        cin >> num;
        l1.push_node(num);
    }

    cout << "The list is:" << endl;
    l.print_list();
    cout << "The list is:" << endl;
    l1.print_list();

    cout << "The merged list is:" << endl;
    res = l.merge(l1);
    res.print_list();

    cout << "Again the merged list is:" << endl;
    res.head->next = l.merge_recur(l.head->next,l1.head->next);
    res.print_list();

}
