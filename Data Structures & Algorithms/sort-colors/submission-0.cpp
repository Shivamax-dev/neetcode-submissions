class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }else if(nums[mid] == 1){
                mid++; // Do not swap as 1 is already in correct section
            }else{
                swap(nums[mid], nums[high]);
                high--; //Here mid is not incremented as swapped element from "high" needs to be evaluated next
            }
        }
        
    }
};