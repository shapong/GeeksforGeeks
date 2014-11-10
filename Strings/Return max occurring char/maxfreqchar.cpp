#include <iostream>
#include <string>

using namespace std;

char getMaxFreqChar(string& s) {

    int count[256] = {0};
    for(int i=0;i<256;i++) count[i] = 0;
    for(int i=0;i<s.length();i++)
        count[s[i]]++;

    char max_c;
    int max=0;
    for(int i=0;i<256;i++) {
        if(count[i] > max && char(i)!=' ') {
            max_c = i;
            max = count[i];
        }
        //if(count[i] > 0) cout << char(i) << endl;
    }
    return max_c;

}

int main() {

    string s;
    cout << "Enter a string:" << endl;
    getline(cin,s);
    cout << "The string: " << s << endl;

    cout << "The maximum occuring character in the string is:" << endl;
    cout << getMaxFreqChar(s) << endl;

}
