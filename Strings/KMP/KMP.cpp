#include <iostream>
#include <cstdio>

using namespace std;

int KMP(string& pat, string& s) {

    int* lps = new int[pat.size()];

    int i=1,len=0;
    lps[0] = 0;
    while(i < pat.size()) {
        if(pat[i]==pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len==0) {
                lps[i] = 0;
                i++;
            }
            ///find match for it in prev letters...
            else {
                len = lps[len-1];
            }
        }
    }

    for(int i=0;i<pat.size();i++) {
        cout << lps[i] << " ";
    }
    cout << endl;

}

int main() {

    string s,pat;

    cout << "Enter Text" << endl;
    cin >> s;

    cout << "Enter a pattern:" << endl;
    cin >> pat;

    cout << KMP(pat,s) << endl;

}
