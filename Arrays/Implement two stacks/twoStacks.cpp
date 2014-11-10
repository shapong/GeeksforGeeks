#include <iostream>

using namespace std;

class twoStacks {

    int size;
    int* stackArray;
    int top1,top2;
    public:
        twoStacks(int n) {
            stackArray = new int[n];
            size = n;
            top1 = 0;
            top2 = size-1;
            cout << top1 << top2 << endl;
        }
        void push1(int);
        void push2(int);
        int pop1();
        int pop2();
        void print();
};

void twoStacks::push1(int num) {
    if(top1 > top2) return;
    stackArray[top1] = num;
    top1++;
}

void twoStacks::push2(int num) {
    if(top1 > top2) return;
    stackArray[top2] = num;
    top2--;
}

int twoStacks::pop1() {
    if(top1==0) return -1;
    int data = stackArray[top1-1];
    top1--;
    return data;
}

int twoStacks::pop2() {
    if(top2==size-1) return -1;
    int data = stackArray[top2+1];
    top2++;
    return data;
}

void twoStacks::print() {
    cout << "Stack 1: ";
    for(int i=0;i<top1;i++)
        cout << stackArray[i] << " ";
    cout << "Stack 2: ";
    for(int i=top2+1;i<size;i++)
        cout << stackArray[i] << " ";
    cout << endl;
}

int main() {

    int N,num,stack_size;
    cout << "What should the size of the two stacks be:" << endl;
    cin >> stack_size;
    twoStacks s(stack_size);

    cout << "How many operations do you want to enter:" << endl;
    cin >> N;
    string str;
    for(int i=0;i<N;i++) {
        cin >> str;
        if(str.compare("push1")==0) { cin >> num; s.push1(num); }
        else if(str.compare("push2")==0) { cin >> num; s.push2(num); }
        else if(str.compare("pop1")==0) { cout << "-->Popped: " << s.pop1() << endl; }
        else if(str.compare("pop2")==0) { cout << "-->Popped: " << s.pop2() << endl; }
        else cout << "Error input string" << endl;
        s.print();
        cout << endl;
    }

}
