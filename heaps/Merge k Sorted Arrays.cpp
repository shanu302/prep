//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// time complexity O(N*N log N) and space complexity O(N).
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {   vector<int> res;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int x=0;x<K;x++)
        {   pq.push(make_pair(arr[x][0],make_pair(x,0)));
        }
        while(pq.top().first !=INT_MAX)
        {   res.push_back(pq.top().first);
            if(pq.top().second.second < K-1)
            {   int i=pq.top().second.first;
                int j=pq.top().second.second;
                pq.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
            }
            else
            {   pq.push(make_pair(INT_MAX,make_pair(K,K)));
            }
            pq.pop();
        }
        return res;
    }
};
