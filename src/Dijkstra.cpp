#include "Dijkstra.h"

void Dijkstra::OriginalAlgorithm(vector<int> V, vector< tuple<int,int,float> > E, int source)
{
    vector<int> vertexSet = {};
    vector<float> distance = {};
    vector<int> previous = {};
    
    for (unsigned int i = 0; i < V.size(); i++)//O(V)
    {
        vertexSet.push_back(V[i]);//O(1)
        previous.push_back(0);//O(1)
        distance.push_back(numeric_limits<float>::infinity());//O(1)
    }
    distance[source] = 0;//O(1)
    
    while (!vertexSet.empty())//O(V^2)
    {
        float minDistance = numeric_limits<float>::infinity();//O(1)
        int minDistIndex = -1;//O(1)
        int minDistVertex = -1;//O(1)
        
        for (unsigned int i = 0; i < vertexSet.size(); i++)//O(V)
        {
            int currentVertex = vertexSet[i];//O(1)
            if (distance[currentVertex] < minDistance || vertexSet.size() == 1)//O(1)
            {
                minDistance = distance[currentVertex];//O(1)
                minDistIndex = i;//O(1)
                minDistVertex = currentVertex;//O(1)
            }
        }
        vertexSet.erase(vertexSet.begin()+minDistIndex);//O(V)

        //Convert to adjacency matrix so O(V)
        for (auto& edge : E)//for each neighbor v of u://O(E)
        {
            if (get<0>(edge) == minDistVertex)//O(1)
            {
                float newDist = distance[minDistVertex] + get<2>(edge);//O(1)
                if (newDist < distance[get<1>(edge)])//O(1)
                {
                    distance[get<1>(edge)] = newDist;//O(1)
                    previous[get<1>(edge)] = minDistVertex;//O(1) 
                } 
            } 
        }
    }

    cout << "Distance: ";
    for (unsigned int i = 0; i < distance.size(); i++)
        cout << distance[i] << " ";
    cout << endl;

    cout << "Previous: ";
    for (unsigned int i = 0; i < previous.size(); i++)
        cout << previous[i] << " ";
    cout << endl;

    list<int> path = {};
    unsigned int target = 2;
    cout << "Path from " << source << " to " << target << " : ";

    while (target > 0 && target < V.size())
    {
        path.push_front(target);
        target = previous[target];
    }
    path.push_front(target);

    for (auto& item : path)
        cout << item << " ";
    cout << endl;
}

void Dijkstra::ModifiedAlgorithm(vector<int> V, vector< tuple<int,int,float> > E, int source)
{
    
}