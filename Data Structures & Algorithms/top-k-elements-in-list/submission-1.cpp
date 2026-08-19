class Solution {
public:
    struct cmp{ //Comparator
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            //Min heap on first, Min on second in pair
            if(a.first == b.first){
                return a.second > b.second; //minheap
            }else{
                return a.first > b.first; //minheap based on frequency
            }
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> f;   //Hashmap to store the frequency of element
        for(int i = 0; i < n; i++){
            f[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(auto i: f){
            int element = i.first;
            int freq = i.second;
            pair<int, int> curr = {freq, element};  //Ek pair bana lete hai jisme pahle frequency of element store karenge then element
            if(pq.size() < k){  //jb tak priority queue ka size k se chhota hai tb tkk bina dekhe push kro
                pq.push(curr);
                continue;
            }
            if(curr.first < pq.top().first){ //if current pair ka frequency priority queue ke pair se chhota hai to ignore kro isse 
                continue;
            }
            //Aur agr bada hai to isse pop krdo and current pair ko push kro
            pq.pop();
            pq.push(curr);
        }
        vector<int> res;     //Results ko store krne ke liye ek array
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

        
    }
    
};
//Time Complexity: O(nlogk) where k is the size of the minheap which is <= n.