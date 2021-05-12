//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> res(n,-1);
        priority_queue<int , vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {   pq.push(arr[i]);
            if(pq.size()>k)
            {   pq.pop();
            }
            if(pq.size() == k)
            {   res[i]=pq.top();
            }
        }
        return res;
    }
};
