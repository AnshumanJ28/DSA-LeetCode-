class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int s = coins.size();
        queue<pair<int,int>> q;  
        vector<bool> visited(amount +1, false);   

        q.push({amount, 0});      
        visited[amount] = true;

        while (!q.empty()) {
            auto [x, steps] = q.front();
            q.pop();

            for (int coin : coins) {
                int next = x - coin;

                if (next == 0) {       
                    return steps+1;    
                }

                if (next >= 0 && !visited[next]) {
                    visited[next] = true;
                    q.push({next, steps+1});   
                }
            }
        }

        return -1;
    }
};