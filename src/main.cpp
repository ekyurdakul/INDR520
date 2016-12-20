#include "Dijkstra.h"

int main()
{
    //Inputs
    const vector<unsigned int> V = {0,1,2};
    const vector<vector<float>> E = 
    {
        {0.0f,5.0f,INFINITY},
        {INFINITY,0.0f,8.0f},
        {INFINITY,INFINITY,0.0f},
    };
    const unsigned int source = 0;
    const unsigned int target = 2;
    //Outputs
    vector<float> distance;
    vector<int> previous;
    list<unsigned int> path;

    Dijkstra::CompareAlgorithms(V,E,source,target,distance,previous,path);

    return 0;
}