class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // keep count of occurance of each element in a hash map
        unordered_map<int,int> hash;
        for(int c:nums){
            ++hash[c];
        }
        // create a min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto iter:hash){
            heap.push({iter.second,iter.first});
            if(heap.size() > k){
                heap.pop();
            }
        }
        vector<int> res;
        while(!heap.empty()){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
}
