/* You are given a m x n 2D grid initialized with these three possible values.
  -1: A wall or an obstacle.
   0: A gate.
   INF: Infinity means an empty room. We use the value 231 - 1 = 2147483647 to
   represent INF as you may assume that the distance to a gate is less than
   2147483647.

   Fill each empty room with the distance to its nearest gate. If it is
   impossible to reach a gate, it should be filled with INF.

   LC 286. Walls and Gates
   Author: Shruti
*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0) {
            return;
        }
        queue<pair<int,int>> q; // queue for bfs
        for(int i = 0; i < rooms.size(); i++) {
            for(int j = 0; j < rooms[0].size(); j++) {
                if(rooms[i][j] == 0) {
                    q.push(make_pair(i,j)); // push all the gates in the queue
                }
            }
        }
        vector<pair<int,int>> neighbors = {{1,0},{-1,0},{0,1},{0,-1}}; // all neighbors' relative distance from node
        while(!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            // x,y coordinates for the front node
            int x = curr.first;
            int y = curr.second;
            for(auto neigh : neighbors) {
                int row = neigh.first + x; // get relative row index for x's neighbor
                int col = neigh.second + y; // get relative col index for y's neighbor
                if(row < 0 || col < 0 || row >= rooms.size() || col >= rooms[0].size() || rooms[row][col] <= rooms[x][y]) {
                    continue; // if neigh doesn't exist or is less than curr node's val => it's been visited
                }
                rooms[row][col] = rooms[x][y] + 1; // update neigh's distance by relative distance i.e. 1
                q.push(make_pair(row, col)); // add the neighbor to the queue for later visit
            }
        }
    }
};
