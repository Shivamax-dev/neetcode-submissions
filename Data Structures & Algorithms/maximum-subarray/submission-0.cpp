class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int max_sum = nums[0];  //max_sum is best ending in current situation

        for(int i = 1; i < nums.size(); i++){
            int val1 = max_sum + nums[i];
            int val2 = nums[i];

            max_sum = max(val1, val2);
            ans = max(ans, max_sum);
        }
        return ans;

    }
};
