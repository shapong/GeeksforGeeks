#include <iostream>

using namespace std;

int find_min_dist(int* a, int e1, int e2, int n) {

    int prev = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == e1 || a[i] == e2) {
            prev = i;
            break;
        }
    }

    int min_dist = n-1,temp=prev;
    for(int i=temp+1;i<n;i++) {
        if(a[i]==e1 || a[i]==e2) {
            if(a[i]==a[prev]) {
                prev = i;
            }
            else {  //it equals e2...
                if(i-prev < min_dist) {
                    min_dist = i - prev;
                    prev = i;
                }
            }
        }
    }

    return min_dist;


}

int main() {

    int N,e1,e2;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++) cin >> a[i];

    cout << "Enter two elements you want to find the distance between?" << endl;
    cin >> e1 >> e2;
    int dist = find_min_dist(a,e1,e2,N);
    cout << "The distance between " << e1 << " and " << e2 << " is: " << dist << endl;

}
