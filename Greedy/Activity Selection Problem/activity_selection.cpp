#include <iostream>
#include <algorithm>

using namespace std;

typedef struct activity_desc {
    int start;
    int finish;

} activity;

bool compare (const activity a1, const activity a2) {
    return (a1.finish < a2.finish) ? true : false;
}

void select_activities(activity* set, int n) {

    sort(set,set+n,compare);
    cout << "Activity 0: " << set[0].start << " " << set[0].finish << endl;
    int curr_start = set[0].finish;
    for(int i=1;i<n;i++) {
        if(set[i].start >= curr_start) {
            cout << "Activity " << i << ": " << set[i].start << " " << set[i].finish << endl;
            curr_start = set[i].finish;
        }
    }

}

int main () {

    int N;
    cout << "How many activities do you want to enter?" << endl;
    cin >> N;
    cout << "Enter start times" << endl;
    activity* set = new activity[N];
    for(int i=0;i<N;i++)
        cin >> set[i].start;
    cout << "Enter finish times" << endl;
    for(int i=0;i<N;i++)
        cin >> set[i].finish;

    select_activities(set,N);

}
