#include "Dijkstra.h"

int main()
{
    vector<int> V = {0,1,2};
    vector< tuple<int,int,float> > E = 
    {
        //<src,dest,weight>
        make_tuple(0,1,5.0f),
        make_tuple(1,2,8.0f),
    };
    Dijkstra::Original(V,E,0);

    return 0;
}