#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getCountUtil(int x, int* y, int m, vector<int>& countY) {
    if(x==0) return 0;
    if(x==1) return countY[0];

    int* ind;
    ind = upper_bound(y,y+m,x);

    int ans;
    ans = (y + m) - ind;
    //cout << "count: " << ans << endl;

    ans += (countY[0] + countY[1]);
    if(x==2) ans = ans - (countY[3] + countY[4]);
    ///Even though 3 is greater than 2...3^2 > 2^3...
    else if (x==3) ans += countY[2];
    return ans;

}

int findPowerPairs(int* X, int n, int* Y, int m) {

    vector<int> countY(5,0);
    for(int i=0;i<m;i++) {
        if(Y[i] < 5)
            countY[Y[i]]++;
    }

    sort(Y,Y+m);
    int final_count=0;
    for(int i=0;i<n;i++) {
        final_count += getCountUtil(X[i],Y,m,countY);
    }
    return final_count;
}

int main() {

    int N,M;
    cout << "Enter 2 arrays <X> & then <Y>" << endl;

    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cin >> M;
    int* b = new int[M];
    for(int i=0;i<M;i++)
        cin >> b[i];

    cout << "The number of pairs where X^Y > Y^X are:" << endl;
    cout << findPowerPairs(a,N,b,M) << endl;

}
