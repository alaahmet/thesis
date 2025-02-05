#include <bits/stdc++.h>
using namespace std;

int d;

bitset<12> B;
bitset<6> X;

int64_t dp[7][64];


int64_t factorial[20];

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

void compute(int d) {
    assert((d < 7) && "bitset size was set for d at most 6");

    vector<int> H(2*d);
    iota(H.begin(), H.end(), 0);

    int64_t total_sum = 0LL;
    int64_t div = (1 << d) * factorial[2 * d];

    int bitmasks = (1 << d);
    vector<pair<int, int64_t>> memo_vector;


    for(int bitmask = 0; bitmask < bitmasks; bitmask++) {
        if((bitmask & 1) == 1) {
            // starts with 1
            dp[d][bitmask] = dp[d - 1][bitmask >> 1] * (2LL * d) * (2LL * d - 1);
        }
        else {
            do {
                int64_t basisChanges = 0;
                B.reset();
                X.reset();
                for(int i = 0; i < d; i++) {
                    if((bitmask & (1 << i)) == 0) {
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

                while(true) {
                    int j = 0;
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
                dp[d][bitmask] += basisChanges;
            }
            while(next_permutation(H.begin(), H.end()));
        }
        total_sum += dp[d][bitmask];
        memo_vector.push_back({bitmask, dp[d][bitmask]});
    }
    double Expected_Value = (double)total_sum / div;    
    cout << "Expected Value for d=" <<  d << ": " << Expected_Value << endl;


    sort(memo_vector.begin(), memo_vector.end(), [](const pair<int, int64_t>& a, const pair<int, int64_t>& b) {
        return a.second < b.second;
    });

    cout << "Basis: ";
    for (const auto& p : memo_vector) {
        cout << "| ";
        for (int i = 0; i < d; i++) {
            cout << ((p.first & (1 << i)) ? 1 : 0);
            if (i < d - 1) cout << ",";
        }
        cout << " ";
    }
    cout << "|\n";

    cout << "|";

    for(int i = 0; i <= (1<<d); i++) {
        cout <<"--|";
    }
    cout << '\n';

    cout << "Expected Number of Basis Changes: ";
    double two2dfac = factorial[2 * d];
    for (const auto& p : memo_vector) {
        double exp_value = (double)p.second / two2dfac;
        cout << "| " << exp_value << " ";
    }
    cout << "|\n";
    


}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <D>" << endl;
        return 1;
    }
    
    int D = std::stoi(argv[1]);
    factorial[0] = 1;
    for(int i = 1; i < 20; i++) {
        factorial[i] = i * factorial[i - 1];
    }
    for(d = 1; d <= D; d++) {
        compute(d);
    }
}
