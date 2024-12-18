#include <bits/stdc++.h>
using namespace std;

int d;
random_device rd;
mt19937 mt(rd() ^ chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist;
int64_t basisChanges;

// given a Basis B, return the optimal solution X to the constraints in B
vector<int> basisToX(set<int> &B) {
    vector<int> X(d, 0);
    for (auto a : B) {
        assert(a >= 0 && a < 2 * d);
        if (a == 0)
            X[0] = 0;
        else if (a == 1)
            X[0] = 1;
        else if (a % 2 == 0) {
            int i = a / 2;
            X[i] = 1 - X[i - 1];
        } 
        else if (a % 2 == 1) {
            int i = a / 2;
            X[i] = max(X[i - 1], X[i]); // apply max() in case both constraints for X_i are in the basis B
        }
    }
    return X;
}

// Compute the new basis after adding an element
set<int> findBasis(set<int> B) {
    set <int> newBasis;
    vector<int> x = basisToX(B);
    for(auto h: B) {
        int i = h / 2;
        if(x[i] == 0) continue; // h is not needed in the basis, since x[h] >= 0 always holds
        if(i == 0) {
            assert(h == 1);
            if(x[0] == 1) newBasis.insert(1);
        }
        else if(h % 2 == 0) {
            if(x[i] == 1 - x[i - 1]) newBasis.insert(h);
        }
        else if(h % 2 == 1) {
            if(x[i] == x[i - 1]) newBasis.insert(h);
        }
    }
    return newBasis;
}

bool violates(int h, set<int> B) {
    vector <int> X = basisToX(B);
    B.insert(h);
    vector <int> newX = basisToX(B);
    if(X == newX) return false;
    else return true;
}


set<int> OnePermLp(vector<int> H, set<int> B) {
    shuffle(H.begin(), H.end(), mt);
    while(true) {
        int j = 0; // min j such that H_j which violates the constraints in B
        while(j < H.size() && !violates(H[j], B)) {
            j++;
        }
        if(j == H.size()) break;
        B.insert(H[j]);
        B = findBasis(B);
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

    set<int> emptyBase;

    set<int> B = OnePermLp(H, emptyBase);

    vector<int> x = basisToX(B);

    for(int i = 0; i < d; i++) {
        assert(x[i] == 1);
    }

    cout << basisChanges << endl;

    return 0;
}
