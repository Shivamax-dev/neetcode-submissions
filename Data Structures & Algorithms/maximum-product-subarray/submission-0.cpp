class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int max_end = nums[0];   //ith index pe max product batane wala
        int min_end = nums[0];   //ith index pe minimum product batane wala  


        for(int i = 1; i < nums.size(); i++){
            int val1 = max_end * nums[i];
            int val2 = min_end * nums[i];
            int val3 = nums[i];

            max_end = max(max(val1, val2), val3);
            min_end = min(min(val1, val2), val3);

            res = max(max_end, res);
        }
        return res;  //res = max(max(max_end, min_end), res);
    }
};
