https://www.geeksforgeeks.org/find-two-numbers-sum-xor/


Given the sum and xor of two numbers X and Y s.t. sum and xor \in [0, 2^{64}-1], we need to find the numbers minimizing the value of X.


So we can find A = (S – X)/2.

Once we find A, we can find all bits of ‘a’ and ‘b’ using below rules.

If X[i] = 0 and A[i] = 0, then a[i] = b[i] = 0. Only one possibility for this bit.
If X[i] = 0 and A[i] = 1, then a[i] = b[i] = 1. Only one possibility for this bit.
If X[i] = 1 and A[i] = 0, then (a[i] = 1 and b[i] = 0) or (a[i] = 0 and b[i] = 1), we can pick any of the two.
If X[i] = 1 and A[i] = 1, result not possible (Note X[i] = 1 means different bits)
Let the summation be S and XOR be X.




// CPP program to find two numbers with 
// given Sum and XOR such that value of 
// first number is minimum. 
#include <iostream> 
using namespace std; 

// Function that takes in the sum and XOR 
// of two numbers and generates the two 
// numbers such that the value of X is 
// minimized 
void compute(unsigned long int S, 
			unsigned long int X) 
{ 
	unsigned long int A = (S - X)/2; 

	int a = 0, b = 0; 

	// Traverse through all bits 
	for (int i=0; i<8*sizeof(S); i++) 
	{ 
		unsigned long int Xi = (X & (1 << i)); 
		unsigned long int Ai = (A & (1 << i)); 
		if (Xi == 0 && Ai == 0) 
		{ 
			// Let us leave bits as 0. 
		} 
		else if (Xi == 0 && Ai > 0) 
		{ 
			a = ((1 << i) | a); 
			b = ((1 << i) | b); 
		} 
		else if (Xi > 0 && Ai == 0) 
		{ 
			a = ((1 << i) | a); 

			// We leave i-th bit of b as 0. 
		} 
		else // (Xi == 1 && Ai == 1) 
		{ 
			cout << "Not Possible"; 
			return; 
		} 
	} 

	cout << "a = " << a << endl << "b = " << b; 
} 

// Driver function 
int main() 
{ 
	unsigned long int S = 17, X = 13; 
	compute(S, X); 
	return 0; 
} 
