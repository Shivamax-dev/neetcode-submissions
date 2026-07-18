class Solution {
public:
    bool fun(vector<int> &have, vector<int> &need){
        for(int i=0;i<256;i++){
            if(have[i]<need[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n)
            return "";   //Edge case
//We have to find the minimum window substring of s such that every character  
// in t is included in that window
        vector<int> have(256,0);  //have = s string
        vector<int> need(256,0);  //need = t string

        int i;
        for(i=0; i < n; i ++){
            need[t[i]]++;
        }

        int left = 0, right = 0;
        int res = INT_MAX;
        int start = -1;
         
        for(right = 0; right < m; right++){
            have[s[right]]++;
            
            while(fun(have, need)) // jab tk sahi hai
            {
                int len = right - left + 1;
                if(res > len){
                    res = len;
                    start = left;
                }

                have[s[left]]--;
                left++;
            }

        }
        if(res==INT_MAX)  //2nd edge case
            return "";
        return s.substr(start,res);
       
    }
};
