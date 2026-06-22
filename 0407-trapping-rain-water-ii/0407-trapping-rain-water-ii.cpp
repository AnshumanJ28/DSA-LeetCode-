class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int waterTrapped = 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!minHeap.empty()) {
            auto [height, pos] = minHeap.top();
            minHeap.pop();
            int row = pos.first, col = pos.second;

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    waterTrapped += max(0, height - heightMap[newRow][newCol]);
                    minHeap.push({max(height, heightMap[newRow][newCol]), {newRow, newCol}});
                }
            }
        }

        return waterTrapped;
    }
};
