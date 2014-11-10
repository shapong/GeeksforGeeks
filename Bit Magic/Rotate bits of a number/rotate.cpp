#include <iostream>

using namespace std;

int left_rotate(int n, int rotate) {

    return ( (n << rotate) | (n >> (32-rotate)) );
}

int right_rotate(int n, int rotate) {

    return ( (n >> rotate) | (n << (32-rotate)) );
}

int main() {

    int num,rotate;
    cout << "Enter a number:" << endl;
    cin >> num;

    cout << "By how many bits do you want to rotate this number left & right?" << endl;
    cin >> rotate;

    cout << "The number rotated left is:" << endl;
    cout << left_rotate(num,rotate) << endl;

    cout << "The number rotated right is:" << endl;
    cout << right_rotate(num,rotate) << endl;

}
