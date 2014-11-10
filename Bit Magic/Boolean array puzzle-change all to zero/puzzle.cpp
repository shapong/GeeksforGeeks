#include <iostream>

using namespace std;

void changeToZeros(int* a)
{
    a[ a[1] ] = a[ !a[1] ];
    //lhs tells the location of 1...
    //1 0 a[0] = a[1]
    //0 1 a[1] = a[0]
}

void method2(int* a)
{
    a[ a[1] ] = a[ a[0] ];
    //1 0 a[0] = a[1]
    //0 1 a[1] = a[0]
}

void method3(int* a)
{
    a[ !a[0] ] = a[ !a[1] ];
    //1 0 a[0] = a[1]
    //0 1 a[1] = a[0]
}

int main()
{

    int * arr = new int[2];

    ///It is important that the indices are opposites...
    cout << "Enter two numbers (either 1 or 0)" << endl;
    cin >> arr[0] >> arr[1];
    changeToZeros(arr);
    method2(arr);

    cout << "The array is: " << arr[0] << " and " << arr[1] << endl;

}
