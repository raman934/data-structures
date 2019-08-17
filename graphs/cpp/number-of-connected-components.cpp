/* Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each
   edge is a pair of nodes), write a function to find the number of connected
   components in an undirected graph.

    Example 1:

    Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

        0          3
        |          |
        1 --- 2    4

    Output: 2

    Example 2:

    Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

        0           4
        |           |
        1 --- 2 --- 3

    Output:  1

   LC 323. Number of Connected Components in an Undirected Graph
   Author: Shruti
*/

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n); // parent to keep track of each vertex's parent
        int count = n;
        for(int i = 0; i < n; i++) {
            parents[i] = i;
        }
        for(auto edge : edges) {
            int x = findCommonParent(parents, edge[0]);
            int y = findCommonParent(parents, edge[1]);
            if(x != y) {
                parents[y] = x;
                count--;
            }
        }
        return count;
    }

    int findCommonParent(vector<int> parents, int v) {
        while(parents[v] != v) {
            v = parents[v];
        }
        return v;
    }
};
