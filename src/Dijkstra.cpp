#include "Dijkstra.h"

void Dijkstra::OriginalAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int& source, vector<float>& distance, vector<int>& previous)
{
    distance = vector<float>(V.size(),INFINITY);
    previous = vector<int>(V.size(),-1);
    vector<unsigned int> vertexSet = {};
    
    for (auto& item : V)
        vertexSet.push_back(item);
    
    distance[source] = 0.0f;
    
    while (!vertexSet.empty())
    {
        float minDistance = INFINITY;
        int minDistIndex = -1;
        int minDistVertex = -1;
        
        for (unsigned int i = 0; i < vertexSet.size(); i++)
        {
            unsigned int currentVertex = vertexSet[i];
            if (distance[currentVertex] < minDistance || vertexSet.size() == 1)
            {
                minDistance = distance[currentVertex];
                minDistIndex = i;
                minDistVertex = currentVertex;
            }
        }
        vertexSet.erase(vertexSet.begin()+minDistIndex);

        for (unsigned int i = 0; i < E[minDistVertex].size(); i++)
        {
            float newDist = distance[minDistVertex] + E[minDistVertex][i];
            if (newDist < distance[i])
            {
                distance[i] = newDist;
                previous[i] = minDistVertex; 
            }  
        }
    }
}

void Dijkstra::ModifiedAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int& source, vector<float>& distance, vector<int>& previous)
{
    distance = vector<float>(V.size(),INFINITY);
    previous = vector<int>(V.size(),-1);
    priority_queue<pair<unsigned int,float>, vector<pair<unsigned int,float>>, greater<pair<unsigned int,float>>> vertexSet;

    distance[source] = 0.0f;
    
    for (auto& item : V)
        vertexSet.push(make_pair(item,distance[item]));
 
    while (!vertexSet.empty())
    {
        auto& vertex = vertexSet.top();
        unsigned int v = get<0>(vertex);
        vertexSet.pop();

        for (auto& item : V)
        {
            if (item == v)
                continue;

            float newDist = distance[v] + E[v][item];
            if (newDist < distance[item])
            {
                distance[item] = newDist;
                previous[item] = v;
                vertexSet.push(make_pair(item,newDist)); 
            }
        }
    }    
}

void Dijkstra::FindPath(const vector<float>& distance, const vector<int>& previous, const unsigned int& target, list<unsigned int>& path)
{
    path = {};

    unsigned int currentTarget = target;
    while (previous[currentTarget] != -1)
    {
        path.push_front(currentTarget);
        currentTarget = previous[currentTarget];
    }
    path.push_front(currentTarget);
}

void Dijkstra::PrintResults(const vector<float>& distance, const vector<int>& previous, const list<unsigned int>& path, const unsigned int& source, const unsigned int& target)
{
    cout << "Distance: ";
    for (auto& item : distance)
        cout << item << " ";
    cout << endl;

    cout << "Previous: ";
    for (auto& item : previous)
        cout << item << " ";
    cout << endl;

    cout << "Source: " << source << " " << "Target: " << target << endl;
    cout << "Path: ";
    for (auto& item : path)
        cout << item << " ";
    cout << endl;
}