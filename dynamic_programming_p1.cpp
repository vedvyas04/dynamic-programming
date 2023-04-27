#include <iostream>


using namespace std;


int A[100];


// Normal recursive function
int FibonacciR(int r)
{
    if(r <= 1)
    {
        return r;
    }
    else
    {
        return FibonacciR(r-1) + FibonacciR(r-2);
    }  
}


// Recursive function that uses dynamic programming
int FibonacciD(int d)
{
    if(A[d] != -1)
    {
        return A[d];
    }
    else if(d <= 2)
    {
        A[d] = 1;
    }
    else
    {
        A[d] = FibonacciD(d-1) + FibonacciD(d-2);
    }
    
    // Print the value
    return A[d];
}


// Main function from the assignment pdf
int main() 
{ 
    int n; //The user inputs this number to calculate its Fibonacci sequence 
    cout << "n = "; 
    cin >> n; 

    // initialize all elements in array A to an invalid Fibonacci value 
    for (int i = 0; i <= n; i++)  
        A[i] = -1; 

    //Find Fibonacci sequence n using the Dynamic programming function 
    cout << " FibonacciD(n) = " << FibonacciD(n); 

    //Find Fibonacci sequence n using the recursive only function 
    cout << "\n FibonacciR(n) = " << FibonacciR(n); 

    return 0; 
}