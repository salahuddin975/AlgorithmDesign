#include <iostream>

#define NIL -1
#define MAX 100

int lookup[MAX];


void initialize()
{
	for (int i = 0; i < MAX; i++){
		lookup[i] = NIL;
	}
}


int fibonacci_memoized(int n)
{
	if (n <= 1)
		lookup[n] = n;
	else
		lookup[n] = fibonacci_memoized(n - 1) + fibonacci_memoized(n - 2);

	return lookup[n];
}


int fibonacci_tabulated(int n)
{
	lookup[0] = 0;
	lookup[1] = 1;

	for (int i = 2; i <= n; i++){
		lookup[i] = lookup[i - 1] + lookup[i - 2];
	}

	return lookup[n];
}


void fibonacci_main()
{
	int n = 40;
	initialize();

	std::cout << n << "th Fibonacci Number: " << fibonacci_memoized(n) << std::endl;
}