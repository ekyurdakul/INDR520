#include "Dijkstra.h"

int main()
{
    vector<unsigned int> V = {0,1,2};
    vector<vector<float> > E = 
    {
        {0.0f,5.0f,INFINITY},
        {INFINITY,0.0f,8.0f},
        {INFINITY,INFINITY,0.0f},
    };

    cout << "Original Algorithm:" << endl;
    vector<float> distance = vector<float>();
    vector<unsigned int> previous = vector<unsigned int>();
    list<unsigned int> path = {};

    Dijkstra::OriginalAlgorithm(V,E,0,distance,previous);
    Dijkstra::FindPath(distance,previous,2,path);
    Dijkstra::PrintResults(distance,previous,path);

    //void ModifiedAlgorithm

    return 0;
}