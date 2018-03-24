using System;

namespace PyramidSort
{
    class Program
    {
        static void Repair(int[] A, int vertex, int length)
        {
            //окучивание засчет внутреннего ремонта
            int left = 0;
            int right = 0;
            
            //если левый потом больше каунт то ремонт можно не делать (нет ни левого ни правого потомка)
            if (2 * vertex + 1 > length)
            {
                return;
            }

            if (2 * vertex + 1 == length)
            {
                left = right = 2 * vertex + 1;
            }
            else
            {
                 left = vertex * 2 + 1;
                 right = vertex * 2 + 2;
            }

            
            int imax = A[left] > A[right] ? left : right;
            
            if (A[imax] > A[vertex])
            {
                int tmp = A[imax];
                A[imax] = A[vertex];
                A[vertex] = tmp;
                Repair(A, imax,length);
            }
            
         
          
        }
        

        static void Main(string[] args)
        {
            int[] A = {17, 2, 6, 21, 9, 1, 3, 5, 7, 8, 0};
            for ( int i = A.Length/2 ; i >= 0; i--)
            {
                Repair(A, i, A.Length - 1);
            }
            for ( int i = 0 ; i < A.Length; i++)
            {
               Console.WriteLine(A[i] + " ");
            }
            
            for ( int i = A.Length - 1; i > 0; i--)
            {
                int temp = A[i];
                A[i] = A[0];
                A[0] = temp;
                
                Repair(A, 0, i - 1);
            }
            
            Console.WriteLine();
            
            for ( int i = 0 ; i < A.Length; i++)
            {
                Console.WriteLine(A[i] + " ");
            }
        }
    }
}