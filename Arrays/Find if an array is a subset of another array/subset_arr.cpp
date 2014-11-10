#include <iostream>
#include <algorithm>

using namespace std;

bool isSubset(int* a1, int* a2, int n, int m)  {

    sort(a1,a1+n);
    sort(a2,a2+m);

    int i=0,j=0;
    while(i < n && j < m) {
        if(a1[i] > a2[j])
            j++;
        else if(a1[i] == a2[j]) {
            i++; j++;
        }
        else if(a1[i] < a2[j])
            return false;
    }

    if(i < n) return false;
    return true;

}

int main() {

    int N,M;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a1 = new int[N];
    for(int i=0;i<N;i++)
        cin >> a1[i];

    cout << "Enter the array:" << endl;
    cin >> M;
    int* a2 = new int[M];
    for(int i=0;i<M;i++)
        cin >> a2[i];

    ///Only method that handles duplicates!!!
    cout << "Is the first array a subset of the second?" << endl;
    (isSubset(a1,a2,N,M)) ? cout << "Yes" << endl : cout << "No" << endl;

}
