class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> f; //hashmap
        f[0] = 1; //Base case: prefix sum of 0 has occurred once
        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int ques = sum - k;
            res = res + f[ques];   //updating the res with the frquency of "sum - k" or "k"
            f[sum]++;  /// Store the frequency of the CURRENT prefix sum
        }
        return res;
    }
};