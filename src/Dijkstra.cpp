#include "Dijkstra.h"

void Dijkstra::OriginalAlgorithm(vector<int> V, vector<vector<float> > E, int source)
{
    vector<int> vertexSet = {};
    vector<float> distance = {};
    vector<int> previous = {};
    
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

void Dijkstra::ModifiedAlgorithm(vector<int> V, vector<vector<float> > E, int source)
{
    vector<float> distance = vector<float>(V.size());
    vector<int> previous = vector<int>(V.size());
    priority_queue<pair<int,float>, vector<pair<int,float>>, greater<pair<int,float> > > vertexSet;
    
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

        int v = get<0>(vertex);

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