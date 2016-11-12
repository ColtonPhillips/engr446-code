#include <omp.h>
#include <stdlib.h>
#include <iostream>
	
int fib(int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	return fib(x-1)+fib(x-2);
}

int main(int argc, char ** argv) {

	double start = omp_get_wtime();
	int n = atoi(argv[1]);
	for (unsigned int i = 0; i < n; i++) {
		std::cout << fib(i) << std::endl;
	}
	double end = omp_get_wtime();
	double diff = end-start;
	std::cout << "This took " << diff << " seconds to execute!";
}
