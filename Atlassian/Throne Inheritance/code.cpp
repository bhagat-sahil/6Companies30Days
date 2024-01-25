class ThroneInheritance {
public:
    
    
    unordered_map<string,vector<string>> child ;
    unordered_map<string,bool> mp ;
    string king ;
    
    void dfs(vector<string>& ans, string s )
    {
        if(!mp[s]) ans.push_back(s) ;
        
        for(auto it : child[s])
            dfs( ans, it ) ;
        
    }
    
    ThroneInheritance(string kingName) 
    {
        king=kingName ;
    }
    
    void birth(string parentName, string childName) 
    {
        child[parentName].push_back(childName) ;
    }
    
    void death(string name) 
    {
        mp[name]=1 ;
    }
    
    vector<string> getInheritanceOrder() 
    {
        vector<string> ans ;
        dfs( ans, king ) ;
        return ans ;
         
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
