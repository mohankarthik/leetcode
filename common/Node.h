#include <cstdlib>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node* random;
    vector<Node*> neighbors;

    Node() : val(0), left(NULL), right(NULL), next(NULL), random(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL), random(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next), random(NULL) {}

    Node(int _val, vector<Node*> _neighbors)
        : val(_val), neighbors(_neighbors), left(NULL), right(NULL), next(NULL), random(NULL) {}
};