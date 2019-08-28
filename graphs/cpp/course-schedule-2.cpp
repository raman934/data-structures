/* There are a total of n courses you have to take, labeled from 0 to n-1. Some
   courses may have prerequisites, for example to take course 0 you have to
   first take course 1, which is expressed as a pair: [0,1]
   Given the total number of courses and a list of prerequisite pairs, return the
   ordering of courses you should take to finish all courses. There may be
   multiple correct orders, you just need to return one of them. If it is
   impossible to finish all courses, return an empty array.

    Example 1:

    Input: 2, [[1,0]]
    Output: [0,1]
    Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
                 course 0. So the correct course order is [0,1] .
    Example 2:

    Input: 4, [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,1,2,3] or [0,2,1,3]
    Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
                 courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
                 So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
  LC 210. Course Schedule II
  Author: Shruti
*/

class Solution {
    unordered_map<int, unordered_set<int>> graph;
    vector<int> result;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> visiting(numCourses, false);
        // create a graph in the form adjacency list from prerequisites
        // the node is int, and its adjacent nodes are added to unordered_set
        for(auto prereq : prerequisites) {
            if(graph.find(prereq[0]) == graph.end()) {
                graph.insert({prereq[0], {prereq[1]}}); // if start node is not in graph
            } else {
                graph[prereq[0]].insert(prereq[1]); // if node present in graph, add to adj. list
            }
        }

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) { // if the course has not been visited, call dfs from that course
                if(isCycle(i, visited, visiting)) {
                    return {}; // if cycle found in graph, it is not possible to finish all courses
                }
            }
        }
        return result;
    }

    bool isCycle(int course, vector<bool>& visited, vector<bool>& visiting) {
        // mark the current course as true in visited and visiting
        visited[course] = true;
        visiting[course] = true;
        // for each prereq of the course
        for(int nbr : graph[course]) {
            // if the current prereq is the prereq of a currently visiting node, there is a cycle
            if(visiting[nbr]) {
                return true;
            } else {
                // if the prereq is not being visited, visit all its' prereqs
                if(!visited[nbr]) {
                    if(isCycle(nbr, visited, visiting)) {
                        return true;
                    }
                }
            }
        }
        visiting[course] = false;
        result.push_back(course);
        return false;
    }
};
