#include <iostream>

using namespace std;

int f(int x) {
    return (x*x - 10*x - 20);
}

int binary_search(int low, int high) {
    if(low==high) return low;
    int mid = (low+high)/2;

    if(f(mid)>0 && (f(mid-1)<=0 || mid==low)) return mid;

    if(f(mid)<=0) return binary_search(mid+1,high);
    else return binary_search(low,mid-1);

    return -1;

}

int find_pos_ind() {

    if(f(0) > 0) return 0;
    int high,x=1;
    while(f(x)<=0) x *= 2;

    high = x;
    return binary_search(1,high);

}

int main() {

    cout << find_pos_ind() << endl;
}
