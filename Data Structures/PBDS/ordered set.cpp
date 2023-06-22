#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> // 1
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 
using namespace __gnu_pbds; //2 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; //3

// less_equal , less, greater, greater_equal 



int main() {
   FAST_IO;
   // start

   indexed_set st;

   st.insert(1);
   st.insert(2);

   cout<<st.order_of_key(2)<<"\n"; // values less than 2
   cout<<*st.find_by_order(1)<<"\n"; // value of 1 th index

   


   return 0;
}
