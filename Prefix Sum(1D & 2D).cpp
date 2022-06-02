/* Author: Tazim(The_crawler) */
#include<bits/stdc++.h>

using namespace std;



int main() {
   // start
   int n;
   cin >> n;
   vector<int> ar(n);

   // 1D Prefix sum 
   vector<int> p_sum;
   int sum = 0;
   p_sum.push_back(0); // Making first element 0 to avoiding out of bound error 

   for (int i = 0; i < n; i++) {
      sum += ar[i];
      p_sum.push_back(sum);
   }
   // Answring query : 
   // p_sum[R]-p_sum[L-1] = sum of R to L 

   //===========================================================

   // 2D prefix sum 
   int arr[n][n];

   vector<vector<int>> pf_sum(n + 1, vector<int>(n + 1, 0));
   // Making first row and column 0 to avoiding out of bound error

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> arr[i][j];

         pf_sum[i][j] = arr[i][j] + pf_sum[i - 1][j] + pf_sum[i][j - 1] + pf_sum[i - 1][j - 1];
         /*
            1 2
            3 4
            here prefix sum of 4 = 4 + 2 + 3 - 1
         */
      }
   }

   // Answring query: 
   // area of r1, c1  to  r2, c2
   // area = pf_sum[r2][c2] - pf_sum[r1-1][c2] - pf_sum[r2][c1-1] + pf_sum[r1-1][c1-1]
   /*
      0  0 0 0
      0 |0 0 0|
      0 |0 0 0|
      0 |0 0 0|

   */

   return 0;
}

