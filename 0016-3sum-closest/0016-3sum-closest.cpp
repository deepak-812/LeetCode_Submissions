class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++){
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if (curSum == target) return curSum;
                if (abs(target - curSum) < abs(target - closest)) {
                    closest = curSum;
                }

                if (target < curSum) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return closest;
    }
};