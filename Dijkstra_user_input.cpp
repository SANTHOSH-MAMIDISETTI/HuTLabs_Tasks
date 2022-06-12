#include<iostream>

using namespace std;
#define INF 999


int V ,cost [100][100],src,dist[100],parent[100];
bool visited[100] = {0} ;

void init()
{
    for (int i = 0 ;i <V ; i++)
    {
        dist[i] = INF;
        parent[i] = i;
    }
    dist[src] = 0;
}


int getNearest()
{
    int minvalue = INF ;
    int minnode = 0 ;
    for(int i = 0 ; i<V ; i++)
    {
        if (!visited[i] && dist[i] < minvalue)
        {
            minvalue = dist[i];
            minnode = i;
        }
    }
return minnode;
}

void dijkstra()
{
    for (int i =0 ; i < V-1 ; i++)
    {
        int nearest = getNearest();
        visited[nearest] = true;
        for(int a_node = 0 ; a_node< V; a_node++)
        {
            if(cost[nearest][a_node] != INF && dist[a_node]>dist[nearest]+cost[nearest][a_node])
            {
                dist[a_node] = dist[nearest]+cost[nearest][a_node];
                parent[a_node] = nearest;
            }
        }
    }
}

void display()
{
    int destination;
    cout<<"enter the destination node";
    cin>>destination;
      cout<<"Node:\t\t\tCost  :\t\t\tPath\n";
      cout<<destination<<"\t\t\t"<<dist[destination]<<"\t\t\t"<<" ";
      cout<<destination<<" ";
      int parnode = destination;

      while(parnode!=src)
      {
          cout<< "<--"<<parnode<<" ";
          parnode = parent[parnode];
      }
      cout<<endl;
}
int main()
{
    cout<<"Enter the number of vertices :  ";
    cin>>V;
    for (int i = 0 ; i< V ; i++)
    {
        for (int j = 0 ;j<V ;j++)
        {
            cin>>cost[i][j];
        }
    }
    cout<<" source node : ";
    cin>>src; 
    init();
    dijkstra();
    display();

}