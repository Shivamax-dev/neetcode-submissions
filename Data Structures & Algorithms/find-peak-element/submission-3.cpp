class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;  //start = low and end = high

        while(start < end){
            int guess = (start + end)/2;
            if(nums[guess] < nums[guess + 1]){
                start = guess + 1;
            }else{   //when nums[guess] >= nums[guess + 1]
                //store the current value
                end = guess;
            }
        }
        return start;
        
    }
};