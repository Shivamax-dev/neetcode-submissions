class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int guess = (low + high) / 2;

            if (nums[guess] == target) {
                return guess;
            }

            // 'guess' is in the left (larger) sorted portion
            if (nums[guess] > nums[n - 1]) {
                // target is strictly to the left of 'guess'
                if (target >= nums[0] && target < nums[guess]) {
                    high = guess - 1;
                } else {
                    low = guess + 1;
                }
            }
            // 'guess' is in the right (smaller) sorted portion
            else {
                // target is strictly to the right of 'guess'
                if (target > nums[guess] && target <= nums[n - 1]) {
                    low = guess + 1;
                } else {
                    high = guess - 1;
                }
            }
        }

        return -1;
    }
};
