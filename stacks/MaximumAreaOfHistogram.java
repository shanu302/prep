// Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
// this code is the efficient implementation, it runs in O(n) time and takes, O(n) auxillary space

class Solution {
    public int largestRectangleArea(int[] heights) {
        ArrayDeque<Integer> st = new ArrayDeque<Integer>();
        
        int res = 0;
        int curr = 0;   
        int n = heights.length;
        int tp;
        for(int i=0;i<heights.length;i++){
            while(st.isEmpty()==false && heights[st.peek()]>=heights[i]){
                tp = st.pop();
                curr = heights[tp] * (st.isEmpty()?i:(i-st.peek()-1));
                res = Math.max(curr, res);
            }
            st.push(i);
        }
        
        //if the array is traversed and stack is not empty( i.e all the elements are not processed yet)
        while(!st.isEmpty()){
            tp=st.pop();
            curr = heights[tp]* (st.isEmpty()?n:(n-st.peek()-1));
            res = Math.max(curr, res);
        }
        return res;
    }
}
