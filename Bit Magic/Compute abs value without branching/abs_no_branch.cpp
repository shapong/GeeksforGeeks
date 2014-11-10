#include <iostream>

using namespace std;

int ABS(int n) {

    ///~n + 1 for negative numbers only returns abs value...
    int mask = n >> 31;
    cout << mask << endl;
    return ((mask+n)^mask);

}

int ABS2(int n) {

    int mask = n >> 31;
    return ((mask^n)-mask);

}

int main() {

    int N;
    cin >> N;

    cout << "The absolute value of the number is:" << endl;
    cout << ABS(N) << endl;
    cout << "Again...the abs is:" << endl;
    cout << ABS2(N) << endl;

}
