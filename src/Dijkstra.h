#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <list>
#include <queue>
using namespace std;

class Dijkstra
{ 
public:
    //Time complexity: O(V^2)
    static void OriginalAlgorithm(vector<int> V, vector<vector<float> > E, int source);
    //Time complexity: O(E + VlogV)
    static void ModifiedAlgorithm(vector<int> V, vector<vector<float> > E, int source);
};