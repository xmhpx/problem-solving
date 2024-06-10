// Linear Sieve of Eratosthenes
// copy the LinearSieve class.
// instantiate a LinearSieve with n = maxN.
// pr = primes <= maxN in ascending order
// lp[i] = smallest prime factor of i
// based on cp-algorithms

#include <bits/stdc++.h>

using namespace std;

class LinearSieve{
public:
    vector<int> lp;
    vector<int> pr;

    LinearSieve(){}
    LinearSieve(int n){
        build(n);
    }

    void build(int n){
        pr.clear();
        lp.clear();
        lp.resize(n+1);
        for(int i=2; i <= n; ++i){
            if(lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
            }
            for(int j = 0; i * pr[j] <= n; ++j){
                lp[i * pr[j]] = pr[j];
                if(pr[j] == lp[i]){
                    break;
                }
            }
        }
    }

    vector<int> getPrimes(){
        return pr;
    }

    vector<int> getMinimumPrimeFactors(){
        return lp;
    }
};

int main() {
    const int maxN = 10000000;
    LinearSieve sieve(maxN);
    vector<int> p = sieve.getPrimes();
    cout << p.size() << '\n';
}