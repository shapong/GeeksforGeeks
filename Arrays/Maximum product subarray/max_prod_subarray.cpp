#include <iostream>

using namespace std;

int max_prod_subarray(int* a, int n) {

    int max_ending_here=1,min_ending_here=1,max_so_far=1,temp;

    for(int i=0;i<n;i++) {

        if(a[i] > 0) {
            max_ending_here = max_ending_here*a[i];
            min_ending_here = min(min_ending_here*a[i],1);
        }

        else if(a[i]==0)
            max_ending_here = min_ending_here = 1;

        else {
            temp = max_ending_here;
            max_ending_here = max(min_ending_here*a[i],1);
            min_ending_here = temp*a[i];
        }

        if(max_ending_here > max_so_far)
            max_so_far = max_ending_here;

    }

    return max_so_far;
}

int main() {

    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];


    cout << "The maximum subarray product of the array is:" << endl;
    cout << max_prod_subarray(a,N) << endl;

}
