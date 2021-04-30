struct myComparator{
    int operator()(pair<int,int> &p1,  pair<int,int>& p2){

        if(p1.first>p2.first)
            return true;
        else if(p1.first<p2.first)
            return false;
        else{
            if(p1.second<p2.second)
                return true;
            else return false;
        }

    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        //we want element with lowest. frequency at top 
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComparator> pq;
        unordered_map<int,int> hash;
        for(int i:nums){
            ++hash[i];
        }
        for(auto iter:hash){
            pq.push({iter.second,iter.first});
        }
        int  i=0;
        while(!pq.empty() && i<nums.size()){
            int count = pq.top().first;
            while(count--){
                nums[i++] = pq.top().second;
            }
            pq.pop();
        }
        return nums;
    }
};
