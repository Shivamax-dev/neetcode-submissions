class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int res1 = -1, res2 = -1;
        // Find the first position (leftmost)
        while(low <= high){
            int guess = (low + high)/2;
            
            if(nums[guess] < target){
                low = guess + 1;
            }else if(nums[guess] > target){
                high = guess - 1;
            }else{
                res1 = guess;
                high = guess - 1;
            }
        }
        //Reset search space for the second search, Find the last position (rightmost)
        low = 0;
        high = n - 1;
        while(low <= high){
            int guess = (low + high)/2;
            
            if(nums[guess] < target){
                low = guess + 1;
            }else if(nums[guess] > target){
                high = guess - 1;
            }else{
                res2 = guess;
                low = guess  + 1; // keep searching right
            }
        }
        return {res1, res2};
        
    }
};