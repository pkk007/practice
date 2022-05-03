#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

int main(){
    int n;
    printf("enter the number of processs : ");
    scanf("%d",&n);
    int tq, count=0, temp,sq;
    int bt[n], tat[n], wt[n], rem_bt[n];
    float avgtat=0, avgwt = 0;

    printf("\nenter the burst time : \n");
    //input burst time
    for(int i=0; i<n; i++){
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("enter the time quantum : ");
    scanf("%d",&tq);

    int t = 0; // Current time

    while (1) {
       bool complete = true;
      // Traverse all processes one by one repeatedly
      for (int i = 0 ; i < n; i++) {
         if (rem_bt[i] > 0) {
            complete = false; // complete =  false means There is a pending process
            if (rem_bt[i] > tq) {
               t += tq;
               rem_bt[i] -= tq;
            }
            else {
               t = t + rem_bt[i];
               // Waiting time is current time minus time used by this process
               wt[i] = t - bt[i];
               // As the process gets fully executed
               // make its remaining burst time = 0
               rem_bt[i] = 0;
            }
         }
      }
      // If all processes are done
      if (complete == true)
         break;
   }

   //calculate TAT
   for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];

    printf("BT\t TAT\t WT\n");
    for(int i=0; i<n; i++){
         printf("%d\t %d\t %d\n", bt[i], tat[i], wt[i]);
    }
    for(int i=0; i<n; i++){
        avgtat = avgtat + tat[i];
        avgwt = avgwt + wt[i];
    }
    printf("\n AVERAGE TAT : %f",avgtat/n);
    printf("\n AVERAGE WT : %f",avgwt/n);
}