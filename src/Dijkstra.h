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
    static void OriginalAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int source, vector<float>& distance, vector<unsigned int>& previous);
    static void ModifiedAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int source, vector<float>& distance, vector<unsigned int>& previous);
    static void FindPath(const vector<float>& distance, const vector<unsigned int>& previous, const unsigned int target, list<unsigned int>& path);
};