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
        int find_count(int);

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

int linked_list::find_count(int n) {
    int count = 0;

    node* curr = head->next;
    while(curr!=NULL) {
        if(curr->data==n)
            count++;
        curr = curr->next;
    }

    return count;
}

int main() {

    linked_list l;
    int N,num;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cout << "The list is: " << endl;
    l.print_list();

    cout << "Enter a number to count the number of occurences in the list: " << endl;
    cin >> num;

    int count = l.find_count(num);
    cout << num << " occurs " << count << " times in the list..." << endl;

}
