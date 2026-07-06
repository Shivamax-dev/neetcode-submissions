class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr1 = 0, res = 1, ptr2 = 1;
        int n = nums.size();
        while(ptr2 < n){
            if(nums[ptr2] == nums[ptr2 - 1]){
                ptr2++;
                continue;
            }
            //Unique element found in given array then
            nums[ptr1 + 1] = nums[ptr2];
            ptr1++;
            res++;
            ptr2++;
        }
        return res;
        
    }
};