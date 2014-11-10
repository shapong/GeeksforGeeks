#include <iostream>
#include <map>

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
        linked_list get_union(linked_list&);
        linked_list get_intersection(linked_list&);

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

linked_list linked_list::get_union(linked_list& l2) {

    /// Hash table implementation is more appropraite than a map
    map<int,int> m;
    linked_list result;

    node* curr = head->next;
    while(curr!=NULL) {
        if(m.find(curr->data)==m.end()) {
            m.insert(make_pair(curr->data,1));
            result.push_node(curr->data);
        }
        else
            m[curr->data]++;
        curr = curr->next;
    }

    curr = l2.head->next;
    while(curr!=NULL) {
        if(m.find(curr->data)==m.end()) {
            m.insert(make_pair(curr->data,1));
            result.push_node(curr->data);
        }
        else
            m[curr->data]++;
        curr = curr->next;
    }

    return result;
}

linked_list linked_list::get_intersection(linked_list& l2) {

    /// Hash table implementation is more appropraite than a map
    map<int,int> m;
    linked_list result;

    node* curr = head->next;
    while(curr!=NULL) {
        if(m.find(curr->data)==m.end())
            m.insert(make_pair(curr->data,1));
        else
            m[curr->data]++;
        curr = curr->next;
    }

    curr = l2.head->next;
    while(curr!=NULL) {
        if(m.find(curr->data)==m.end()) {;}
        else {
            result.push_node(curr->data);
            m[curr->data]++;
        }
        curr = curr->next;
    }

    return result;
}

int main() {

    int N,M,num;
    cout << "Enter in the size of both lists and then the elements one by one" << endl;
    cin >> N;

    linked_list l,l2;
    for(int i=0;i<N;i++) {
        cin >> num;
        l.push_node(num);
    }
    cin >> M;
    for(int i=0;i<M;i++) {
        cin >> num;
        l2.push_node(num);
    }

    linked_list result;
    result = l.get_union(l2);
    cout << "The union of both lists is: " << endl;
    result.print_list();

    result = l.get_intersection(l2);
    cout << "The intersection of both lists is: " << endl;
    result.print_list();


}
