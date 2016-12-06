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

    /*
    void OriginalAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int source, vector<float>& distance, vector<unsigned int>& previous);
    void ModifiedAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int source, vector<float>& distance, vector<unsigned int>& previous);
    void FindPath(const vector<float>& distance, const vector<unsigned int>& previous, const unsigned int target, list<unsigned int>& path);
    */

    cout << "Original Algorithm:" << endl;
    vector<float> distance = vector<float>();
    vector<unsigned int> previous = vector<unsigned int>();
    list<unsigned int> path = {};

    Dijkstra::OriginalAlgorithm(V,E,0,distance,previous);

    cout << "Distance: ";
    for (unsigned int i = 0; i < distance.size(); i++)
        cout << distance[i] << " ";
    cout << endl;

    cout << "Previous: ";
    for (unsigned int i = 0; i < previous.size(); i++)
        cout << previous[i] << " ";
    cout << endl;

    Dijkstra::FindPath(distance,previous,2,path);


    /*
    cout << endl << "Modified Algorithm:" << endl;
    Dijkstra::ModifiedAlgorithm(V,E,0);
    */

    return 0;
}