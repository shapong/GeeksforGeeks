#include <iostream>

using namespace std;

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
        void rotate(int);

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
    cout << << endl;
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

///counterclockwise rotation...
void linked_list::rotate(int k) {

    get_length();
    //cout << "lenght: " << length << endl;
    if(k >= length) k = k % length;

    if(k==0) return;

    node* curr = head->next, *kth, *kth1;
    int travelled = 0;
    while(curr->next!=NULL) {
        travelled++;
        if(travelled==k) kth = curr;
        else if(travelled==k+1) kth1 = curr;
        curr = curr->next;
    }

    //cout << "Kth: " << kth->data << endl;
    //cout << "K+1 th: " << kth1->data << endl;
    //cout << "End: " << curr->data << endl;

    curr->next = head->next;
    head->next = kth1;
    kth->next = NULL;

}

int main () {

    linked_list l;
    int N,num,k;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cout << "The list is: " << endl;
    l.print_list();

    cout << "How many times do you want to rotate the list?" << endl;
    cin >> k;
    l.rotate(k);
    cout << "\nThe list rotated is...\n" << endl;
    l.print_list();

}
