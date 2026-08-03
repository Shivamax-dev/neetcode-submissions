class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            st.push(s[i]);
        }
        vector<char> res;
        while(!st.empty()){     //Jb tkk stack khali n ho jaye tb tk
            char c = st.top();
            st.pop();
            res.push_back(c);
        }
        s = res;
    }
};