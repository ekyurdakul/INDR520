#include "Dijkstra.h"

void Dijkstra::OriginalAlgorithm(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, vector<float> &distance, vector<int> &previous, duration<double> &time)
{
    auto startTime = high_resolution_clock::now();
    //O(V)
    distance = vector<float>(V.size(),INFINITY);//O(V)
    previous = vector<int>(V.size(),-1);//O(V)
    vector<unsigned int> vertexSet = {};//O(1)
    //O(V)
    for (auto& item : V)//O(1*V)
        vertexSet.push_back(item);//O(1)
    //O(1)
    distance[source] = 0.0f;//O(1)
    //O(V^2)
    while (!vertexSet.empty())//O(V*V)
    {
        //O(1)
        float minDistance = INFINITY;//O(1)
        int minDistIndex = -1;//O(1)
        unsigned int minDistVertex = 0;//O(1)
        //O(V)
        for (unsigned int i = 0; i < vertexSet.size(); i++)//O(1*V)
        {
            unsigned int currentVertex = vertexSet[i];//O(1)
            if (distance[currentVertex] < minDistance || vertexSet.size() == 1)//O(1)
            {
                minDistance = distance[currentVertex];//O(1)
                minDistIndex = i;//O(1)
                minDistVertex = currentVertex;//O(1)
            }
        }
        //O(1)
        if (minDistance == INFINITY)//O(1)
            break;
        //O(V)
        vertexSet.erase(vertexSet.begin()+minDistIndex);//O(V)
        //O(1)
        if (minDistVertex > E.size()-1)//O(1)
            continue;
        //O(V)
        for (auto& edge : E[minDistVertex])//O(1*V)
        {
            float newDist = distance[minDistVertex] + get<1>(edge);//O(1)
            const unsigned int i = get<0>(edge);//O(1)
            if (newDist < distance[i])//O(1)
            {
                distance[i] = newDist;//O(1)
                previous[i] = minDistVertex;//O(1)
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

void Dijkstra::CompareAlgorithms(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, const unsigned int &target, vector<float> &distance, vector<int> &previous, list<unsigned int> &path, duration<double> &otime, duration<double> &mtime)
{
    cout << "Original Algorithm:" << endl;
    OriginalAlgorithm(V,E,source,distance,previous,otime);
    FindPath(distance,previous,target,path);
    PrintResults(distance,previous,path,source,target);
    cout << "*******************" << endl;
    cout << "Modified Algorithm:" << endl;
    ModifiedAlgorithm(V,E,source,distance,previous,mtime);
    FindPath(distance,previous,target,path);
    PrintResults(distance,previous,path,source,target);
    cout << "*******************" << endl;
    cout << "Original: " << otime.count() << " s" << endl << "Modified: " << mtime.count() << " s" << endl;
}