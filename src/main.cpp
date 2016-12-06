#include "Dijkstra.h"

int main()
{
    vector<int> V = {0,1,2};
    vector<vector<float> > E = 
    {
        {0.0f,5.0f,INFINITY},
        {INFINITY,0.0f,8.0f},
        {INFINITY,INFINITY,0.0f},
    };
    cout << "Original Algorithm:" << endl;
    Dijkstra::OriginalAlgorithm(V,E,0);
    cout << endl << "Modified Algorithm:" << endl;
    Dijkstra::ModifiedAlgorithm(V,E,0);

    return 0;
}