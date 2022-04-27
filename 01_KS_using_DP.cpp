#include<bits/stdc++.h>
using namespace std;


int main(){
    int P[5] =  {1,2,5,6};
    int wt[5] = {2,3,4,5};
    int M = 8;
    int n = 4;
    int k[5][9];

    for (int i=0; i<=n; i++) {
      for (int w=0; w<=M; w++) {
         if (i==0 || w==0)
         k[i][w] = 0;
         else if (wt[i-1]<=w)
            k[i][w] = max(P[i-1]+k[i-1][w - wt[i-1]], k[i-1][w]);
         else
        k[i][w] = k[i-1][w];
      }
   }
   cout<<"max profit is : "<<k[n][M];

}