#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std; 


typedef struct Interval {
    int i; 
    int begin; 
    int end; 
} interval; 

bool comp( interval a, interval b) {
    return a.begin < b.begin; 
} 

void schedule (int c, vector<interval> &activities ) {

    stack<Interval> cam; 
    stack<Interval> jam; 

    std::vector<char> schedule(activities.size()); 

    for( interval i: activities) {

        if ( cam.empty() ) {

            cam.push(i); 
            schedule[i.i] = 'C';
         
        } else if ( jam.empty() ) {

            jam.push(i);
            schedule[i.i] = 'J';
            
        } else {

            if ( cam.top().end <= i.begin ) {
                cam.push(i); 
                schedule[i.i] = 'C';  
            } else if (jam.top().end <= i.begin) {
                jam.push(i); 
                schedule[i.i] = 'J'; 
            } else {
                printf("Case #%d: IMPOSSIBLE\n", c);
                return; 
            }
        }
    }
    printf("Case #%d: ", c); 
    for ( char chr : schedule) {
        cout << chr; 
    }
    cout << endl; 
}

int main () {
    int t, n; 
    cin >> t;
    interval activity; 
    std::vector<interval> activities; 
    for(int c = 1; c <= t; c++) {
        cin >> n; 
        for (int j = 0; j < n; j++) {
            activity.i = j; 
            cin >> activity.begin >> activity.end; 
            activities.push_back(activity); 
        }
        sort(activities.begin(), activities.end(), comp); 

        schedule(c, activities);
        activities.clear(); 

    }
    return 0; 
}