#include <iostream>

using namespace std;

void find_matches(string& text, string& pat) {

    bool flag;
    for(int i=0;i<text.length();i++) {
        flag = true;
        for(int j=0;j<pat.length();j++) {
            if(text[i+j]!=pat[j]) flag = false;
        }
        if(flag) cout << "Pattern found at " << i << endl;
    }


}

int main() {

    string text;
    string pattern;
    cout << "Enter text:" << endl;
    getline(cin,text);
    cout << "Enter the pattern:" << endl;
    getline(cin,pattern);

    find_matches(text,pattern);

}
