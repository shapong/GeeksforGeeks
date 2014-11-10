#include <iostream>

using namespace std;

int getContSub(int* arr, int n) {

    int maxn,minn,max_length=1;
    int storeIndI,storeIndJ;
    for(int i=0;i<n;i++) {
        minn = arr[i]; maxn = arr[i];
        for(int j=i+1;j<n;j++) {
            maxn = max(maxn,arr[j]);
            minn = min(minn,arr[j]);
            if((maxn-minn == j-i) && (maxn-minn+1 > max_length)) {
                max_length = maxn-minn+1;
                storeIndI = i;
                storeIndJ = j;
                //cout << minn << maxn << endl;
                //cout << "I " << i << endl;
                //cout << "J " << j << endl;
                //cout << "max len " << maxn-minn << endl;
            }
        }
    }
    cout << "From index: " << storeIndI << " to index: " << storeIndJ << endl;
    return max_length;
}

int main() {

    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << "The length of the largest subarray with contiguous elements is:" << endl;
    cout << getContSub(arr,n) << endl;

}
