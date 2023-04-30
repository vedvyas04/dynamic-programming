#include <iostream>
#include <time.h>
#include <math.h>


using namespace std;


// Function to find maximum of two integers
int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}


// Function to find maximum revenue
int cutrod(int price[], int size)
{
    int dynamic[size+1];
    dynamic[0] = 0;
    int i, j;

    // Insert values in dynamic[]
    for (i = 1; i<=size; i++)
    {
        int max_dynamic = INT_MIN;

        for (j = 0; j < i; j++)
        {            
            max_dynamic = max(max_dynamic, price[j] + dynamic[i-j-1]);
        }
        dynamic[i] = max_dynamic;
    }

    // Return the final entry
    return dynamic[size];
}


// Function to recursively cut the rod
int cutrodR(int price[], int size)
{
    if (size <= 0)
        return 0;

    int max_recursive = INT_MIN;
  
    // Recursive calls
    for (int i = 0; i<size; i++)
        max_recursive = max(max_recursive, price[i] + cutrodR(price, size-i-1));

    return max_recursive;
}


// Main function
int main()
{
    int n;
    int i=0;
    clock_t t1;
    clock_t t2;

    cout<<"Enter the size of the rod: ";
    cin>>n;

    int revenue[n];
    
    // Calculating the price 
    for(int L=1;L<=n;L++)
    {
        if(L==1)
        {
            revenue[i]=2;
        }
        else if(1<L<n)
        {
            revenue[i]=floor(L*2.5);
        }
        else if(L==n)
        {
            revenue[i]=(L*2.5)-1;
        }
        i++;
    }

    int size = sizeof(revenue)/sizeof(revenue[0]);

    // Time for just recursive
    t1 = clock();
    cout<<"\nDynamic Maximum Revenue is: "<< cutrod(revenue, size)<<endl;
    t1 = clock() - t1;
    cout<<"Time: "<<((float)t1)/(CLOCKS_PER_SEC*1000000)<<" microseconds"<<endl;

    // Time for dynamic
    t2 = clock();
    cout<<"\nRecursive Maximum Revenue is: "<< cutrodR(revenue, size);
    t2 = clock() - t2;
    cout<<"\nTime: "<<((float)t2)/(CLOCKS_PER_SEC*1000000)<<" microseconds"<<endl;

    return 0;
}