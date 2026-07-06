class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dest, unordered_set<string>& visited) {
        // If either variable doesn't exist
        if (graph.find(src) == graph.end())
            return -1.0;

        // Reached destination
        if (src == dest)
            return 1.0;

        visited.insert(src);

        // Visit all neighbors
        for (auto neighbor : graph[src]) {
            string next = neighbor.first;
            double value = neighbor.second;

            if (visited.count(next))
                continue;

            double result = dfs(next, dest, visited);

            if (result != -1.0)
                return value * result;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> answer;

        // Process each query
        for (auto query : queries) {
            string src = query[0];
            string dest = query[1];

            if (graph.find(src) == graph.end() ||
                graph.find(dest) == graph.end()) {
                answer.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;

            answer.push_back(dfs(src, dest, visited));
        }

        return answer;
    }
};