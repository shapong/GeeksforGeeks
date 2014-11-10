#include <iostream>
#include <map>
#include <list>

using namespace std;

multimap<int,int, less<int> >::iterator iter;
list<int>::iterator it,it1;
list<int> stack;    ///start times
list<int> stack1;   ///end times

void merge_intervals(multimap<int,int, less<int> >& m) {
    iter = m.begin();
    stack.push_front(m.begin()->first);
    stack1.push_front(m.begin()->second);
    iter++;
    for(;iter!=m.end();iter++){
        if(iter->first <= stack1.front()) {
            if(iter->second > stack1.front()){
                stack1.front() = iter->second;
            }
        }
        else {
            stack.push_front(iter->first);
            stack1.push_front(iter->second);
        }

    }

    //return stack;
}

int main() {

    int N,n1,n2;
    cin >> N;
    multimap<int,int, less<int> > intervals;
    for(int i=0;i<N;i++) {
        cin >> n1 >> n2;
        intervals.insert(make_pair(n1,n2));
    }

    //for(iter=intervals.begin();iter!=intervals.end();iter++)
    //    cout << iter->first << " " << iter->second << endl;

    merge_intervals(intervals);

    cout << "The merged intervals:" << endl;

    for(it=stack.begin(),it1=stack1.begin();it!=stack.end(),it1!=stack1.end();it++,it1++) {
        cout << *it << " " << *it1 << endl;
    }

}
