#include <iostream>
#include <map>

using namespace std;

class doubly_linked_list {

    typedef struct list_node {
        int data;
        list_node* next;
        list_node* prev;
    } node;
    node* head,*tail;
    int queue_count,max_mem;
    map<int,node*> hash_table;

    public:
        doubly_linked_list(int m) {
            head = new node;
            head->next = NULL;
            head->prev = NULL;
            queue_count=0;
            max_mem = m;
            tail = head;
        }
        node* create_node(int num) {
            node* n = new node;
            n->next = NULL;
            n->prev = NULL;
            n->data = num;
            return n;
        }
        void print_list();
        void push(int);
        void pop();
        void req_page(int);
        void move_back(node*);
};

void doubly_linked_list::print_list() {
    node* curr;
    curr = head->next;
    while(curr!=NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

void doubly_linked_list::push(int num) {

    if(queue_count==max_mem) { cout << "Cache is full" << endl; return; }
    node* n = create_node(num);
    tail->next = n;
    n->prev = tail;
    tail = tail->next;
    hash_table.insert(make_pair(num,n));
    queue_count++;

}

void doubly_linked_list::pop() {

    if(head->next==NULL) return;
    node* first = head->next;

    head->next = first->next;

    if(first->next!=NULL) first->next->prev = head;

    hash_table.erase(first->data);
    delete(first);
    queue_count--;

    if(queue_count==0) tail = head;

}

void doubly_linked_list::move_back(node* n) {
    node* temp_prev = n->prev;
    temp_prev->next = n->next;
    if(n->next!=NULL) n->next->prev = temp_prev;
    else tail = temp_prev;

    hash_table.erase(n->data);
    queue_count--;

    push(n->data);

    delete(n);
}

void doubly_linked_list::req_page(int page) {

    ///if the page is already there in the cache...
    if(hash_table.find(page)!=hash_table.end()) {
        move_back(hash_table[page]);
    }

    ///if the page is not there in the cache and the queue is full...
    else if(hash_table.find(page)==hash_table.end() && queue_count==max_mem) {
        pop();
        push(page);
    }

    else if(hash_table.find(page)==hash_table.end() && queue_count!=max_mem)
        push(page);

}

int main() {

    int N,nop,num;
    string op;
    cout << "What is the cache capapcity?" << endl;
    cin >> N;
    doubly_linked_list l(N);
    cout << "How many operations do you want to make" << endl;
    ///------GET is the only command that needs to be used....!
    cin >> nop;
    for(int i=0;i<nop;i++) {
        cin >> op;
        if(op.compare("pop")==0) l.pop();
        else if(op.compare("push")==0) { cin >> num; l.push(num); }
        else if(op.compare("get")==0) {cin >> num; l.req_page(num); }
        else cout << "ERROR: Incorrect command...try ( push, pop, or get )" << endl;
        cout << "The list is: (LRU) "; l.print_list(); cout << "(MFU)"<< endl;
        /// LRU = least recently used...
        /// MFU = most frequently used...
    }

}
