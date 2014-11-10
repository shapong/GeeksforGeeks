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

long int multiplyBitStrings(string s1, string s2) {

    int n = makeEqualLength(s1,s2);

    if(n==1) return (s1[0] - '0')*(s2[0]-'0');

    ///for any length bit string we get floor(of first half) & celling(of second half)
    ///number of bits for the first left half and the second right half
    int l = n/2;
    int r = n-l;

    string xl = s1.substr(0,l);
    string xr = s1.substr(l,r);

    string yl = s2.substr(0,l);
    string yr = s2.substr(l,r);

    long int M1 = multiplyBitStrings(xl,yl);
    long int M2 = multiplyBitStrings(addBitStrings(xl,xr),addBitStrings(yl,yr));
    long int M3 = multiplyBitStrings(xr,yr);

    return M1*(1<<(2*r)) + (M2 - M1 - M3)*(1<<r) + M3;

}

int main () {

    string s1,s2;
    cin >> s1 >> s2;

    long int ans = multiplyBitStrings(s1,s2);

    cout << "The product of the two bit strings is: " << ans << endl;

}
