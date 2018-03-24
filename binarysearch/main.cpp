#include <iostream>

using namespace std;

int main() {
    //очень простая задача
    // x y время печати каждого принтера
    long N = 4, K = 11, x = 0, y = 0;
    long l = 1, r = 0 , m = 0;
    int arr[] = {802, 743, 457, 539};
    int max;

    for (int i = 0; i < N - 1; i++) {

        if (arr[i] > arr[i + 1]) {
            max = arr[i];
        }
    }
    r = max;
    while (l < r - 1){

       int sum = 0;
       m = (l + r)/2;

       for (int i = 0; i < N; i++) {
         sum += arr[i] / m ;
       }

        if (sum < K) {
            r = m;
        } else {
            l = m;
        }
   }
    cout  << l;
    //for
//    if (x > y)
//    {
//        swap(x,y);
//    }
//    N--;
//    long l = 0, r = y * N, m = 0;
//    while(l < r - 1){
//        m = (l + r)/2;
//        if (m/x + m/y < N) {
//            l = m;
//        } else {
//            r = m;
//        }
//    }
//    cout  << r + x;
    // std::cout << "Hello, World!" << std::endl;

    //трубы
    //  int N(0), K(0);



    return 0;
}