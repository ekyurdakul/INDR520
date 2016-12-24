#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <queue>
#include <chrono>
#include <cmath>
#include <numeric>
#include <random>
#include <sstream>
using namespace std;
using namespace chrono;

class Dijkstra
{
public:
    //O(V^2)
    static void OriginalAlgorithm(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, vector<float> &distance, vector<int> &previous, duration<double> &time);
    //O(ElogV + VlogV)
    static void ModifiedAlgorithm(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, vector<float> &distance, vector<int> &previous, duration<double> &time);
    static void FindPath(const vector<float> &distance, const vector<int> &previous, const unsigned int &target, list<unsigned int> &path);
    static void PrintResults(const vector<float> &distance, const vector<int> &previous, const list<unsigned int> &path, const unsigned int &source, const unsigned int &target);
    static void CompareAlgorithms(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, const unsigned int &target, vector<float> &distance, vector<int> &previous, list<unsigned int> &path, duration<double> &otime, duration<double> &mtime);
};