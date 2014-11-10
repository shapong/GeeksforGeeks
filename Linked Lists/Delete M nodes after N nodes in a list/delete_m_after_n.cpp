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
        void reverse_print(node*);
        void delete_n(int,int);
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

void linked_list::delete_n(int n, int m) {

    node* curr = head->next, *dnode,*temp;

    int countM=m,countN=n;
    while(curr!=NULL) {

        while(countM-1 > 0 && curr!=NULL) {
            curr = curr->next;
            countM--;
        }

        if(curr!=NULL) dnode = curr->next;
        else return;

        while(countN > 0 && dnode!=NULL) {
            temp = dnode;
            dnode = dnode->next;
            delete(temp);
            countN--;
        }
        curr->next = dnode;

        countM = m; countN = n;
        curr = curr->next;
    }
}

int main() {

    linked_list l;
    int N,num,n,m;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cout << "The list is: " << endl;
    l.print_list();

    cout << "Enter N(delete N nodes) and M(after M nodes): " << endl;
    cin >> n >> m;

    l.delete_n(n,m);

    cout << "The list after deleting " << n << " nodes after every " << m << " nodes is:" << endl;
    l.print_list();

}
