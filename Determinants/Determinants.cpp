#include <iostream>
using namespace std;

// n is matrix size
int det(int* matrix, int n)
{
    if (n == 1) return *(matrix);
    if (n == 2) return *(matrix) * *(matrix + 3) - *(matrix + 1) * *(matrix + 2);
    int d = 0, s = 1;

    int* new_matrix = new int[(n - 1) * (n - 1)];

    //row cofactor along row 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            bool found = false;
            for (int k = 0; k < n ; k++)
            {
                if (k == i) {
                    found = true;
                    continue;
                }
                if (!found)
                    *(new_matrix + (j - 1) * (n - 1) + k) = *(matrix + j * n + k);
                else
                    *(new_matrix + (j - 1) * (n - 1) + k-1) = *(matrix + j * n + k);

            }
        }

        d += s * *(matrix + i) * det(new_matrix, n-1);
        s = -s;
    }

    delete[] new_matrix;
    return d;
}


int main()
{
    // input function [done]
    // input n  [done]
    // input coefficient matrix [done]
    // input solution vector [done]
    // calcuate det of og matrix and save it [done]
    // test if not invertible i.e. det == 0, then exit the program [done]
    // else create n-1 * n-1 matrix and (Malak)
    // for n times, switch the ith row with the solution vector and calculate the det (Malak)
    // divide by original det and save it in a 1d array (ghada)
    // output in turn (ghada)

    int n, det_original;
    cout << "Please input the size of your matrix: ";
    cin >> n;

    int* matrix = new int[n * n];

    cout << "Please input the elements of your matrix in row order, separated by spaces or escapes:\n ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> *(matrix + i * n + j);

    det_original = det(matrix, n);

    if (det_original == 0) {
        cout << "Matrix is not invertible. Cannot use cramer's rule to solve it\n\nexiting program...\n\n";
        return 1;
    }

    int* solution = new int[n];
    int* output = new int[n];

    cout << "Please input your solution vector: ";
    for (int i = 0; i < n; i++)
        cin >> *(solution + i);

    cout << "\n";

    delete[] matrix;
    delete[] solution;
    delete[] output;
    return 0;
}



/*for (int j = 0; j < n - 1; j++)
{
    for (int k = 0; k < n - 1; k++)
        cout << *(new_matrix + j * (n - 1) + k) << ' ';
    cout << "\n";
}*/
