class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char, int> f;
        for(int i = 0; i < s.length(); i++){
            f[s[i]]++;
        }
        bool odd = false; //initialize no. of odds is false
        int res = 0;
        for(auto i : f){
            int val = i.second;
            if(val % 2 == 0){
                res = res + val;
            }
            else{   //when there is frequncy of character is odd
                odd = true;
            }
        }
        if(odd == false){
            return res;     //agr sirf even frequency wale hi character ahi to result return krdo
        }
        for(auto i : f){
            int val = i.second;
            if(val % 2 == 1){
                res = res + val -1;
            }
        }
        return res + 1;
        
    }
};