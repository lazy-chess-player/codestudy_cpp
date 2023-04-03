#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 1; i < points.size(); i++) 
        {
            ans = max(points[i][0] - points[i - 1][0], ans);
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>> arr = { {3,1} ,{9,0},{1,0},{1,4},{5,3},{8,8} };
    cout << s1.maxWidthOfVerticalArea(arr) << endl;
}