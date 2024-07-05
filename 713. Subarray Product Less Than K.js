#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int l = 0, r = 0; r < n; r++) {
            mp[nums[r]]++;
            if(mp[nums[r]] > k) {
                while(nums[l] != nums[r]) {
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Maximum subarray length with at most " << k << " distinct elements: " << sol.maxSubarrayLength(nums, k) << endl;
    return 0;
}
