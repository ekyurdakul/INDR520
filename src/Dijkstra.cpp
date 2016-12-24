#include "Dijkstra.h"

void Dijkstra::OriginalAlgorithm(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, vector<float> &distance, vector<int> &previous, duration<double> &time)
{
    auto startTime = high_resolution_clock::now();

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
        unsigned int minDistVertex = 0;
        
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
        if (minDistance == INFINITY)
            break;

        vertexSet.erase(vertexSet.begin()+minDistIndex);

        if (minDistVertex > E.size()-1)
            continue;

        for (auto& edge : E[minDistVertex])
        {
            float newDist = distance[minDistVertex] + get<1>(edge);
            const unsigned int i = get<0>(edge);
            if (newDist < distance[i])
            {
                distance[i] = newDist;
                previous[i] = minDistVertex; 
            }  
        }
    }
    auto endTime = high_resolution_clock::now();
    time = endTime - startTime;
}

void Dijkstra::ModifiedAlgorithm(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, vector<float> &distance, vector<int> &previous, duration<double> &time)
{
    auto startTime = high_resolution_clock::now();
    
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

        if (v > E.size()-1)
            continue;

        for (auto& edge : E[v])
        {
            float newDist = distance[v] + get<1>(edge);
            const unsigned int i = get<0>(edge);
            if (newDist < distance[i])
            {
                distance[i] = newDist;
                previous[i] = v;
                vertexSet.push(make_pair(i,newDist));
            }
        }
    }

    auto endTime = high_resolution_clock::now();
    time = endTime - startTime;
}

void Dijkstra::FindPath(const vector<float> &distance, const vector<int> &previous, const unsigned int &target, list<unsigned int> &path)
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

void Dijkstra::PrintResults(const vector<float> &distance, const vector<int> &previous, const list<unsigned int> &path, const unsigned int &source, const unsigned int &target)
{
#ifdef DEBUG
    cout << "Distance: ";
    for (auto& item : distance)
        cout << item << " ";
    cout << endl;

    cout << "Previous: ";
    for (auto& item : previous)
        cout << item << " ";
    cout << endl;
#endif

    cout << "Source: " << source << " " << "Target: " << target << endl;
    cout << "Path: ";
    for (auto& item : path)
        cout << item << " ";
    cout << endl;
}

void Dijkstra::CompareAlgorithms(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, const unsigned int &target, vector<float> &distance, vector<int> &previous, list<unsigned int> &path)
{
    duration<double> originalTime, modifiedTime;
    cout << "Original Algorithm:" << endl;
    OriginalAlgorithm(V,E,source,distance,previous,originalTime);
    FindPath(distance,previous,target,path);
    PrintResults(distance,previous,path,source,target);
    cout << "*******************" << endl;
    cout << "Modified Algorithm:" << endl;
    ModifiedAlgorithm(V,E,source,distance,previous,modifiedTime);
    FindPath(distance,previous,target,path);
    PrintResults(distance,previous,path,source,target);
    cout << "*******************" << endl;
    cout << "Original: " << originalTime.count() << " s" << endl << "Modified: " << modifiedTime.count() << " s" << endl;
}