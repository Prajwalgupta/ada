// जय सरस्वती माता
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int max(int a , int b)
{
    return (a>b) ? a : b ;
}

void warshall(int p[10][10] , int n)
{
    for(int k = 1 ; k<=n ; k++)
    {
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ; j<=n ; j++)
            {
                p[i][j] = max(p[i][j] , p[i][k] && p[k][j]);
            }
        }
    }
}
int main()
{
    int p[10][10] = {0} , edge , vertice , a , b;
    cout<<"enter number of vertices"<<endl;
    cin>>vertice;
    cout<<"Enter number of edges"<<endl;
    cin>>edge;

    for(int i = 0 ; i<edge ; i++)
    {
        cout<<"Enter connection"<<" "<<i+1<<endl;
        cin>>a>>b;
        p[a][b] = 1;
    }

    cout<<"Matrix of input"<<endl;
    for(int i = 1  ; i<=vertice; i++)
    {
        for(int j = 1 ; j<=vertice ; j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }

    warshall(p , vertice);

    cout<<"Transitive matrix"<<endl;
    for(int i = 1  ; i<=vertice; i++)
    {
        for(int j = 1 ; j<=vertice ; j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}