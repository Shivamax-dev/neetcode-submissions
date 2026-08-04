class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;

        // Process nums2 to precompute the next greater element for each number
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Map elements from nums1 to their next greater element
        vector<int> result;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                result.push_back(next_greater[num]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
        
    }
};