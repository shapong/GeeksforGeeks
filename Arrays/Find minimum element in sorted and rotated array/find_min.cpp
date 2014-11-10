#include <iostream>

using namespace std;

int find_min(int* a, int low, int high) {

    int mid = (low+high)/2;

    if((mid!=0 && a[mid-1] > a[mid]) || (mid==0)) return a[mid];

    if(a[mid] < a[high])
        return find_min(a,low,mid-1);
    else
        return find_min(a,mid+1,high);

}

int find_min_dup(int* a, int low, int high) {

    if(low > high) return a[0];

    if(low==high) return a[low];

    int mid = (low+high)/2;

    ///new...
    if(mid < high && a[mid+1] < a[mid])
        return a[mid+1];

    ///new...
    if (a[low] == a[mid] && a[high] == a[mid])
        return min(find_min_dup(a, low, mid-1), find_min_dup(a, mid+1, high));

    ///new...
    if (mid > low && a[mid] < a[mid - 1])
       return a[mid];

    if(a[mid] < a[high])
        return find_min(a,low,mid-1);
    else
        return find_min(a,mid+1,high);
}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];

    ///a[] is a sorted array which is rotated by some elements...
    for(int i=0;i<N;i++)
        cin >> a[i];

    ///DOESNT WORK FOR (12: 2 2 2 0 2 2 2 2 2 2 2 2)
    int min = find_min(a,0,N-1);
    cout << "The minimum element in the array is: " << min << endl;

    int min1 = find_min_dup(a,0,N-1);
    cout << "The minimum element in the array with duplicates is: " << min1 << endl;

}
