/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> Map;
typedef queue<UndirectedGraphNode *> Queue;
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return node;
        
        Map graphMap;
        Queue graphNodeQueue;
        graphNodeQueue.push(node);
        
        while(!graphNodeQueue.empty()){
            UndirectedGraphNode* curNode = graphNodeQueue.front();
            graphNodeQueue.pop();
            //if the node is not copied before
            if(graphMap.find(curNode) == graphMap.end()){
                UndirectedGraphNode* copyNode = new UndirectedGraphNode(curNode->label);
                graphMap[curNode] = copyNode;
            }
            
            for(UndirectedGraphNode* neighbor:curNode->neighbors){
                if(graphMap.find(neighbor) == graphMap.end()){
                    graphNodeQueue.push(neighbor);
                    UndirectedGraphNode* newNeighbor = new UndirectedGraphNode(neighbor->label);
                    graphMap[curNode]->neighbors.push_back(newNeighbor);
                    graphMap[neighbor] = newNeighbor;
                }
                else{
                    graphMap[curNode]->neighbors.push_back(graphMap[neighbor]);
                }
            }
            
        }
        return graphMap[node];
    }
};