#include <iostream>
#include <sstream>

using namespace std;

void reverse_words_and_sent(string& s) {

    int left,right;
    string temp;
    istringstream ss(s);
    while(ss >> temp) {
        cout << temp << " ";
        left = 0; right = temp.length();
        while(left < right) {
            swap(temp[left],temp[right]);
            left++;
            right--;
        }
        cout << temp << " ";
    }

    /*while(left < right) {
        swap(s[left],s[right]);
        left++;
        right--;
    }*/

}

int main() {

    string str;
    getline(cin,str);

    reverse_words_and_sent(str);
    //cout << str << endl;

}
