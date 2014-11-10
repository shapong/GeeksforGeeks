#include <iostream>
#include <vector>

using namespace std;

vector<int> find_union(int* a, int* b, int n, int m) {

    vector<int> u;
    int i =0,j=0,size=0;
    while(i < n && j < m) {
        size = u.size();
        if(a[i] < b[j]) {
            if((size!=0 && a[i] > u[size-1]) || size==0) {
                u.push_back(a[i]);
            }
            i++;
        }
        else if(a[i] > b[j]) {
            if((size!=0 && b[i] > u[size-1]) || size==0) {
                u.push_back(b[j]);
            }
            j++;
        }
        else {
            if((size!=0 && a[i] > u[size-1]) || size==0) {
                u.push_back(a[i]);
            }
            i++; j++;
        }
    }
    for(int k=i;k<n;k++) if(a[k] > u[u.size()-1]) u.push_back(a[k]);
    for(int k=j;k<m;k++) if(b[k] > u[u.size()-1]) u.push_back(b[k]);

    return u;

}

vector<int> find_intersect(int* a, int* b, int n, int m) {

    vector<int> inter;
    int i=0,j=0,size;
    while(i < n && j < m) {
        size = inter.size();
        if(a[i] < b[j]) {
            i++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
        else {
            if((size!=0 && a[i] > inter[size-1]) || size==0)
                inter.push_back(a[i]);
            i++; j++;
        }
    }

    return inter;

}

int main() {

    int N,M;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];
    cin >> M;
    int* b = new int[M];
    for(int i=0;i<M;i++)
        cin >> b[i];

    vector<int> u;
    u = find_union(a,b,N,M);
    cout << "The union of the two sets is: " << endl;
    for(int i=0;i<u.size();i++) cout << u[i] << " ";
    cout << endl;

    vector<int> intersect;
    intersect = find_intersect(a,b,N,M);
    cout << "The intersection of the two sets is: " << endl;
    for(int i=0;i<intersect.size();i++) cout << intersect[i] << " ";
    cout << endl;

}
