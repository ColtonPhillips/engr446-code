#include <iostream>
#include <omp.h>
#include <random>
#include <algorithm>
#include <string>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <math.h>

int parent(int i) { 
	return (int) floor( ((float)(i-1)) / 2);
}

int left(int i) {
	return 2*i + 1;
}

int right(int i) {
	return 2*i + 2;
}

void siftdown(std::vector<int> &a, int start, int end) {
	int root = start;
	while (left(root) <= end) {
		int child = left(root);
		int swap = root;
		if (a[swap] < a[child]) {
			swap = child;
		}
		if (child + 1 <= end && a[swap] < a[child + 1]) {
			swap = child + 1;
		}
		if (swap == root) {
			return;
		}
		else {
			std::swap(a[root],a[swap]);
			root = swap;
		}
	}
}

void heapify(std::vector<int> &a, int count) {
	int start = parent(count - 1);
	while (start >= 0) {
		siftdown(a,start,count - 1);
		start = start - 1;
	}
}

void heapsort(std::vector<int> &a, int count) {
	heapify(a,count);
	int end = count - 1;
	while (end > 0) {
		std::swap(a[end],a[0]);
		end = end - 1;
		siftdown(a, 0, end);
	}
}

void shuffle_heap(std::vector<int> &s) {
	std::random_device rd;
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto engine = std::default_random_engine(seed);
	std::shuffle(std::begin(s), std::end(s), engine);
}

int main (int argc, char ** argv){
	std::vector<int> heap;
	unsigned int c = atoi(argv[1]);
	for (unsigned int i = 0; i < c; i++) {
		heap.push_back(i);
	}
	shuffle_heap(heap);
	double start = omp_get_wtime();
	heapsort(heap,c);
	//for (auto a: heap) {
//		std::cout << a << "\n"; //<< std::endl;
//	}
	double end = omp_get_wtime();
	double diff = end-start;
	std::cout << "This took " << diff << " seconds to execute!";
}
