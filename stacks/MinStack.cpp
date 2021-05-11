/*
https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{  if(s.empty())
        return -1;
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{   int ans;
    if(s.empty())
        return -1;
    else
    {   if(s.top()>=minEle)
        {   ans=s.top();
            s.pop();
        }
        else
        {   ans=minEle;
            minEle=2*minEle - s.top();
            s.pop();
        }
    }
    return ans;
}

/*push element x into the stack*/
void _stack::push(int x)
{   if(s.empty())
    {   s.push(x);
        minEle=x;
    }
    else if(x>=minEle)
    {   s.push(x);
    }
    else
    {   s.push(2*x-minEle);
        minEle=x;
    }
}
