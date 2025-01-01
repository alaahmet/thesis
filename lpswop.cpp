#include <bits/stdc++.h>
using namespace std;

int d;
random_device rd;
mt19937 mt(rd() ^ chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist;
int64_t basisChanges;

// given a Basis B, return the optimal solution X to the constraints in B
vector<int> basisToX(set<int> B) {
    assert(B.size() == d);
    vector<int> X(d, 0);
    bool h1 = B.find(1) != B.end();
    if(h1) X[0] = 1;
    for(int i = 1; i < d; i++) {
        bool h0 = B.find(2 * i) != B.end();
        bool h1 = B.find(2 * i + 1) != B.end();
        if(h0 && h1) X[i] = max(X[i - 1], 1 - X[i - 1]);
        else if(h0) X[i] = 1 - X[i - 1];
        else if(h1) X[i] = X[i - 1];
    }
    return X;
}


// Returns Basis(B \cup h)
set <int> UpdateBasis(set <int> B, int h) {
    assert(B.find(h) == B.end());
    int cmpl;
    if(h % 2 == 0) cmpl = h + 1;
    if(h % 2 == 1) cmpl = h - 1;
    B.erase(cmpl);
    B.insert(h);
    assert(B.size() == d);
    return B;
}

// Returns True if h violates constraints in B
bool violates(int h, set<int> B) {
    assert(B.find(h) == B.end());
    int cmpl;
    if(h == 1) return true;
    else if(h == 0) return false;
    vector <int> X = basisToX(B);
    int idx = h / 2;
    if((h % 2 == 0) ^ (X[idx - 1] == 1)) return true;
    return false;
}

set<int> OnePermLp(vector<int> H, set<int> B) {
    shuffle(H.begin(), H.end(), mt);
    while(true) {
        int j = 0; // min j such that H_j which violates the constraints in B
        while(j < H.size() && (B.find(H[j]) != B.end() || !violates(H[j], B))) {
            // we increase j when either H[j] is in B OR H[j] doesn't violate B
            j++;
        }
        if(j == H.size()) break;
        B = UpdateBasis(B, H[j]);
        basisChanges++;
    }
    return B;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <d>" << endl;
        return 1;
    }
    // Define the problem constraints:
    // 0: h^0_1: x1 >= 0
    // 1: h^1_1: x1 >= 1
    // 2: h^0_2: x2 >= 1 - x1
    // 3: h^1_2: x2 >= x1
    // 4: h^0_3: x3 >= 1 - x2
    // 5: h^1_3: x3 >= x2
    // ...
    // 2d: h^1_d: xd >= 1 - x{d-1}
    
    d = stoi(argv[1]);
    vector<int> H;

    for (int i = 0; i < 2 * d; i++) {
        H.push_back(i);
    }

    basisChanges = 0;

    // random initial regular basis
    set<int> T;
    dist = uniform_int_distribution<int>(0, 1);    
    for(int i = 0; i < d; i++) {
        if(dist(mt) == 0) T.insert(2 * i);
        else T.insert(2 * i + 1);
    }
    // random initial regular basis

    assert(T.size() == d);

    set<int> B = OnePermLp(H, T);

    vector<int> x = basisToX(B);

    for(int i = 0; i < d; i++) {
        assert(x[i] == 1);
    }

    cout << basisChanges << endl;

    return 0;
}



