class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> have;
        unordered_map <char, int> need;

        for(int i = 0; i < ransomNote.length(); i++){ // to store frequency of every character in ransoimeNote string
            need[ransomNote[i]]++;
        }
        for(int i = 0; i < magazine.length(); i++){ // to store frequency of every character in magazine string
            have[magazine[i]]++;
        }

        for(auto i: need){ //to loop the characters of the ransomNode hashmap.
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            if(fhave < fneed){
                return false;
            }
            
        }

    return true;    
        
    }
};