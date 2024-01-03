class Solution{   
public:
    string printMinNumberForPattern(string S)
     {
        string ans = "";
        stack<int>stack;
        int count = 1;
        
        for(auto it : S)
        {
            
            if( it == 'D')
            {
                stack.push(count);
                count++;
            }
            else
            {
                stack.push(count);
                count++;
                while(!stack.empty())
                {
                    ans += to_string(stack.top());
                    stack.pop();
                }
            }
        }
        stack.push(count);
        while(!stack.empty())
        {
            ans += to_string(stack.top());
            stack.pop();
        }
        return ans;
     }
};
