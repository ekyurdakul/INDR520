#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <queue>
#include <chrono>
#include <math.h>
#include <numeric>
using namespace std;
using namespace chrono;

class Dijkstra
{
public:
    static void OriginalAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int& source, vector<float>& distance, vector<int>& previous);
    static void ModifiedAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int& source, vector<float>& distance, vector<int>& previous);
    static void FindPath(const vector<float>& distance, const vector<int>& previous, const unsigned int& target, list<unsigned int>& path);
    static void PrintResults(const vector<float>& distance, const vector<int>& previous, const list<unsigned int>& path, const unsigned int& source, const unsigned int& target);
    static void CompareAlgorithms(const vector<unsigned int> &V, const vector<vector<float>> &E, const unsigned int &source, const unsigned int &target, vector<float> &distance, vector<int> &previous, list<unsigned int> &path);
};