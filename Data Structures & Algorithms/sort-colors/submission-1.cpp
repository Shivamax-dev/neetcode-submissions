class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        int n = nums.size();
        int id  = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                zero++;
            }else if(nums[i] == 1){
                one++;
            }else{
                two++;
            }
        }

        while(zero != 0){
            nums[id] = 0;
            id++;
            zero--;
                
        }
        while(one != 0){
            nums[id] = 1;
            id++;
            one--;
                
        }   
        while(one != 0){
            nums[id] = 1;
            id++;
            one--;
                
        }
        while(two != 0){
            nums[id] = 2;
            id++;
            two--;
        }        
        
    }
};