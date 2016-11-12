import sys
from time import time
def fib(n):
	a,b = 1,1
	for i in range(3,n+1):
		c = a + b
		a = b
		b = c
	return b

c = int(sys.argv[1])
start = time()
for i in range(0,c):
	print (fib(i))
	print("")

end = time()
print ("this took " + str(end - start))
