// 2493. Divide Nodes Into the Maximum Number of Groups


// You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

// You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

// Divide the nodes of the graph into m groups (1-indexed) such that:

//     Each node in the graph belongs to exactly one group.
//     For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.

// Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 

// Example 1:

// Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
// Output: 4
// Explanation: As shown in the image we:
// - Add node 5 to the first group.
// - Add node 1 to the second group.
// - Add nodes 2 and 4 to the third group.
// - Add nodes 3 and 6 to the fourth group.
// We can see that every edge is satisfied.
// It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.

// Example 2:

// Input: n = 3, edges = [[1,2],[2,3],[3,1]]
// Output: -1
// Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
// It can be shown that no grouping is possible.

 

// Constraints:

//     1 <= n <= 500
//     1 <= edges.length <= 104
//     edges[i].length == 2
//     1 <= ai, bi <= n
//     ai != bi
//     There is at most one edge between any pair of vertices.

class Solution {
public:
    // Main function to calculate the maximum number of magnificent sets
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            // Transition to 0-index
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] != -1) continue;
            // Start coloring from uncolored nodes
            colors[node] = 0;
            // If the graph is not bipartite, return -1
            if (!isBipartite(adjList, node, colors)) return -1;
        }

        // Calculate the longest shortest path for each node
        vector<int> distances(n);
        for (int node = 0; node < n; node++) {
            distances[node] = getLongestShortestPath(adjList, node, n);
        }

        // Calculate the total maximum number of groups across all components
        int maxNumberOfGroups = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++) {
            if (visited[node]) continue;
            // Add the number of groups for this component to the total
            maxNumberOfGroups += getNumberOfGroupsForComponent(
                adjList, node, distances, visited);
        }

        return maxNumberOfGroups;
    }

private:
    // Checks if the graph is bipartite starting from the given node
    bool isBipartite(vector<vector<int>> &adjList, int node,
                     vector<int> &colors) {
        for (int neighbor : adjList[node]) {
            // If a neighbor has the same color as the current node, the graph
            // is not bipartite
            if (colors[neighbor] == colors[node]) return false;

            // If the neighbor is already colored, skip it
            if (colors[neighbor] != -1) continue;

            // Assign the opposite color to the neighbor
            colors[neighbor] = (colors[node] + 1) % 2;

            // Recursively check bipartiteness for the neighbor; return false if
            // it fails
            if (!isBipartite(adjList, neighbor, colors)) return false;
        }
        // If all neighbors are properly colored, return true
        return true;
    }

    // Computes the longest shortest path (height) in the graph starting from
    // the source node
    int getLongestShortestPath(vector<vector<int>> &adjList, int srcNode,
                               int n) {
        // Initialize a queue for BFS and a visited array
        queue<int> nodesQueue;
        vector<bool> visited(n, false);

        nodesQueue.push(srcNode);
        visited[srcNode] = true;
        int distance = 0;

        // Perform BFS layer by layer
        while (!nodesQueue.empty()) {
            // Process all nodes in the current layer
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();

                // Visit all unvisited neighbors of the current node
                for (int neighbor : adjList[currentNode]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
            // Increment the distance for each layer
            distance++;
        }
        // Return the total distance (longest shortest path)
        return distance;
    }

    // Calculates the maximum number of groups for a connected component
    int getNumberOfGroupsForComponent(vector<vector<int>> &adjList, int node,
                                      vector<int> &distances,
                                      vector<bool> &visited) {
        // Start with the distance of the current node as the maximum
        int maxNumberOfGroups = distances[node];
        visited[node] = true;

        // Recursively calculate the maximum for all unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (visited[neighbor]) continue;
            maxNumberOfGroups = max(maxNumberOfGroups,
                                    getNumberOfGroupsForComponent(
                                        adjList, neighbor, distances, visited));
        }
        return maxNumberOfGroups;
    }
};