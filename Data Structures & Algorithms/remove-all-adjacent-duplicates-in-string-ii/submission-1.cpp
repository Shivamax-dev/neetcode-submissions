class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        // Stack to store pairs of {character, consecutive_count}
        stack<pair<char, int>> st;

        for(int i = 0; i < n; i++){
            char c = s[i];
            //Stack is empty, push new character with count 1
            if(st.empty()){
                st.push({c, 1});
                continue;
            }
            //Current character differs from the stack top, push new entry
            if(st.top().first != c){
                st.push({c, 1});
                continue;
            }
            //Same character, but count is less than k - 1; increment count
            if(st.top().second < (k-1)){
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first, p.second + 1});
                continue;
            }
            //Reached k consecutive characters; remove the group from stack
            st.pop();
        }
        // Reconstruct result string from the stack
        string res = "";
        while(!st.empty()){
            pair<char, int> p = st.top();
            st.pop();
            // Append character 'count' number of times
            while(p.second--){
                res.push_back(p.first);
            }
        }
        //// Reverse to restore original character order (stack processes right-to-left)
        reverse(res.begin(), res.end());
        return res;
        
    }
};