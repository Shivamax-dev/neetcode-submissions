class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // vector <int> res;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int sum = nums[i] + nums[j];
                if(sum == target){
                    return {i, j};
                }
            }

        //     int left = i;
        //     int right = n-1;
        //     while(left < right){
        //         int sum = nums[left] + nums[right];

        //         if(sum == target){
        //             res = {left, right};
        //         }
        //         if(sum < target){
        //             left++;
        //         }
        //         else{
        //             right--;
        //         }
        //     }
        // }
        // return res;
        }
        return {};
    }
};