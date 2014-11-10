#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool find4numbers(int* a, int n, int sum) {

    qsort(a,n,sizeof(int),compare);

    int temp,l,r; bool flag = true;
    for(int i=0;i<n-3;i++) {
        for(int j=i+1;j<n-2;j++) {
            temp = a[i] + a[j];
            l = j+1;
            r = n-1;
            while(l < r) {
                if(a[l]+a[r] < sum-temp) l++;
                else if(a[l]+a[r] > sum-temp) r--;
                else if(a[l]+a[r]==sum-temp){
                    cout << a[l] << " "  << a[r] << " " << a[i] << " " << a[j] << endl;
                    l++; r--; flag = false;
                }
            }
        }
    }

    if(flag) return false;
    return true;
}

int main() {

    int N,sum;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Input a sum to find for four numbers:" << endl;
    cin >> sum;

    (find4numbers(a,N,sum)) ? cout << "Four numbers do add to the sum\n" : cout << "No four numbers add to the sum\n";

}
