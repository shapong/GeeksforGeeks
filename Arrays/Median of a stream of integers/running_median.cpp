#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstdlib>

using namespace std;

float running_median(vector<int>& stream, int em, priority_queue<int, vector<int>, less<int> >& small, priority_queue<int, vector<int>, greater<int> >& large) {

    int num = stream[stream.size()-1];
    if (num < em) small.push(num);
    else large.push(num);
    int diff = large.size() - small.size();
    ///small is a max heap where the numbers are smaller than the median
    int temp;
    if(abs(diff) == 1) {
        return (large.size() > small.size()) ? large.top() : small.top();
    }
    else if(diff==0) {
        return (large.top()+small.top())/2.0;
    }
    else {
        if(diff > 0) {
            temp = large.top();
            large.pop();
            small.push(temp);
        }
        else {
            temp = small.top();
            small.pop();
            large.push(temp);
        }
        return (large.top()+small.top())/2.0;
    }

}

int main () {

    int N,num;
    float effective_median;
    cout << "How many intergers do you want to enter?" << endl;
    cin >> N;
    vector<int> stream;
    priority_queue<int, vector<int>, greater<int> > larger; //ordered least...to...greatest...MIN HEAP
    priority_queue<int, vector<int>, less<int> > smaller;
    for(int i=0;i<N;i++) {
        cin >> num;
        stream.push_back(num);
        effective_median = running_median(stream,effective_median,smaller,larger);
        cout << "The median so far is: " << effective_median << endl;
    }
}
