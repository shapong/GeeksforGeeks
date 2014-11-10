#include <iostream>
#include <algorithm>

using namespace std;

int LCS(string& s, string& s1) {

    int n=s.length(),m=s1.length(),max=0;
    int** lcs = new int*[n];
    for(int i=0;i<m;i++) lcs[i] = new int[m];

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i]==s1[j]) {
                if((i-1) >= 0 && (j-1) >= 0)
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = 1;
            }
            else {
                if((i-1) >= 0 && (j-1) >= 0) lcs[i][j] = std::max(lcs[i-1][j],lcs[i][j-1]);
                else if(i==0 && j==0) lcs[i][j] = 0;
                else if(j==0) lcs[i][j] = lcs[i-1][j];
                else if(i==0) lcs[i][j] = lcs[i][j-1];
            }
            if(lcs[i][j] > max) max = lcs[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }
    return max;

}

int main() {

    string s,s1;
    cout << "Enter two strings:" << endl;
    cin >> s >> s1;

    cout << "The length of the longest common subsequence is:" << endl;
    cout << LCS(s,s1) << endl;
}
