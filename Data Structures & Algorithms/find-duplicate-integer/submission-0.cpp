class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0; //Initializing 2 pointer and store the first index(head) of the array in this
        while(fast != nums.size()){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow == fast){   //for sure there is cycle as a duplicate number is present
                slow = 0;
                while(slow != fast){
                    slow = nums[slow];  //traversing a step at a time for both slow and fast pionter
                    fast = nums[fast];
                }
                return slow; // OR return fast;
            }
        }
        return -1;   
        
    }
};
