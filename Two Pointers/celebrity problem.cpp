class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    //this is also done by stack
    int celebrity(vector<vector<int> >& M, int n) 
    {   int a=0,b=n-1;
        while(a<b)
        {   if(M[a][b]==1)  //if a knows b so a can't be celebrity
                a++;
            else    //else b can't be celebrity
                b--;    
        }
        for(int i=0;i<n;i++)
        {   if(i!=a && ( M[a][i]==1 || M[i][a]==0)) 
                return -1;
        }
        return a;
        // code here
    }
};
