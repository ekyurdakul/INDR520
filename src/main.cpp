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
    const vector<vector<float>> E =
    {
        {0.0f,5.0f,INFINITY},
        {INFINITY,0.0f,8.0f},
        {INFINITY,INFINITY,0.0f},
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
        vector<vector<float>> E(N);
        const unsigned int source = 0;
        const unsigned int target = N-1;
        unsigned int edges = 0;

        vector<float> distance;
        vector<int> previous;
        list<unsigned int> path;

        for (unsigned int i = 0; i < N; i++)
        {
            uniform_int_distribution<int> edgeDist(0,1);
            const unsigned int edgeCount = edgeDist(gen);
            for (unsigned int j = 0; j < N; j++)
            {
                if (i == j)
                    E[i].push_back(0.0f);
                else
                    E[i].push_back(weightDist(gen));
            }
            edges += edgeCount;
        }
        cout << "*************" << N << " Nodes " << edges << " Edges *************" << endl;
        Dijkstra::CompareAlgorithms(V,E,source,target,distance,previous,path);
    }
}