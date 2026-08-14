class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high){
            int guess = (low + high)/2;
            if(nums[guess] == target){
                return guess;
            }
            //part 1 {where the bigger elements of the arrays are present}
            if(nums[guess] > nums[n-1]){
                if(nums[guess] < target){
                    low = guess + 1; //right
                }else{
                    if(nums[0] > target){
                        low = guess + 1;  //right (target must be in the smaller segment)
                    }else{
                        high = guess -1;  //left
                    }
                }
            }
            //Part 2 {where the relatively smaller elements of the arrays are present than in the part 2}
            else{
                if(nums[guess] > target){
                    high = guess - 1;  // left
                }else{
                    if(nums[n-1] < target){
                        high = guess - 1;   // left
                    }else{ // Target is within this segment to the right
                        low = guess + 1; //right
                    }
                }
            }
        }
        return -1;
        
    }
};
