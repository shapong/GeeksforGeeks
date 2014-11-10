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
        linked_list sorted_intersect(linked_list&);
        node* recur_sorted_intersect(node*,node*,node*);
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

linked_list linked_list::sorted_intersect(linked_list& l) {

    linked_list res;

    node* curr=head->next,*curr1=l.head->next,*end=res.head;
    while(curr!=NULL && curr1!=NULL) {
        if(curr->data < curr1->data) {
            curr = curr->next;
        }
        else if(curr1->data < curr->data) {
            curr1 = curr1->next;
        }
        else {
            end->next = create_node(curr->data);
            curr = curr->next;
            curr1 = curr1->next;
            end = end->next;
        }
    }
    return res;
}

node* linked_list::recur_sorted_intersect(node* a, node* b, node* result) {

    node* temp=NULL;
    if(a==NULL || b==NULL) return NULL;

    if(a->data < b->data)
        return recur_sorted_intersect(a->next,b,result);
    else if(b->data < a->data)
        return recur_sorted_intersect(a,b->next,result);
    else {
        temp = create_node(a->data);
        if(result==NULL) result = temp;
        else  {
            result->next = temp;
            result = result->next;
        }
        result->next = recur_sorted_intersect(a->next,b->next,result);
    }
    return result;
}

int main() {

    linked_list l,l1,res,res1;
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

    cout << "The sorted interesect of the two lists is:" << endl;
    res = l.sorted_intersect(l1);
    res.print_list();

    cout << "The sorted interesect of the two lists again is:" << endl;
    res1.head->next = l.recur_sorted_intersect(l.head->next,l1.head->next,res1.head->next);
    res1.print_list();
}
