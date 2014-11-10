#include <iostream>
#include <string>

using namespace std;

int LSP(string& s) {

    int len = s.length();

    int max_len = 1,low,high,start=0;
    for(int i=1;i<len-1;i++) {
        if(len%2==1) {
            low = i-1; high=i+1;
            while(s[low]==s[high] && low >= 0 && high < len) {
                if(high-low+1 > max_len) {
                    max_len = high-low+1;
                    start = low;
                }
                low--; high++;
            }
        }
        else {
            low = i; high=i+1;
            while(low >= 0 && high < len && s[low]==s[high]) {
                if(high-low+1 > max_len) {
                    max_len = high-low+1;
                    start = low;
                }
                low--; high++;
            }
        }
    }
    cout << "The longest substring palindrome is:" << endl;
    cout << s.substr(start,max_len) << endl;
    return max_len;
}

int main() {

    string s;
    cout << "Enter a string:" << endl;
    cin >> s;

    cout << "The length of the longest substring palindrome is:" << endl;
    cout << LSP(s) << endl;

}
