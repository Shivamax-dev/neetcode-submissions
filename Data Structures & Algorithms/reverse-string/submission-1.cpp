class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            st.push(s[i]);
        }
        ////Pop characters back into the original vector 's'
        int i = 0;
        while (!st.empty()) {
            s[i] = st.top();
            st.pop();
            i++;
        }
        
    }
};