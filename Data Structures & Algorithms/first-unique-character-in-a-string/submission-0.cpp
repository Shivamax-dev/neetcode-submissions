class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char, int> f;
        int i;
        //Counting the frequency of every character with a count of 1
        for(i = 0; i < n; i++){
            f[s[i]]++;
        }
        //Index of the first character with a count of 1
        for(i = 0; i < n; i++){
            if(f[s[i]] == 1){
                return i;
            }
        }
       return -1; 
    }
};