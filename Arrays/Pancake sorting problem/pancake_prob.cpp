#include <iostream>

using namespace std;

void flip(int* a, int i) {

    int start =0;
    while(start < i) {
        swap(a[start],a[i]);
        start++; i--;
    }
}

void pancake_sort(int* a, int n) {

    int curr_size = n,mi,max;
    while(curr_size > 1) {
        max = a[0]; mi =0;
        for(int i=0;i<curr_size;i++) {
            if(a[i] > max) { mi = i; max = a[i]; }
        }
        flip(a,mi);
        flip(a,curr_size-1);
        curr_size--;
    }
}

int main () {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int * a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The sorted array:" << endl;
    pancake_sort(a,N);
    for(int i=0;i<N;i++)
        cout << a[i] << " ";
    cout << endl;

}
