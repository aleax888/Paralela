#include <iostream>
#include <ctime>
using namespace std;
// Declaration variables
double **A, *x, *y;


double first_loop(int MAX)
{
	// Get time
	clock_t begin, end;
	// First loop (i,j) -> each row
	begin = clock();
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			y[i] += A[i][j] * x[j];
	end = clock();
	return (double(end - begin) / CLOCKS_PER_SEC);
}

double second_loop(int MAX)
{
	// Get time
	clock_t begin, end;
	// Second loop (j,i) -> each column
	begin = clock();
	for (int j = 0; j < MAX; j++)
		for (int i = 0; i < MAX; i++)
			y[i] += A[i][j] * x[j];
	end = clock();
	return (double(end - begin) / CLOCKS_PER_SEC);
}


int main()
{
	
	// Definition variables
	const int MAX = 10000, n = 10, aux = MAX/n;
	A = new double*[MAX];
	x = new double[MAX * MAX]();
	for (int i = 0; i < MAX; ++i)
	{
		A[i] = x;
		x += MAX;
	}
	x = new double[MAX]();
	y = new double[MAX]();

	cout << "First Loop:" << endl;
	for (int i = 1; i <= n; ++i)
		cout << first_loop(aux * i) << endl;

	cout << "Second Loop:" << endl;
	for (int i = 1; i <= n; ++i)
		cout << second_loop(aux * i) << endl;
	
}