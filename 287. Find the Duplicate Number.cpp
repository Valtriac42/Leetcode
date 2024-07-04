#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define faster                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);            \
  cout.tie(nullptr);

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        faster
        int n = nums.size();
        int arr[100000+ 10];
        memset(arr,0,sizeof arr);
        for(int i = 0;i<n;i++)
        {
            arr[nums[i]]++;
            if(arr[nums[i]] > 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Duplicate element in the array is: " << sol.findDuplicate(nums) << endl;
    return 0;
}
