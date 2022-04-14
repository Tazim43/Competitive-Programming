/**
Author: Tazim(The_crawler)

Table of content:

line - 14: General Binary search - 1
line - 30: General Binary search - 2
line - 47: Lowerbound implementation - 1
line - 65: Lowerbound implementation - 2
line - 86: Upperbound implementation - 1
line - 103: Upperbound implementation - 2
line - 125: Finding Nth root using BS
line - 147: STL methods

**/

#include<bits/stdc++.h>
using namespace std;

// General BInary Search - 1                                   general - 1
int binarySearch1(vector<int> ar, int query) {
   int lo = 0;
   int hi = ar.size() - 1;
   while (hi - lo > 1)
   {
      int mid = (hi + lo) / 2;
      if (ar[mid] < query)lo = mid + 1;
      else hi = mid;
   }
   if (ar[lo] == query)return lo;
   else if (ar[hi] == query)return hi;
   return -1;
}
// General Binary Search - 2                                  general - 2
int binarySearch2(vector<int> ar, int query) {
   int lo = 0;
   int hi = ar.size() - 1;
   while (lo <= hi)
   {
      int mid = (hi + lo) / 2;
      if (ar[mid] == query)return mid;
      else if (ar[mid] < query)lo = mid + 1;
      else hi = mid - 1;
   }
   return -1;

}

// Lowerbound implementation using binary search -1            lb - 1
int lowerBound1(vector<int> ar, int query) {
   int lo = 0;
   int hi = ar.size() - 1;
   while (hi - lo > 1)
   {
      int mid = (hi + lo) / 2;
      if (ar[mid] < query)lo = mid + 1;
      else hi = mid;
   }
   if (ar[lo] >= query)return lo;
   else if (ar[hi] >= query)return hi;
   return -1;

}

// Lowerbound implementation - 2                               lb - 2
/// *note : This will not work like STL lower_bound  - It will return First occurence of the element ***
int lowerBound2(vector<int> ar, int query) {
   int lo = 0;
   int hi = ar.size() - 1;
   int ans = -1;
   while (lo <= hi)
   {
      int mid = (hi + lo) / 2;
      if (ar[mid] == query) {
         ans = mid;
         hi = mid - 1;
      }
      else if (ar[mid] > query) {
         hi = mid - 1;
      }
      else lo = mid + 1;
   }
   return ans;
}

// Upper bound implementation using binary search - 1                 ub - 1
int upperBound1(vector<int> ar, int query) {
   int lo = 0;
   int hi = ar.size() - 1;
   while (hi - lo > 1)
   {
      int mid = (hi + lo) / 2;
      if (ar[mid] <= query)lo = mid + 1;
      else hi = mid;
   }
   if (ar[lo] > query)return lo;
   else if (ar[hi] > query)return hi;
   else return -1;

}

// Uppebound implementation - 2                                      ub - 2 (read note *)
/// *note: This will not work like STL upper_bound - it will return Last occurence of the element
int upperBound2(vector<int> ar, int query) {
   int lo = 0;
   int hi = ar.size() - 1;
   int ans = -1;
   while (lo <= hi)
   {
      int mid = (lo + hi) / 2;
      if (ar[mid] == query) {
         ans = mid;
         lo = mid + 1;
      }
      else if (ar[mid] > query) {
         hi = mid - 1;
      }
      else lo = mid + 1;
   }
   return ans;
}

// Finding Nth square root using binary search 
double eps = 1e-6; // Modify for desire precission ***
double multiply(double num, int n) {
   double ans = 1;
   for (int i = 0; i < n; i++)ans *= num;
   return ans;
}
// main function for sqrt 
double root(double n, int tm) {
   double lo = 1;
   double hi = n;
   double mid;
   while (hi - lo > eps)
   {
      mid = (hi + lo) / 2;
      if (multiply(mid, tm) > n)hi = mid;
      else lo = mid;
   }
   return lo;
}

/*
STL Binary Search:

1) upper_bound :
   return the strictly greater value of the element for a given Range
   1 2 3 4 5 6
   Ex : upper_bound(v.begin(), v.end(), query) for query = 4 : return 5

2) lower_bound :
   return the equal or strictly greater element for a given Range
   1 2 3 4 5 6
   Ex : lower_bound(v.begin(), v.end(), query) for query = 4 : return 4
*/

int main() {
   int n;
   cin >> n;
   vector<int> ar(n);
   for (int i = 0; i < n; i++)cin >> ar[i];
   int q;
   cin >> q;
   cout << binarySearch1(ar, q) << endl;
   cout << lowerBound1(ar, q) << endl;
   cout << upperBound1(ar, q) << endl;


   return 0;
}