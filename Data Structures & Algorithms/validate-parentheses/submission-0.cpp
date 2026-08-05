class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);  // Push opening brackets onto the stack
            }else{

                if(st.empty()){ // If stack is empty, there is no matching opening bracket
                    return false;
                }
                
                if((s[i] == ')' and st.top() == '(') ||
                (s[i] == '}' and st.top() == '{' ) ||
                (s[i] == ']' and st.top() == '[' )){
                    st.pop();
                }
                else{       // Mismatched bracket types
                    return false;
                }
            }
        }
        return st.empty();  
        
    }
};
