#include "../../../../common/Includes.h"

class Solution
{
private:
    unordered_map<Node *, Node *> copies;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return NULL;
        }

        if (!copies.count(node))
        {
            copies[node] = new Node(node->val);
            for (Node *neighbor : node->neighbors)
            {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return copies[node];
    }
};