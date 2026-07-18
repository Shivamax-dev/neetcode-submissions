class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0;
        int sum = 0;
        int res = INT_MAX;  //Minimum length

        for (high = 0; high < n; high++) {
            sum += nums[high];

            // shrink window while valid
            while (sum >= target) {
                int len = high - low + 1;
                res = min(res, len);
                sum -= nums[low];
                low++;
            }
        }
        if(res == INT_MAX){
            return 0;
        }
        return res;
        
    }
};