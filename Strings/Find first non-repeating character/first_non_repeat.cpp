#include <iostream>

using namespace std;

char first_non_repeat(string& s) {

    char m[256] = {0};
    for(int i=0;i<s.length();i++)
        m[s[i]]++;

    for(int i=0;i<s.length();i++) {
        if(m[s[i]]==1) return s[i];
    }

    return '\0';

}

int main() {

    string str;
    cin >> str;

    cout << "The first non-repeating character in the string is:" << endl;
    cout << first_non_repeat(str) << endl;

}
