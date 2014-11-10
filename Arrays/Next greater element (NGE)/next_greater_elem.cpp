#include <iostream>
#include <stack>

using namespace std;

void next_greater_element(int* a, int n) {

    stack<int> s;
    s.push(a[0]);

    int next,element;
    for(int i=1;i<n;i++) {
        next = a[i];
        if(!s.empty()) {

            element = s.top();

            while(element < next) {
                s.pop();
                cout << element << ": " << next << endl;
                if(s.empty()) break;
                element = s.top();
            }
        }
        s.push(next);
    }

    while(!s.empty()) {
        cout << s.top() << ": -1" << endl;
        s.pop();
    }

}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The next greater element to the right are given below:" << endl;
    next_greater_element(a,N);

}
