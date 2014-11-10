#include <iostream>

using namespace std;

int find_min(int * a) {

    int c=0;
    while(a[0]&& a[1] && a[2]) {
        a[0]--; a[1]--; a[2]--;
        c++;
    }
    return c;

}

int main()
{

    int * arr = new int[3];
    cout << "Enter three numbers" << endl;
    cin >> arr[0] >> arr[1] >> arr[2];

    ///Doesn't work for negative numbers...
    cout << "The minimum of the three numbers is: " << find_min(arr) << endl;

}
