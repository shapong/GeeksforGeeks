#include <iostream>

using namespace std;

int* partition(int* a, int n) {
    int storeIndex=0;
    for(int i=0;i<n;i++){
        if(a[i] < 0){
            if(i!=storeIndex) swap(a[i],a[storeIndex]);
            storeIndex++;
        }
    }
    //return a; all neg in front and all positive at end
    //...storeIndex = start of pos values
    //for(int i=0;i<n;i++) cout << a[i] << endl;


    int pos=storeIndex, neg=0;
    while(neg < pos && pos < n && a[neg] < 0){
        swap(a[pos],a[neg]);
        pos++;
        neg = neg + 2;
    }

    return a;
}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];



    a = partition(a,N);

    for(int i=0;i<N;i++) cout << a[i] << endl;


}
