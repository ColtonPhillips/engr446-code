#include <omp.h>
#include <stdlib.h>
#include <iostream>
	
typedef unsigned long long int mylongint;
mylongint fib(int x) {
	mylongint a = 1, b = 1;
	for (mylongint i = 3; i <= x; i++) {
		mylongint c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main(int argc, char ** argv) {

	double start = omp_get_wtime();
	unsigned int n = atoi(argv[1]);
	for (unsigned int i = 0; i < n; i++) {
		std::cout << fib(i) << "\n" << std::endl;
	}
	double end = omp_get_wtime();
	double diff = end-start;
	std::cout << "This took " << diff << " seconds to execute!";
}
