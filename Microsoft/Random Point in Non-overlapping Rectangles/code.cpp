class Solution {
public:
    vector<int> v;
    vector<vector<int>> r;
    
    int findArea(vector<int>& r) 
    {
        int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1) ;
        return area ;
    }
    
    
    Solution(vector<vector<int>>& rects) 
    {
        r = rects ;
        for ( auto it : r ) 
        {
            v.push_back(findArea(it) + (v.empty() ? 0 : v.back()));
        }
    }
    
    vector<int> pick() 
    {
        int random = rand() % v.back();
        auto it = upper_bound( v.begin(), v.end(), random );
        int i = it - v.begin() ;
        
        auto a = r[i];
        return { rand() % (a[2] - a[0] + 1) + a[0], rand() % (a[3] - a[1] + 1) + a[1] } ;
    }
};
