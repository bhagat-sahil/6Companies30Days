class Solution {
public:
    int countCollisions(string directions) 
    {  
        int n = directions.size() ;
        stack<char> stack ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++ )
        {
            if(stack.empty()) 
                stack.push(directions[i]) ;
            else if( (stack.top() == 'S') && (directions[i] == 'L')) 
                count++;
            else if( (stack.top() == 'R') && (directions[i] == 'S'))
            {
                stack.pop() ;
                directions[i] = 'S';
                i-- ;
                count++ ;
            }
            else if(stack.top() == 'R' && (directions[i] == 'L')) 
            {
                stack.pop();
                directions[i] = 'S';
                i--;
                count = count + 2 ;
            }
        
            else
                stack.push(directions[i]) ;
            
        }
        return count ;
    }
};
