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

void Dijkstra::PriorityQueueAlgorithm(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, vector<float> &distance, vector<int> &previous, duration<double> &time)
{
    auto startTime = high_resolution_clock::now();
    //O(V)
    distance = vector<float>(V.size(),INFINITY);//O(V)
    previous = vector<int>(V.size(),-1);//O(V)
    priority_queue<pair<unsigned int,float>, vector<pair<unsigned int,float>>, greater<pair<unsigned int,float>>> vertexSet;//O(1)
    distance[source] = 0.0f;//O(1)
    //O(VlogV)
    for (auto& item : V)//O(logV*V)
        vertexSet.push(make_pair(item,distance[item]));//O(logV)
    //O(ElogV)
    while (!vertexSet.empty())//O(VlogV * V)
    {
        //O(logV)
        auto& vertex = vertexSet.top();//O(1)
        unsigned int v = get<0>(vertex);//O(1)
        vertexSet.pop();//O(logV)
        //O(1)
        if (v > E.size()-1)//O(1)
            continue;
        //O(VlogV)
        for (auto& edge : E[v])//O(logV*V)
        {
            float newDist = distance[v] + get<1>(edge);//O(1)
            const unsigned int i = get<0>(edge);//O(1)
            if (newDist < distance[i])//O(1)
            {
                distance[i] = newDist;//O(1)
                previous[i] = v;//O(1)
                vertexSet.push(make_pair(i,newDist));//O(logV)
            }
        }
    }
    auto endTime = high_resolution_clock::now();
    time = endTime - startTime;
}

void Dijkstra::FibonacciHeapAlgorithm(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, vector<float> &distance, vector<int> &previous, duration<double> &time)
{
    auto startTime = high_resolution_clock::now();
    //O(V)
    distance = vector<float>(V.size(),INFINITY);//O(V)
    previous = vector<int>(V.size(),-1);//O(V)
    boost::heap::fibonacci_heap<fheap> vertexSet;//O(1)
    vector<boost::heap::fibonacci_heap<fheap>::handle_type> handles;//O(1)
    distance[source] = 0.0f;//O(1)
    //O(V)
    for (auto& item : V)//O(1*V)
    {
        auto h = vertexSet.push(fheap(item,distance[item]));//O(1)
        vertexSet.increase(h);//O(1)
        handles.push_back(h);//O(1)
    }
    //O(E + VlogV)
    while (!vertexSet.empty())
    {
        //O(logV)
        auto& vertex = vertexSet.top();//O(1)
        unsigned int v = vertex.edge;//O(1)
        vertexSet.pop();//O(logV)
        //O(1)
        if (v > E.size()-1)//O(1)
            continue;
        //O(E)
        for (auto& edge : E[v])
        {
            //O(1)
            float newDist = distance[v] + get<1>(edge);//O(1)
            const unsigned int i = get<0>(edge);//O(1)
            if (newDist < distance[i])//O(1)
            {
                distance[i] = newDist;//O(1)
                previous[i] = v;//O(1)
                (*handles[i]).weight = newDist;//O(1)
                vertexSet.increase(handles[i]);//O(1)
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

void Dijkstra::CompareAlgorithms(const vector<unsigned int> &V, vector<vector<tuple<unsigned int,float>>> &E, const unsigned int &source, const unsigned int &target, vector<float> &distance, vector<int> &previous, list<unsigned int> &path, duration<double> &otime, duration<double> &ptime, duration<double> &ftime)
{
    cout << "Original Algorithm:" << endl;
    OriginalAlgorithm(V,E,source,distance,previous,otime);
    FindPath(distance,previous,target,path);
    PrintResults(distance,previous,path,source,target);
    cout << "*************************" << endl;
    cout << "Priority Queue Algorithm:" << endl;
    PriorityQueueAlgorithm(V,E,source,distance,previous,ptime);
    FindPath(distance,previous,target,path);
    PrintResults(distance,previous,path,source,target);
    cout << "*************************" << endl;
    cout << "Fibonacci Heap Algorithm:" << endl;
    FibonacciHeapAlgorithm(V,E,source,distance,previous,ftime);
    FindPath(distance,previous,target,path);
    PrintResults(distance,previous,path,source,target);
    cout << "*************************" << endl;
    cout << "Original: \t" << otime.count() << " s" << endl << "Priority Queue: " << ptime.count() << " s" << endl << "Fibonacci Heap: " << ftime.count() << " s" << endl;
}