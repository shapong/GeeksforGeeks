#include <iostream>

using namespace std;

int makeEqualLength(string& s1, string& s2) {

    int len1 = s1.length(), len2 = s2.length();
    if(len1 < len2) {
        for(int i=0;i<len2-len1; i++)
            s1 = '0' + s1;
    }
    else if(len2 < len1) {
        for(int i=0;i<len1-len2; i++)
            s2 = '0' + s2;
    }
    //cout << s1 << " " << s2 << endl;
    return s1.length();
}

string addBitStrings(string& s1, string& s2) {

    string result;

    int len = makeEqualLength(s1,s2);
    //cout << s1 << " func.. " << s2 << endl;

    int carry = 0,sum=0,a,b;
    for(int i=len-1;i>=0;i--) {
        a = s1[i] - '0';
        b = s2[i] - '0';

        sum = (a ^ b ^ carry) + '0';

        result = (char)sum + result;

        carry = (a & b) | (a & carry) | (b & carry);
    }

    ///overflow bit means a 1 should be added at the beginning
    if(carry) result = '1' + result;

    return result;

}

int main() {

    string s1,s2,s3;
    cin >> s1 >> s2;

    s3 = addBitStrings(s1,s2);
    cout << "The addition of the two strings is: " << s3 << endl;

}
