#include <iostream>
#define M 6
#define N 6
using namespace std;
int setA[M], setB[N];
bool bipartiteMatch(bool bipartiteGraph[M][N],int u, bool visited[], int assign[]) {
   for (int v = 0; v < N; v++) 
   {    
      if (bipartiteGraph[u][v] && !visited[v])
      {    
         visited[v] = true;    
         if (assign[v] < 0 || bipartiteMatch(bipartiteGraph,assign[v], visited, assign)) {
            assign[v] = u;    
            return true;
         }
      }
   }
   return false;
}

int maxMatch(bool bipartiteGraph[M][N])
{
   int assign[N];    
   for(int i = 0; i<N; i++)
      assign[i] = -1;    
   int result = 0;
    bool visited[N];
   for (int u = 0; u < M; u++)
   {    
      
      for(int i = 0; i<N; i++)
         visited[i] = false;    
      if (bipartiteMatch(bipartiteGraph,u, visited, assign))    
         result++;
   }
   cout<<"Matched vertices set = {";
     for(int i=0; i<N; i++){
        cout<<"("<<setA[i]<<", "<<setB[visited[i]]<<")";
        if(i != M-1) cout<<", ";
     }
     cout<<"}";
     cout<<endl;
   return result;
}

int main() 
{
    int m,n;
    cout<<"Enter number of vertices in set A\n";
    cin>>m;
    cout<<"Enter number of vertices in set B\n";
    cin>>n;
    bool bipartiteGraph[M][N];
    cout<<"Enter the adjacency matrix describing the relation between the two set of vertices:\n";
    for(int i=0;i<M;i++)
     for(int j=0;j<N;j++)
        cin>>bipartiteGraph[i][j];
   cout << "Maximum number of matching \n: " << maxMatch(bipartiteGraph);
   return 0;
}
