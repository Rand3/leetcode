/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // https://oj.leetcode.com/problems/clone-graph/
        //
        // Clone an undirected graph. Each node in the graph contains 
        // a label and a list of its neighbors.
        //
        // NOTE: OJ's undirected graph serialization:
        // Nodes are labeled uniquely. Use '#' as a separator for node, 
        // ',' as a separator for node label and each neighbor of the node. 
        // As an example, consider the serialized graph {0,1,2#1,2#2,2}.
        // The graph has a total of three nodes separated by #.
        //  - First node is labeled as '0'. Connect node 0 to both node 1 and 2
        //  - Second node is '1', connecting to node 2
        //  - Thrid node is '2', conneting to itself.
        // Visually, the graph looks like:
        // .   1
        // .  / \
        // . 0---2
        // .    /_\
        
        if (node == NULL) { return NULL; }
        unordered_map<int, UndirectedGraphNode*> visited;
        return clone(node, visited);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*> &visited) {
        if (visited.count(node->label) != 0) {
            return visited[node->label];
        }
        UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
        visited[node->label] = p;
        for (auto neighbor : node->neighbors) {
            p->neighbors.push_back(clone(neighbor, visited));
        }
        return p;
    }
};
