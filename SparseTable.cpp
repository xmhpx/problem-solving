#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6+7;
const int maxL = 21;

int n;
int a[maxN];
int mn[maxN][maxL];
int mx[maxN][maxL];

inline int MN(const int& x, const int& y){
    return a[y] < a[x] ? y : x;
}

inline int MX(const int& x, const int& y){
    return a[y] > a[x] ? y : x;
}

inline int getMin(const int& l, const int & r){
    if(r-l == 1)return l;
    int lg = __lg(r-l-1);
    return MN(mn[l+(1<<lg)-1][lg], mn[r-1][lg]);
}

inline int getMax(const int& l, const int & r){
    if(r-l == 1)return l;
    int lg = __lg(r-l-1);
    return MX(mx[l+(1<<lg)-1][lg], mx[r-1][lg]);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    cif(j, maxL){
        cif(i, n){
            if(j == 0)mn[i][j] = mx[i][j] = i;
            else{
                if(i-(1<<(j-1)) < 0){
                    mn[i][j] = mn[i][j-1];
                    mx[i][j] = mx[i][j-1];
                }
                else{
                    mn[i][j] = MN(mn[i][j-1], mn[i-(1<<(j-1))][j-1]);
                    mx[i][j] = MX(mx[i][j-1], mx[i-(1<<(j-1))][j-1]);
                }
            }
        }
    }
}