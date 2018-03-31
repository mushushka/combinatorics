#include <iostream>
#include<vector>

using namespace std;

void repair(vector<int> &v, int vertex, int top) {
    //top номер последнего элемента
    int left = vertex * 2 + 1;
    int right = vertex * 2 + 2;
    if (left > top) {
        return;
    }
    if (left == top) {
        right = left;
    }
    int imax = v[left] > v[right] ? left : right;
    if (v[vertex] < v[imax]) {
        swap(v[vertex], v[imax]);
        repair(v, imax, top);
    }


}

int main() {

    vector<int> A(10);
    for (int i = 0; i < A.size(); i++) {
        A[i] = i;
    }

    for (int i = (int) A.size() / 2; i >= 0; i--) {
        repair(A, i, (int) A.size() - 1);
    }

    for (int i = (int) A.size() - 1; i > 0; i--) {
        swap(A[0], A[i]);
        repair(A, 0, i - 1);
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }

    return 0;
}