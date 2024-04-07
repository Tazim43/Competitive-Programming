#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
using namespace std; 

template <typename T>
class SparseTable
{
	public:
	 vector<T> lg, two;
    vector<vector<T>> st;
    void build(vector<int> &aa, int state)
    {
        int n = (int)aa.size();
        lg.resize(n + 1);
        lg[0] = lg[1] = 0;
        for (int ii = 2; ii <= n; ++ii)
            lg[ii] = lg[ii / 2] + 1;
        two.resize(lg[n] + 1);
        for (int ii = two[0] = 1; ii <= lg[n]; ++ii)
            two[ii] = two[ii - 1] * 2;
        st.resize(n, vector<T>(lg[n] + 1));
        for (int ii = 0; ii < n; ii++)
            st[ii][0] = aa[ii];
        for (int jj = 1; jj <= lg[n]; jj++)
            for (int ii = 0; ii + two[jj] <= n; ii++)
            {
                T x = st[ii][jj - 1];
                T y = st[ii + two[jj - 1]][jj - 1];
                st[ii][jj] = state ? max(x, y) : min(x, y);
            };
    }
    T query(int L, int R, int state)
    {
        int jj = lg[(R - L + 1)];
        T x = st[L][jj];
        T y = st[R - two[jj] + 1][jj];
        return state ? max(x, y) : min(x, y);
    }
};

int main() {
	FAST_IO;
	// start
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i=0; i<n; i++){
		cin>>ar[i];
	}

	SparseTable<int> ST;

	ST.build(ar, 1);

	



	return 0;
}
