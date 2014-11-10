#include <iostream>
#include <cstdlib>

using namespace std;

bool isDigit(char s) {
    return (s - '0' >= 0 && s-'0' <= 9) ? true : false;
}

int myAtoi(const char* s, int N) {

    int result = 0;
    bool sign = false;
    for(int i=0;i<N;i++) {

        if(s[i]=='.') break;
        if(i!=0 && !isDigit(s[i])) return 0;

        if(i==0 && s[i]=='-') sign = true;
        else result = (result*10) + (s[i] - '0');
    }

    return (sign) ? -1*result : result;
}

int main() {

    string str;
    cin >> str;
    int atoi_ans = myAtoi(str.c_str(),str.length());

    int i = atoi(str.c_str());

    cout << "STDLIB atoi: " << i << endl;
    cout << atoi_ans << endl;

}
