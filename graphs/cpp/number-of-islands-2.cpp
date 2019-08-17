/* A 2d grid map of m rows and n columns is initially filled with water. We may
   perform an addLand operation which turns the water at position (row, col)
   into a land. Given a list of positions to operate, count the number of
   islands after each addLand operation. An island is surrounded by water and
   is formed by connecting adjacent lands horizontally or vertically. You may
   assume all four edges of the grid are all surrounded by water.

    Example:

    Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
    Output: [1,1,2,3]

   LC 305. Number of Islands II
   Author: Shruti
*/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> parents(m*n, -1); // initialize parent vector for each node in grid
        vector<pair<int,int>> neighbors = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<int> result;
        unordered_set<string> num_of_pos;
        if(m <= 0 || n <= 0) {
            return result;
        }
        int island = 0;
        for(auto pos : positions) {
            // detect duplicate pos values in positions
            string pos_str = to_string(pos[0]) + "," + to_string(pos[1]);
            if(num_of_pos.find(pos_str) != num_of_pos.end()) { // duplicate pos detected
                result.push_back(island);
                continue;
            }
            num_of_pos.insert(pos_str);
            int row = pos[0];
            int col = pos[1];
            int parent_id = row*n + col; // linearize the grid vector w.r.t parents vector
            parents[parent_id] = parent_id; // make the node its own parent; hence an island of its own
            island++; // increment islands
            for(auto nei : neighbors) {
                int nrow = row + nei.first;
                int ncol = col + nei.second; // calculate new row and col value for neighbors of (row,col)
                int nparent_id = nrow*n + ncol; // get parent_id of the neighbor
                if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n || parents[nparent_id] == -1){
                    continue; // if neighbor doesn't exist or its parent is invalid/not visited go to next neighbor
                } // if neighbor exists, and its parent has been visited, it is a part of an island
                int new_parent_id = findIsland(parents, nparent_id);
                if(parent_id != new_parent_id) { // the node is in another island, not its own
                    parents[parent_id] = new_parent_id; // unionize the new found part (neigh) of the island
                    parent_id = new_parent_id; // update the parent_id for all remaining neighbors
                    island--; // decrement the count of islands
                }
            }
            result.push_back(island);
        }
        return result;
    }

    int findIsland(vector<int> parents, int nparent_id) {
        while(nparent_id != parents[nparent_id]) {
            nparent_id = parents[nparent_id]; // find the actual parent of the neighbor i.e. the node who started the island
        }
        return nparent_id; // this node started the island, send its id
    }
};
