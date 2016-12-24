#include "Dijkstra.h"

void TestCorrectness();
void TestRandomGraphs();
    
int main()
{
    TestCorrectness();
    TestRandomGraphs();

    return 0;
}

void TestCorrectness()
{
    //Inputs
    const vector<unsigned int> V = {0,1,2};
    vector<vector<tuple<unsigned int,float>>> E =
    {
        //Source,Target,Weight
        {make_tuple(1,5.0)},
        {make_tuple(2,8.0)},
        {}
    };
    const unsigned int source = 0;
    const unsigned int target = 2;
    //Outputs
    vector<float> distance;
    vector<int> previous;
    list<unsigned int> path;

    cout << "*************Correctness Check*************" << endl;
    Dijkstra::CompareAlgorithms(V,E,source,target,distance,previous,path);
}

void TestRandomGraphs()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> weightDist(0,100);

    for (unsigned int N = 1000; N <= 1000; N+=100)
    {
        vector<unsigned int> V(N);
        iota(V.begin(),V.end(),0);

        vector<vector<tuple<unsigned int,float>>> E(N);
        const unsigned int source = 0;
        int target = -1;
        unsigned int edges = 0;

        vector<float> distance;
        vector<int> previous;
        list<unsigned int> path;

        //Nodes
        for (unsigned int i = 0; i < N; i++)
        {
            uniform_int_distribution<int> edgeDist(1,2);
            uniform_int_distribution<int> edgeIndexDist(0,N-1);
            const unsigned int edgeCount = edgeDist(gen);
            //Generate random edges
            for (unsigned int j = 0; j < edgeCount; j++)
            {
                const unsigned int destNode = edgeIndexDist(gen);
                const float weight = weightDist(gen);
                E[i].push_back(make_pair(destNode,weight));

                if (edgeDist(gen) == 1 || target == -1)
                    target = destNode;
            }
            edges += edgeCount;
        }
        cout << "*************" << N << " Nodes " << edges << " Edges *************" << endl;
        Dijkstra::CompareAlgorithms(V,E,source,target,distance,previous,path);
    }
}