#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <list>
using namespace std;

class Dijkstra
{
public:
    //Time complexity: O(V^2)
    static void OriginalAlgorithm(vector<int> V, vector< tuple<int,int,float> > E, int source);
    //Time complexity: O(E + VlogV)
    static void ModifiedAlgorithm(vector<int> V, vector< tuple<int,int,float> > E, int source);
};