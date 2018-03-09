#include <iostream>
#include<vector>

using namespace std;

struct DSU {
    vector<int> parent;


    DSU(int size) {
        parent.resize(size, -1);
    }

    void hang(int v, int p) {
        parent[v] = p;

    }

    void print() {
        cout << "digraph g {" << endl;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] != -1) {
                cout << i << "->" << parent[i] << endl;
            } else {
                cout << i << endl;
            }
        }
        cout << "}" << endl;
    }

    void reset(int n) {

        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                hang(i, -1);
                cout << "reset done" << endl;
                break;
            }

        }

        for (int i = n + 1; i < parent.size(); i += 1) {
            if (find(i) < n) {
                hang(i, -1);
            }
        }
    }

    void check(int j, int k) {
        if (find(j) == find(k)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    void join(int j, int k) {
        if (find(j) == find(k)) {
            cout << "already " << j << " " << k << endl;
        } else {
            hang(find(j), find(k));
        }
    }

    int find(int v) {
        int r = v;
        while (parent[r] != -1) {
            r = parent[r];
        }
        while (parent[v] != -1) {
            int temp = v;
            v = parent[v];
            parent[temp] = r;
        }
        return v;
    }
};


int main() {

    DSU newdsu(16);
    newdsu.reset(15);
    newdsu.join(14, 10);
    newdsu.join(13, 8);
    newdsu.join(0, 9);
    newdsu.join(8, 3);
    newdsu.join(4, 1);
    newdsu.join(10, 5);
    newdsu.join(8, 4);
    newdsu.check(2, 11);
    newdsu.join(4, 1);
    newdsu.join(2, 6);
    newdsu.check(9, 1);
    newdsu.join(6, 5);
    newdsu.check(10, 5);
    newdsu.print();

    return 0;
}