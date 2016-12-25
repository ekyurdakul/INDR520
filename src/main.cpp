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
    duration<double> otime,ptime,ftime;

    cout << "*************Correctness Check*************" << endl;
    Dijkstra::CompareAlgorithms(V,E,source,target,distance,previous,path,otime,ptime,ftime);
}

void TestRandomGraphs()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> weightDist(0,100);
    vector<tuple<string,duration<double>,duration<double>,duration<double>>> sparseTimes = {};
    vector<tuple<string,duration<double>,duration<double>,duration<double>>> denseTimes = {};
    for (unsigned int N = 5000; N <= 50000; N+=5000)
    {
        for (int sparseGraph = 1; sparseGraph >= 0; sparseGraph--)
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
                uniform_int_distribution<int> edgeDist;
                if (sparseGraph == 1)
                    edgeDist = uniform_int_distribution<int>(1,2);
                else
                    edgeDist = uniform_int_distribution<int>(1,N/2);

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
            cout << endl << "*************" << N << " Nodes " << edges << " Edges *************" << endl;
            duration<double> otime,ptime,ftime;
            Dijkstra::CompareAlgorithms(V,E,source,target,distance,previous,path,otime,ptime,ftime);
            stringstream ss;
            ss << "Nodes " << N << " Edges " << edges;
            if (sparseGraph == 1)
                sparseTimes.push_back(make_tuple(ss.str(),otime,ptime,ftime));
            else
                denseTimes.push_back(make_tuple(ss.str(),otime,ptime,ftime));
        }
    }

    cout << endl << "Performance Summary:" << endl << "Sparse Graphs" << endl;
    for (auto& time : sparseTimes)
        cout << get<0>(time) << " Original " << get<1>(time).count() << " s" << " Priority Queue " << get<2>(time).count() << " s" << " Fibonacci Heap " << get<3>(time).count() << " s" << endl;
    cout << "Dense Graphs" << endl;
    for (auto& time : denseTimes)
        cout << get<0>(time) << " Original " << get<1>(time).count() << " s" << " Priority Queue " << get<2>(time).count() << " s" << " Fibonacci Heap " << get<3>(time).count() << " s" << endl;
}