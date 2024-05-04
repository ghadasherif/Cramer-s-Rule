#include <iostream>
using namespace std;

// n is matrix size
//The function that Calculates the determinant of any n*n matrix
double det(double* matrix, int n)
{
    if (n == 1) return *(matrix);
    if (n == 2) return *(matrix) * *(matrix + 3) - *(matrix + 1) * *(matrix + 2);
    int d = 0, s = 1;

    double* new_matrix = new double[(n - 1) * (n - 1)];

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
//The function that changes the original determinant by the solution vector
void changematrix(double* matrix,double* b,double* temporary_det, int n, int k)
{
    double* temporary_matrix = new double[n*n];
    for(int i=0; i<n*n; i++)
{

   temporary_matrix[i] = matrix [i];

}
for(int i=0; i<n; i++)
{

    temporary_matrix[(i*n)+k] =b[i];

}
temporary_det[k] = det(temporary_matrix, n);
delete[] temporary_matrix;
}

int main()
{
    // input function [done]
    // input n  [done]
    // input coefficient matrix [done]
    // input solution vector [done]
    // calcuate det of og matrix and save it [done]
    // test if not invertible i.e. det == 0, then exit the program [done]
    // for n times, switch the ith row with the solution vector and calculate the det (done)
    // divide by original det and save it in a 1d array (ghada)
    // output in turn (ghada)

    int n;
    double det_original;
    cout << "Please input the size of your matrix: ";
    cin >> n;

    double* matrix = new double[n * n];
    double* temporary_det= new double[n];

    cout << "Please input the elements of your matrix in row order, separated by spaces or escapes:\n ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> *(matrix + i * n + j);

    det_original = det(matrix, n);

    if (det_original == 0) {
        cout << "Matrix is not invertible. Cannot use cramer's rule to solve it\n\nexiting program...\n\n";
        return 1;
    }

    double* solution = new double[n];
    double* output = new double[n];

    cout << "Please input your solution vector: ";
    for (int i = 0; i < n; i++)
        cin >> *(solution + i);

    cout << "\n";
    // A function that stores the values for temporary determinants in the array temporary_det
    for(int i=0; i<n; i++)
    {
      changematrix(matrix, b,temporary_det, n, i);

    }

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
