#include <iostream>

using namespace std;

void bst_array_sort(int* a, int start, int end) {

    if(start > end) return;

    bst_array_sort(a,start*2+1,end);
    cout << a[start] << " ";
    bst_array_sort(a,start*2+2,end);

}

int main() {

    int N;
    cin >> N;

    int* bst = new int[N];
    for(int i=0;i<N;i++)
        cin >> bst[i];

    ///Given level order traversal & only works for a complete binary tree....
    ///Children are stored at +1 and +2 indices...
    bst_array_sort(bst,0,N-1);

}
