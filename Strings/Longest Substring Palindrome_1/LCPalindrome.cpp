#include <iostream>
#include <string>

using namespace std;

int LCP(string& s) {

    int n = s.length();
    bool** table = new bool*[n];
    for(int i=0;i<n;i++) table[i] = new bool[n];

    int max_length = 1;
    for(int i=0;i<n;i++) table[i][i] = true;

    int start_ind=0;
    for(int i=0;i<n-1;i++) {
        if(s[i]==s[i+1]) {
            table[i][i+1] = true;
            max_length = 2;
            start_ind = i;
        }
    }

    int end=0;
    for(int k=3;k<=n;k++) {
        for(int start=0;start<n-k+1;start++) {
            end = start+k-1;
            if(s[start]==s[end] && table[start+1][end-1]) {
                table[start][end] = true;
                if(k > max_length) {
                    start_ind = start;
                    max_length = k;
                }
            }
            else table[start][end] = false;
        }
    }

    cout << "The longest palindrome substring is:" << endl;
    cout << s.substr(start_ind,max_length) << endl;
    return max_length;

}

int main() {

    string s;
    cout << "Enter a string" << endl;
    cin >> s;

    cout << "What is the longest substring palindrome?" << endl;
    cout << LCP(s) << endl;

}
