#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int p, q;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j++)
            {
                if (nums[j] < nums[i])
                {
                    swap(nums[j], nums[i]);
                    p = i;
                    q = j;
                }
            }
        }
        if (p == 0 && q == 0)
            sort(nums.begin(), nums.end());
        return;
    }
};

int main()
{
	return 0;
}