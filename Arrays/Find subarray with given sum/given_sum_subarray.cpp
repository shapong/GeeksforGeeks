#include <iostream>

using namespace std;

void find_subarray(int* a, int n, int sum) {

    if(n<=0) return;
    int curr_sum = a[0],start=0;
    for(int i=1;i<=n;i++) {

        //remove starting elements till curr_sum < sum
        while(curr_sum > sum && start < i) {
            curr_sum = curr_sum - a[start];
            start++;
        }

        if(curr_sum==sum) {
            cout << "The subarray with the given sum " << sum << " is from " << start << " to " << i-1 << endl;
            return;
        }

        if(i!=n) curr_sum += a[i];
    }

    cout << "There is no subarray with sum: " << sum << endl;
    return;


}

int main() {

    int N,sum;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Enter a sum:" << endl;
    cin >> sum;

    find_subarray(a,N,sum);

}
