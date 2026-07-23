class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.assign(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y)
                return false;

            if (rank[x] < rank[y])
                swap(x, y);

            parent[y] = x;

            if (rank[x] == rank[y])
                rank[x]++;

            return true;
        }
    };

    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {
        DSU dsu(n);
        int cost = 0;

        if (force != -1) {
            dsu.unite(edges[force][0], edges[force][1]);
            cost += edges[force][2];
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip)
                continue;

            if (dsu.unite(edges[i][0], edges[i][1]))
                cost += edges[i][2];
        }

        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root)
                return INT_MAX;
        }

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        for (int i = 0; i < m; i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int original = kruskal(n, edges, -1, -1);

        vector<int> critical, pseudo;

        for (int i = 0; i < m; i++) {

            if (kruskal(n, edges, i, -1) > original) {
                critical.push_back(edges[i][3]);
            } else if (kruskal(n, edges, -1, i) == original) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};