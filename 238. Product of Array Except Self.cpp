#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int subArray_length = 0;
        for (int i = 0; i < n; i++) {
            cout << "Enter element " << i << ": ";
            cin >> nums[i];
            sum += nums[i] == 0 ? -1 : 1; 
            if (sum == 0) {
                subArray_length = i + 1;
            } else if (mp.find(sum) != mp.end()) {
                subArray_length = max(subArray_length, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return subArray_length;
    }
};

int main() {
    Solution obj;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> nums(size);
    int maxLength = obj.findMaxLength(nums);
    cout << "Max length of contiguous subarray with equal number of 0s and 1s: " << maxLength << endl;
    return 0;
}
