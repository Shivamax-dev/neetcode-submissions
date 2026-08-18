class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  //Minheap
        int n = nums.size();
        int i;
        for(i = 0; i < k; i++){  //log(k)
            pq.push(nums[i]);
        }
        for(i = k; i < n; i++){ //(n-k){O(logk) + O(logk)} = O(nlogk)
            if(nums[i] <= pq.top())
                continue;
            pq.pop();
            pq.push(nums[i]); 
        }
        return pq.top();

    }

};
//Time complexity: O(nlogk)
//Space complexity: O(k)
