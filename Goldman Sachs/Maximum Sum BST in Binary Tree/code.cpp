class Solution {
public:
        
    int ans = 0;
    
    class Data{
        public:
        
        int currentMaxSum;
        int currentBstMin;
        int currentBstMax;
        bool isBST;
        
        Data(){
            currentMaxSum = 0;
            currentBstMin = INT_MAX;
            currentBstMax = INT_MIN;
            isBST = true;
        }
    };
    
    Data maxSum(TreeNode* root)
    {
        if(root == NULL) return Data();
        
        Data node;    
        Data nodeLeft = maxSum(root->left);
        Data nodeRight = maxSum(root->right);
        
        if(nodeLeft.isBST && nodeRight.isBST && root->val > nodeLeft.currentBstMax && nodeRight.currentBstMin > root->val)
        {
            node.isBST = true;
            node.currentBstMax = max(root->val,nodeRight.currentBstMax);
            node.currentBstMin = min(root->val,nodeLeft.currentBstMin);
            node.currentMaxSum = root->val + nodeLeft.currentMaxSum + nodeRight.currentMaxSum;
        }
        else
        {
            node.isBST = false;
            node.currentMaxSum = max(nodeLeft.currentMaxSum,nodeRight.currentMaxSum);
        }
        ans = max(ans,node.currentMaxSum);
        return node;
    }
    
    
    int maxSumBST(TreeNode* root) 
    {
        maxSum(root);
        return ans;
    }
};
