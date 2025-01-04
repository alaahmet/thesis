#include <bits/stdc++.h>
using namespace std;

#ifndef DVAL
    #define DVAL 10
#endif

static const int d = DVAL;

random_device rd;
mt19937 mt(rd() ^ chrono::steady_clock::now().time_since_epoch().count());
int64_t basisChanges = 0;

bitset<2 * d> B;

bitset<d> X;

// Returns Basis(B ∪ {h} \ {complement-of-h}), updating X incrementally. 
// We'll recompute X starting from the index affected by 'h' to the end.
inline void UpdateBasisAndX(int h) {
    int cmpl = (h % 2 == 0) ? (h + 1) : (h - 1);
    B.reset(cmpl); // complementary
    B.set(h);
    int start = h / 2;
    if(start == 0) {
        X.set(0, B.test(1) ? 1 : 0);
        start = 1; 
    }
    for(int i = start; i < d; i++) {
        if(B.test(2*i)) {
            X.set(i, 1 - X[i - 1]);
        } 
        else {
            X.set(i, X[i - 1]);
        }
    }
}

// Returns true if constraint h *violates* the current solution X
inline bool violates(int h) {
    if(h == 0) {
        return false;
    }
    if(h == 1) {
        return true;
    }
    int idx = h / 2;
    if((h % 2 == 0) ^ (X.test(idx - 1))) return true;
    return false;
}

int main() {

    // Define the problem constraints:
    // 0: h^0_1: x1 >= 0
    // 1: h^1_1: x1 >= 1
    // 2: h^0_2: x2 >= 1 - x1
    // 3: h^1_2: x2 >= x1
    // 4: h^0_3: x3 >= 1 - x2
    // 5: h^1_3: x3 >= x2
    // ...

    vector<int> H(2*d);
    iota(H.begin(), H.end(), 0);

    B.reset();
    X.reset();
    auto dist = uniform_int_distribution<int>(0, 1);
    // For each i in [0..d-1], set either 2*i or 2*i+1 in random
    for(int i = 0; i < d; i++) {
        if(dist(mt) == 0) {
            B.set(2*i);
        } else {
            B.set(2*i + 1);
        }
    }

    // build X from B
    X.set(0, B.test(1) ? 1 : 0);
    for(int i = 1; i < d; i++) {
        if(B.test(2*i)) {
            X.set(i, 1 - X[i - 1]);
        } else {
            X.set(i, X[i - 1]);
        }
    }

    // The OnePermLP
    shuffle(H.begin(), H.end(), mt);
    while(true) {
        int j = 0; // min j s.t. H[j] not in B and violates solution X
        while(j < 2*d && ( B.test(H[j]) || !violates(H[j]) )) {
            j++;
        }
        if(j == 2*d) {
            break;
        }
        UpdateBasisAndX(H[j]);
        basisChanges++;
    }


    for(int i = 0; i < d; i++) {
        assert(X[i] == 1);
    }

    cout << basisChanges << "\n";
    return 0;
}
