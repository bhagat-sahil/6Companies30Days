class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>, greater<int>> minHeap ;
        int mod = 1e9+7 ;
        
        
        for ( auto &it : nums )
            minHeap.push(it) ;
        
        while ( k != 0 )
        {
            int val = minHeap.top() ;
            minHeap.pop() ;
            val++ ;
            minHeap.push(val) ;
            k-- ;
        }
        long long ans = 1 ;
        while ( !minHeap.empty())
        {
            int temp = minHeap.top() ;
            minHeap.pop() ;
            ans = ( ans * temp ) % mod ;
        }
        return ans ;
    }
};
