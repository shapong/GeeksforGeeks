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
        bool isPalindrome(int);
        void reverse(node*,node*);
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

void linked_list::reverse(node* start, node* mid) {

    node* curr=start,*prev=NULL,*next=start->next;
    while(curr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next) next = next->next;
    }
    mid->next = prev;
}

bool linked_list::isPalindrome(int count) {

    node* mid,*slow=head,*fast=head->next,*temp,*rev_s,*rev_b;
    while(fast) {
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
        if(fast && !fast->next) temp = slow;
    }
    mid = slow->next;
    temp = (count%2==0) ? slow : temp->next;
    //cout << "start: " << mid->data << endl;
    //cout << "before: " << temp->data << endl;
    reverse(mid,temp);
    print_list();
    node* curr=head->next,*sec=temp->next;
    rev_s = sec; rev_b = temp;
    while(sec) {
        if(sec->data!=curr->data) {
            reverse(rev_s,rev_b);
            return false;
        }
        sec = sec->next;
        curr = curr->next;
    }
    reverse(rev_s,rev_b);
    return true;

}

int main() {

    linked_list l;
    int N,num,loop;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }

    cout << "Is the linked list a palindrome?" << endl;
    bool ans = l.isPalindrome(N);
    (ans) ? cout << "Yes\n" : cout << "No\n";

    cout << "The list is:" << endl;
    l.print_list();
}
