#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,string>mp;
vector<pair<int, int> > vec;
bool comp(pair<int, int>  x, pair<int, int>  y)
{
    return x.second < y.second;
}
int main()
{
    int n;
    cin>>n; // Number of activities
    for(int i=0; i<n; i++)
    {
        string activity;
        int start,finish;
        cin>>activity>>start>>finish; // activity serial,start time,finish time;
        mp.insert(make_pair(make_pair(start,finish),activity));
        vec.push_back({start,finish});
    }
    sort(vec.begin(),vec.end(),comp);
    cout<<"Activity No: "<<mp[ {vec[0].first,vec[0].second}]<<", Start: "<<vec[0].first<<", Finish: "<<vec[0].second<<" "<<endl;
    int i=0,j=0;
    for(j=i+1; j<n; j++)
        if(vec[j].first>=vec[i].second) // if starting time of next activity is greater that finishing time of previous activity
        {
            cout<<"Activity No: "<<mp[ {vec[j].first,vec[j].second}]<<", Start: "<<vec[j].first<<", Finish: "<<vec[j].second<<" "<<endl; //then that activity can be selected
            i=j;
        }
    return 0;
}
/* 8
   a1 1 3
   a2 0 4
   a3 1 2
   a4 4 6
   a5 2 9
   a6 5 8
   a7 3 5
   a8 4 5
OUTPUT:
a3,a7,a6*/
