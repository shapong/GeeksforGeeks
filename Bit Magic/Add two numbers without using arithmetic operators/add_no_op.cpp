#include <iostream>

using namespace std;

int Add(int x, int y) {

    if(y==0) return x;

    return Add(x^y,(x&y) << 1);

}

int add_again(int n1, int n2) {

    int carry;
    while(n2!=0) {
        carry = n1 & n2;
        n1 = n1 ^ n2;
        n2 = carry << 1;
    }

    return n1;

}

int main () {

    int num1,num2;
    cout << "Enter two numbers you want to add:" << endl;
    cin >> num1 >> num2;

    cout << "Their sum is: " << Add(num1,num2) << endl;

    cout << "Again their sum is: " << add_again(num1,num2) << endl;

}
