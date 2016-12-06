#include "Dijkstra.h"

void Dijkstra::OriginalAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int source, vector<float>& distance, vector<unsigned int>& previous)
{
    vector<int> vertexSet = {};
    
    for (unsigned int i = 0; i < V.size(); i++)
    {
        vertexSet.push_back(V[i]);
        previous.push_back(0);
        distance.push_back(INFINITY);
    }
    distance[source] = 0;
    
    while (!vertexSet.empty())
    {
        float minDistance = INFINITY;
        int minDistIndex = -1;
        int minDistVertex = -1;
        
        for (unsigned int i = 0; i < vertexSet.size(); i++)
        {
            int currentVertex = vertexSet[i];
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

void Dijkstra::ModifiedAlgorithm(const vector<unsigned int>& V, const vector<vector<float>>& E, const unsigned int source, vector<float>& distance, vector<unsigned int>& previous)
{
    distance = vector<float>(V.size());
    previous = vector<unsigned int>(V.size());
    priority_queue<pair<unsigned int,float>, vector<pair<unsigned int,float>>, greater<pair<unsigned int,float>>> vertexSet;
    
    for (unsigned int i = 0; i < V.size(); i++)
    {        
        auto currentVertex = V[i];
        if (currentVertex != source)
        {
            distance[i] = INFINITY;
            previous[i] = -1;
        }
        else
            distance[i] = 0.0f;

        vertexSet.push(make_pair(currentVertex,distance[currentVertex]));
    }
 
    while (!vertexSet.empty())
    {
        auto vertex = vertexSet.top();
        vertexSet.pop();

        unsigned int v = get<0>(vertex);

        for (unsigned int i = 0; i < V.size(); i++)
        {
            if (V[i] == v)
                continue;

            float newDist = distance[v] + E[v][V[i]];
            if (newDist < distance[V[i]])
            {
                distance[V[i]] = newDist;
                previous[V[i]] = v;

                vertexSet.push(make_pair(V[i], newDist)); 
            }
        }
    }

    
}

void Dijkstra::FindPath(const vector<float>& distance, const vector<unsigned int>& previous, const unsigned int target, list<unsigned int>& path)
{
    cout << "Path to node " << target << " : ";

    unsigned int currentTarget = target;
    while (currentTarget > 0 && currentTarget < distance.size())
    {
        path.push_front(currentTarget);
        currentTarget = previous[currentTarget];
    }
    path.push_front(currentTarget);

    for (auto& item : path)
        cout << item << " ";
    cout << endl;
}

void Dijkstra::PrintResults(const vector<float>& distance, const vector<unsigned int>& previous, const list<unsigned int>& path)
{
    cout << "Distance: ";
    for (unsigned int i = 0; i < distance.size(); i++)
        cout << distance[i] << " ";
    cout << endl;

    cout << "Previous: ";
    for (unsigned int i = 0; i < previous.size(); i++)
        cout << previous[i] << " ";
    cout << endl;
}