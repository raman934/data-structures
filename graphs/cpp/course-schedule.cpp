/* There are a total of n courses you have to take, labeled from 0 to n-1. Some
   courses may have prerequisites, for example to take course 0 you have to
   first take course 1, which is expressed as a pair: [0,1]
   Given the total number of courses and a list of prerequisite pairs, is it
   possible for you to finish all courses?

    Example 1:

    Input: 2, [[1,0]] 
    Output: true
    Explanation: There are a total of 2 courses to take.
                 To take course 1 you should have finished course 0. So it is possible.
    Example 2:

    Input: 2, [[1,0],[0,1]]
    Output: false
    Explanation: There are a total of 2 courses to take.
                 To take course 1 you should have finished course 0, and to take course 0 you should
                 also have finished course 1. So it is impossible.

  LC 207. Course Schedule
  Author: Shruti
*/

class Solution {
    unordered_map<int,unordered_set<int>> graph;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
                    return false; // if cycle found in graph, it is not possible to finish all courses
                }
            }
        }
        return true;
    }

    bool isCycle(int course, vector<bool>& visited, vector<bool>& visiting) {
        // mark the node being visited as both visited and visiting
        visited[course] = true;
        visiting[course] = true;
        // for each nbr of the node/course being visited
        // if the nbr is already marked as visiting => there is a cycle in the graph, return true
        // if the nbr is not visited, visit it
        // after all nbrs of the node visited, mark it false in visiting vector
        for(int nbr : graph[course]) {
            if(visiting[nbr]) {
                return true;
            } else {
                if(!visited[nbr]) {
                    if(isCycle(nbr, visited, visiting)) {
                        return true;
                    }
                }
            }
        }
        visiting[course] = false;
        return false;
    }
};
