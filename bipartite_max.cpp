#include <iostream>
#define M 6
#define N 6
using namespace std;

bool bipartiteMatch(bool bipartiteGraph[M][N],int u, bool visited[], int assign[]) {
   for (int v = 0; v < N; v++) 
   {    //for all jobs 0 to N-1
      if (bipartiteGraph[u][v] && !visited[v])
      {    //when job v is not visited and u is interested
         visited[v] = true;    //mark as job v is visited
         //when v is not assigned or previously assigned
         if (assign[v] < 0 || bipartiteMatch(bipartiteGraph,assign[v], visited, assign)) {
            assign[v] = u;    //assign job v to applicant u
            return true;
         }
      }
   }
   return false;
}

int maxMatch(bool bipartiteGraph[M][N])
{
   int assign[N];    //an array to track which job is assigned to which applicant
   for(int i = 0; i<N; i++)
      assign[i] = -1;    //initially set all jobs are available
   int jobCount = 0;

   for (int u = 0; u < M; u++)
   {    //for all applicants
      bool visited[N];
      for(int i = 0; i<N; i++)
         visited[i] = false;    //initially no jobs are visited
      if (bipartiteMatch(bipartiteGraph,u, visited, assign))    //when u get a job
         jobCount++;
   }
   return jobCount;
}

int main() 
{
    int m,n;
    cout<<"Enter the no of applicants:\n";
    cin>>m;
    cout<<"Enter the no of jobs:\n";
    cin>>n;
    bool bipartiteGraph[M][N];
    cout<<"Enter which job has been applied by which applicant:\n";
    for(int i=0;i<M;i++)
     for(int j=0;j<N;j++)
        cin>>bipartiteGraph[i][j];
   cout << "Maximum number of applicants matching for job: " << maxMatch(bipartiteGraph);
   return 0;
}
