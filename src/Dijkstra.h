#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <queue>
#include <math.h>
using namespace std;

class Dijkstra
{ 
public:
    static void OriginalAlgorithm(vector<int> V, vector<vector<float> > E, int source);
    static void ModifiedAlgorithm(vector<int> V, vector<vector<float> > E, int source);
};