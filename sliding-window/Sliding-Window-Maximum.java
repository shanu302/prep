/**
Leetcode problem: https://leetcode.com/problems/sliding-window-maximum/
Difficulty Level: Hard
Possible topics it belongs to: Deque and SlidingWindow
Time Complexity: O(n) ;n: size to input array
Space Complexity: ??

*/

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<Integer>();
        int n=nums.length;
        int[] slidingWindow = new int[n-k+1];
        int ctr=0;
        
        //handles first window
        for(int i=0;i<k;i++){
            while(!dq.isEmpty() && nums[i]>=nums[dq.peekLast()]){
                dq.removeLast();
            }
            dq.addLast(i);
        }
        
        //for subsequent windows
        for(int i=k;i<n;i++){
            slidingWindow[ctr]=nums[dq.peek()];
            ctr++;
            while((!dq.isEmpty())&&(dq.peek()<=i-k)){
                dq.removeFirst();
            }
            
            while((!dq.isEmpty())&&nums[i]>=nums[dq.peekLast()]){
                dq.removeLast();
            }
            
            dq.addLast(i);
        }
        
        slidingWindow[ctr]=nums[dq.peek()];
        return slidingWindow;
    }
}
