// जय सरस्वती माता
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int min(int a , int b)
{
    return (a<b) ? a : b;
}

void floyd(int distances[10][10] , int n)
{
    for(int k = 1 ; k<=n ; k++)
    {
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ; j<=n ; j++)
            {
                distances[i][j] = min(distances[i][j] , distances[i][k] + distances[k][j]);
            }
        }
    }
}
int main()
{
    int distances[10][10] = {0} , n;

    cout<<"Enter number of cities"<<endl;
    cin>>n;

    cout<<"Enter distances between cities (use 999 for infinity)"<<endl;
    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=n ; j++)
        {
            cin>>distances[i][j];
        }
    }

    floyd(distances , n);

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=n ; j++)
        {
            cout<<distances[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}