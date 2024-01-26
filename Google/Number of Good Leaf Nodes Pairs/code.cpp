/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0 ;
    
    vector<int> findGoodPairs ( TreeNode* root, int distance )
    {
        if ( root == NULL ) return {0} ;
        if ( root->left == NULL && root->right == NULL ) return {1} ;
        
        vector<int> left = findGoodPairs( root->left, distance ) ;
        vector<int> right = findGoodPairs( root->right, distance ) ;
        
        for ( auto it : left )
        {
            for ( auto i : right )
            {
                if ( it != 0 && i != 0 && it + i  > 1 &&  it + i  <= distance )
                    ans++ ;
            }
        }
        
        vector<int>ans ;
        for ( auto it : left )
        {
            if ( it != 0 ) ans.push_back(it+1) ;
        }
        for ( auto it : right )
        {
            if ( it != 0 ) ans.push_back(it+1) ;
        }
        return ans ;
    }
    
    
    int countPairs(TreeNode* root, int distance) 
    {
        if ( root == NULL ) return 0 ;
        vector<int> a =  findGoodPairs( root, distance ) ;
        return ans ;
    }
};
