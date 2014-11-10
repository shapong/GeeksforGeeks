#include <iostream>
#include <algorithm>

using namespace std;

typedef struct pair_struct {
    int first;
    int second;
    int sum;
} pairs;

bool my_compare(const pairs p1, const pairs p2) {
    return (p1.sum < p2.sum) ? true : false;
}

void find_sum(int* a, int n, int sum) {

    int size = (n*(n-1))/2,ind=0;
    pairs* aux = new pairs[size];

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            aux[ind].first = i;
            aux[ind].second = j;
            aux[ind].sum = a[i] + a[j];
            ind++;
        }
    }

    sort(aux,aux+size,my_compare);

    int l=0,r=size-1;
    while(l < r) {
        if(aux[l].sum+aux[r].sum < sum) l++;
        else if(aux[l].sum+aux[r].sum > sum) r--;
        else {
            if(aux[l].first != aux[r].first && aux[l].first != aux[r].second &&
               aux[l].second != aux[r].first && aux[l].second != aux[r].second)
               cout << "The 4 numbers are: " << a[aux[l].first] << " " << a[aux[l].second] << " " << a[aux[r].first] << " " << a[aux[r].second] << endl;
            return;
            //l++; r--;
        }
    }
    cout << "No such sum" << endl;
}

int main() {

    int N,sum;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "What sum are you looking for?" << endl;
    cin >> sum;

    find_sum(a,N,sum);
}
