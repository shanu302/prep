// Questions: https://leetcode.com/problems/min-stack/

// This code fails for integer upper and lower limit values.
// This should handle positive as well as negative integers.
// Time Complexity: O(1) for all operations, Auxillary Space: O(n) [if stack included] else O(1)

/**
  failed testcase: 
  Operations: ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
  Values/Inputs: [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]'
  ExpectedOutput: [null,null,null,null,2147483647,null,2147483646,null,2147483646,null,null,2147483647,2147483647,null,-2147483648,-2147483648,null,2147483647]
  Actual Output: [null,null,null,null,2147483647,null,2147483646,null,2147483646,null,null,2147483647,2147483647,null,-2147483647,-2147483648,null,-2147483648]

*/

class MinStack {
    ArrayDeque<Integer> st;
    int min;
    /** initialize your data structure here. */
    public MinStack() {
        st = new ArrayDeque<Integer>();
        min = Integer.MAX_VALUE;
    }
    
    public void push(int val) {
        if(st.isEmpty()){
            this.min=val;
            st.push(val);
        } else if(val<=this.min){
            st.push(2*val-this.min);
            this.min=val;
        } else {
            st.push(val);
        }
    }
    
    public void pop() {
        int temp = st.pop();
        if(temp<=this.min){
            int res=this.min;
            this.min=2*this.min-temp;
            // return res;
        } else {
            // return temp;
        }
    }
    
    public int top() {
        int temp=st.peek();
        return (temp<=this.min)?this.min:temp;
    }
    
    public int getMin() {
        return this.min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
