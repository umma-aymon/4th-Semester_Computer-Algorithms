#include <bits/stdc++.h>
using namespace std;
vector< pair<int, int> > vec;
bool comp(pair<int, int> x, pair<int, int> y)
{
    return x.second * y.first > x.first * y.second;
}
int main()
{
    int i, n, max_weight;
    cin >> n >> max_weight;
    for (i = 0; i < n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        vec.push_back(make_pair(weight, value));
    }
    // vec.resize(n);
    sort(vec.begin(), vec.end(), comp);
    //for(auto el:vec)
      //  cout<<el.first<<" "<<el.second<<endl;
    float total_weight=0, total_value=0;
    for (i = 0; i < n; i++)
        if(vec[i].first+total_weight<=max_weight)
        {
            total_weight+=vec[i].first;
            total_value+=vec[i].second;
        }
        else
        {
            int z=max_weight-total_weight;
            total_weight+=z;
            total_value+=z*((float)(vec[i].second)/vec[i].first);;
        }
    cout << "Total weight taken: " << total_weight << "\nValue of knapsack:  " << total_value;
    return 0;
}
/* 6
1 20
2 5
3 10
8 40
15 7
25 4
10
Total weight taken: 9
Value of knapsack:  60*/
