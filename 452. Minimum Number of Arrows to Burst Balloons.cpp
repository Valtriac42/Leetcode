#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<int> newInterval = points[0];
        int ans = 1;
        for(int i=1;i<points.size();i++)
        {
            if( newInterval[1] >= points[i][0])
            {
                newInterval[0] = min(newInterval[0],points[i][0]);
                newInterval[1] = min(newInterval[1],points[i][1]);
            }
            else{
                ans++;
                newInterval = points[i];
            }
        }
     
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of balloons: ";
    cin >> n;
    vector<vector<int>> balloons(n, vector<int>(2));
    cout << "Enter the coordinates of balloons (start and end points):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> balloons[i][0] >> balloons[i][1];
    }
    Solution obj;
    cout << "Minimum number of arrows required: " << obj.findMinArrowShots(balloons) << endl;
    return 0;
}
