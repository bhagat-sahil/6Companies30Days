class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        
        for(auto current : edges)
        {
            int to = current[0];
            int from = current[1];
            int weight = current[2];
            
            distance[to][from] = weight;
            distance[from][to] = weight; // since its biderectional
        }
        
        for(int intermediate = 0; intermediate < n; intermediate++)
        {
            for(int source = 0; source < n; source++)
            {
                for(int destination = 0; destination < n; destination++)
                {
                    if(source == destination)
                    {
                        distance[source][destination] = 0;
                        continue;
                    }
                    if(distance[source][intermediate] != INT_MAX && distance[intermediate][destination] != INT_MAX)
                    {
                        distance[source][destination] = min(distance[source][destination],
                                                         distance[source][intermediate]+distance[intermediate][destination]);
                    }
                }
            }
        }
        
        vector<int>cityCount(n,0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // cout<<distance[i][j]<<" ";
                if(distance[i][j] <= distanceThreshold)
                    cityCount[i]++;
            }
            // cout<<endl;
        }
        
        int ans = 0;
        int minCount = INT_MAX;
        for(int index = 0; index < n; index++)
        {
            if(cityCount[index] <= minCount)
            {
                minCount = cityCount[index];
                ans = index;
            }
        }
        return ans;
    }
};
