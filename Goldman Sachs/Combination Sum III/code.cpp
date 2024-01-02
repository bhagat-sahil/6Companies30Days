class Solution {
public:
    
    void findCombinations( int i, int numCount, int target, vector<int>&combi, vector<vector<int>>&ans )
    {
        if ( target == 0 && numCount == 0 ){
            ans.push_back(combi) ;
            return ;
        }
        if ( numCount == 0 || i > 9 )   return ;
        
        //TAKE
        if ( target - i >= 0 )
        {
            combi.push_back(i) ;
            findCombinations( i+1, numCount-1, target-i, combi, ans ) ;
            combi.pop_back() ;
        }
        //NOT TAKE
        findCombinations( i+1, numCount, target, combi, ans ) ;
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>combi ;
        vector<vector<int>> ans ;
        findCombinations( 1, k, n, combi, ans ) ;
        return ans ;
    }
};
