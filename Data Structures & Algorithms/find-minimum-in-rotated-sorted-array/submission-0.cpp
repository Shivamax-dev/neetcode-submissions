class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            if(nums[guess] > nums[n-1]){    //part 2
                low = guess + 1;
            }else{  //(nums[guess] <= nums[n-1])  ..///part 1
                res = guess;  //store it
                high = guess - 1;

            }
        }
        return nums[res];   //Minimum element
        
    }
};
