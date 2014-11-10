#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
struct mymap {
    T value;
    int freq;
};

bool map_compare(const mymap<int> m1, mymap<int> m2) {
    return (m1.freq > m2.freq) ? true : false;
}

void sort_by_freqs(int* a, int n) {
    sort(a,a+n);
    mymap<int>* M = new mymap<int>[n];
    int num = a[0],count=1,ind=0;
    for(int i=1;i<n;i++) {
        if(a[i] > num) {
            M[ind].value = num;
            M[ind].freq = count;
            num = a[i];
            count = 1;
            ind++;
        }
        else
            count++;
    }
    M[ind].value = num;
    M[ind].freq = count;
    sort(M,M+ind,map_compare);

    for(int i=0;i<=ind;i++) {
        //cout << M[i].value << " " << M[i].freq << endl;
        for(int j=0;j<M[i].freq;j++) {
            cout << M[i].value << " ";
        }
    }
    cout << endl;
    return;

}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    ///Note!!! If you want to keep the original order when freqs TIE...
    ///then also save the first index in the structure...

    sort_by_freqs(a,N);

}
