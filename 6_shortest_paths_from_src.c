/* 6.	Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the
given graph. The graph may contain negative weight edges. (Bellmen ford) */
#include<stdio.h>
int max(int,int);
int countPlatforms(int n,int arr[],int dep[])
{
    int ans=1;
    for(int i=0;i<=n-1;i++)
    {
        int count=1;
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
           {
               count++;
           }
        }
        ans=max(ans,count);
    }
    return ans;
}
int max(int ans,int count)
{
return (ans>count)?ans:count;
}
int main()
{
    int arr[]={900,940,950,1100,1500,1800};
    int dep[]={910,1200,1120,1130,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    printf("Minimum number of Platforms required: %d\n",countPlatforms(n,arr,dep));
}
