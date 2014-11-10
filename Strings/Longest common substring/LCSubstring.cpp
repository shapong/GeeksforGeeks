#include <iostream>

using namespace std;

int LCS(string& s, string& s1) {

    int n = s.length(),m=s1.length(),max=0;
    int** lcs = new int*[n];
    for(int i=0;i<n;i++) lcs[i] = new int[m];

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i]==s1[j]) {
                //cout << s[i] << endl;
                if((i-1) >= 0 && (j-1) >= 0)
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = 1;
            }
            else lcs[i][j] = 0;
            if(lcs[i][j] > max) max = lcs[i][j];
        }
    }

    return max;
}

int main() {

    string s1,s;
    cout << "Enter two strings:" << endl;
    cin >> s1 >> s;

    ///Continuous.....
    cout << "The longest common substring is of length:" << endl;
    cout << LCS(s1,s) << endl;

}
