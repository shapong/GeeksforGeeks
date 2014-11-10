#include <iostream>

using namespace std;

int INT_MAX;

void first_second_min(int* a, int n) {

    int first=INT_MAX,second=INT_MAX;
    for(int i=0;i<n;i++) {
        if(a[i]<first) {
            second = first;
            first = a[i];
        }
        else if(a[i]<second) second = a[i];
    }
    cout << "The smallest element is: " << first << endl;
    cout << "The second smallest element is: " << second << endl;

}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
        if(i==0) INT_MAX = a[0];
        if(a[i] > INT_MAX && i!=0) INT_MAX = a[i];
    }

    first_second_min(a,N);

}
