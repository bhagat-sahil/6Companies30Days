class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>list ;
        
        for ( auto &it :  buildings )
        {
            list.push_back({it[0],-it[2]}) ;
            list.push_back({it[1],it[2]}) ;
        }
        
        int curHt = 0 ;
        multiset<int>pq ;
        pq.insert(0) ;
        
        sort(begin(list),end(list)) ;
        
        vector<vector<int>>ans ;
        for ( int i = 0 ; i < size(list) ; i++ )
        {
            int point = list[i].first ;
            int ht = list[i].second ;
            
            if ( ht < 0 )
                pq.insert(-ht) ;
            else 
                pq.erase(pq.find(ht)) ;
        
            int top = *pq.rbegin() ;
        
            if ( curHt != top )
            {
                curHt = top ;
                ans.push_back({point,curHt}) ;
            }
        }
        return ans ;
    }
};
