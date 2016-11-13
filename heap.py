import math
import sys
from time import time
import random
def heapsort(a, count):
	heapify(a, count)
	end = count - 1
	while (end > 0):
		swap(a,end,0)
		end = end - 1
		siftdown(a, 0, end)
def heapify(a, count):
	start = parent(count - 1)
	while (start >= 0):
		siftdown(a, start, count - 1)
		start = start - 1
def siftdown(a, start, end):
		root = start
		while (left(root) <= end):
			child = left(root)
			_swp = root
			if a[_swp] < a[child]:
				_swp = child
			if (child + 1 <= end and a[_swp] < a[child + 1]):
				_swp = child + 1
			if _swp == root:
				return	
			else:
				swap(a,root,_swp)
				root = _swp
def swap(a,i,j):
	a[i],a[j] = a[j],a[i]
	return
def siftup(a, start, end):
	child = end
	while child > start:
		pa = parent(child)
		if a[pa] < a[child]:
			swap(a,pa,child)
			child = pa
		else:
			return
def parent(i):
	return int(math.floor((i-1)/2))
def left(i):
	return 2*i + 1
def right(i):
	return 2*i + 2
start = time()
a=[]
for i in range(int(sys.argv[1])):
	a.append(i)

random.shuffle(a)
heapsort(a,int(sys.argv[1]))
print a
end = time()
print ("this took " + str(end - start))
