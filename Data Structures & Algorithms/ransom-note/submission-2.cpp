class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
        
        // Count frequency of each character in magazine
        for (char c : magazine) {
            count[c]++;
        }
        
        // Check if magazine has enough characters for ransomNote
        for (char c : ransomNote) {
            if (count[c] <= 0) {
                return false;
            }
            count[c]--;
        }
        
        return true;
        
    }
};