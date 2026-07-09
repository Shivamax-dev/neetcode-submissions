class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        //Sorting the given array
        sort(nums.begin(), nums.end());

        //find the 2 sum for each element of array
        for(int i = 0; i < n-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]){ //skiping the duplicate values for i for unique triplets
            continue;
            }
            //Initializing 2 pointer
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];  //nums[left] + nums[right] + nums[i] = 0

            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){      //triplet found now push
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for 'left' and 'right' pointers
                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right--;
                    } 
                    left++;
                    right--;


                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }

        }
        return result;
    }
    
};
