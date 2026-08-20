class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        // Step 1: Frequency map banana
        unordered_map<char, int> f;
        for (int i=0; i<n; i++) {
            f[s[i]]++;
        }

        // Step 2: Max Heap (Priority Queue of pairs: {frequency, character})
        priority_queue<pair<int, char>> pq;
        for (auto i : f) {
            pq.push({i.second, i.first});
        }

        string res = "";
        int seat = 0;

        // Step 3: Loop tab tak chalana jab tak saare characters place na ho jayein
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();

            // Check karo kya hum current character ko is seat pe baitha sakte hain
            if (seat == 0 || res[seat - 1] != p.second) {
                // Character ko result string mein add karo
                res.push_back(p.second);
                seat++;
                p.first--;
                if (p.first > 0) { // Agar abhi bhi is character ki frequency bachi hai to wapas push karo
                    pq.push(p);
                }
            } 
            else { // Agar same character repeat ho raha hai to second most frequent element chahiye
                if (pq.empty()) {
                    // Agar koi aur character bacha hi nahi to rearrange karna impossible hai
                    return "";
                }
                pair<int, char> p2 = pq.top();
                pq.pop();
                // Second character ko baithao
                res.push_back(p2.second);
                seat++;
                p2.first--;
                // Agar p2 bacha hai to heap mein wapas daalo
                if (p2.first > 0) {
                    pq.push(p2);
                }
                // Pehle wale character (p) ko bina frequency ghataye wapas daalo
                pq.push(p);
            }
        }

        return res;
        
    }
};