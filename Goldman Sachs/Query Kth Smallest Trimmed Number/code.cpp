class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries)
    {
        vector<int>ans;
        
        
        for(auto current : queries)
        {
            int n = current[0];
            int len = current[1];
            vector<pair<string,int>>arr; // number : index
            for(int i = 0; i < nums.size(); i++)
            {
                // string number = nums[i];
                // int numberLen = number.size();
                // string str = number.substr(numberLen-len);
                arr.push_back({nums[i].substr(nums[i].size()-len),i});
            }
            sort(arr.begin(),arr.end());
            ans.push_back(arr[n-1].second);
        }
        return ans;
    }
};

