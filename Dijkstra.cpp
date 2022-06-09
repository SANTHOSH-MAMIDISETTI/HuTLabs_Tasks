#include<iostream>
#include<climits>     
using namespace std;

#define size 9
int shortDist(const int O_distance[], bool Short_set[]);

int shortDist(const int *O_distance, bool *Short_set) {
    int ap_min=INT_MAX,index;

    for(int i=0;i<size;i++)
    {
        if (Short_set[i] || O_distance[i] > ap_min)
            continue;
        ap_min=O_distance[i];
        index=i;
    }
    return index;
}


void Dijkstra(int graph[size][size],int src) 
{
	int O_distance[size];         
	bool Short_set[size];
	for(int i = 0; i<size; i++)
	{
		O_distance[i] = INT_MAX;
		Short_set[i] = false;	
	}
	
	O_distance[src] = 0;
	
	for(int i = 0; i<size; i++)                           
	{
		int m=shortDist(O_distance,Short_set); 
		Short_set[m]=true;
        for (int lil = 0; lil < size; lil++)
            if (!Short_set[lil] && graph[m][lil] && O_distance[m] != INT_MAX && O_distance[m] + graph[m][lil] < O_distance[lil])
			{
				O_distance[lil] = O_distance[m] + graph[m][lil];
			}
	}
	cout<<"\n\aVertex\t\tDistance from source"<<endl;
	for(int i = 0; i<size; i++)                      
	{
        char str;
        str = 65 + i; 
		cout<<str<<"\t\t\t\t"<<O_distance[i]<<endl;
	}
}

int main()
{
  int graph[size][size]=
   {
{ 0, 4, 0, 0, 0, 0, 0, 8, 0},
{ 4, 0, 8, 0, 0, 0, 0, 11,0},
{ 0, 8, 0, 7, 0, 4, 0, 0,2},
{ 0, 0, 7, 0, 9, 14, 0, 0,0},
{ 0, 0, 0, 9, 0, 10, 0, 0,0},
{ 0, 0, 4, 14,10, 0, 2, 0,0},
{ 0, 0, 0, 0, 0, 2, 0, 1, 6},
{ 8, 11, 0, 0, 0, 0, 1, 0,7},
{ 0, 0, 2, 0, 0, 0, 6, 7,0 }
    };
	Dijkstra(graph,0);
	return 0;	                        
}