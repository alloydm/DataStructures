#include <iostream>
#define I 32767
#define V 7 
#define E 9

using namespace std;

void PrintMCST(int T[][V-1], int A[][E]){
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    for (int i {0}; i<V-1; i++){
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}
 void unon(int u,int v , int s[])
 {
     if(s[u]<s[v])
     {
         s[u]=s[u]+s[v];
         s[v]=u;
     }
     else
     {
         s[v]=s[u]+s[v];
         s[u]=v;
     }
     

 }
 int find(int u,int s[])
 {
     int x = u;
     while(s[x]>0)
     {
         x=s[x];
     }
     return x;

 }

 void kruskal(int A[3][9])
 {
     int T[2][V-1];
     int track[E] ={0};
     int set[V+1]= {-1};
     int i=0;
     while(i!=V-1)
     {
         int min=I,u=0,v=0,k=0;
         for(int j=0;j<E;j++)
         {
             if(track[j]==0 && A[2][j] < min )
             {
                 min = A[2][j];
                 u=A[0][j];
                 v=A[1][j];
                 k=j;
             }
         }
         if(find(u,set)!=find(v,set))
         {
             T[0][i]=u;
             T[1][i]=v;
             unon(find(u,set),find(v,set),set);
             i++;

         }
         track[k]=1;

     }
     PrintMCST(T,A);
 }
int main()
{
    
     int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
 
    kruskal(edges);
   
    return 0;
}
