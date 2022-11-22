#include <iostream>
using namespace std;
int Recusivefibonacci(int n)
{
	if(n == 0)
	{
		return 0;
	}
	else if(n == 1)
	{
		return 1;
	}
	return Recusivefibonacci(n-1)+Recusivefibonacci(n-2);
}

void IterativeFibonacci(int n)
{
	int fib[n+1];
	fib[0] = 0;
	if(n == 0)
	{
		cout<<fib[n]<<" ";
		return;
	}
	fib[1] = 1;
	for(int i = 2; i<=n; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	if(n == 1 || n == 2)
	{
		for(int i = 0; i<=n; i++)
		{
			cout<<fib[i]<<" ";
		}
	}
	else
	{
		for(int i = 0; i<=n; i++)
		{
			cout<<fib[i]<<" ";
		}
	}
	// int a = 0, b=1, c;
	// for(int i =2; i<=n;i++)
	// {
	// 	cout<<a<<" ";
	// 	c = a+b;
	// 	a = b;
	// 	b = c;
	// }
	// cout<<a;
	// cout<<" Fibonacci Number at index "<<n<<" is "<<c;
}

int main()
{
	int n;
	cout<<"\nEnter the index whose fibonacci number has to be find: ";
	cin>>n;
	int choice;
	cout<<"\n\tEnter 1 for using Recursive approach";
	cout<<"\n\tEnter 2 for using Iterative approach";
	cout<<"\n\nEnter choice: ";
	cin>>choice;
	switch(choice)
	{
	case 1:
		for(int i = 0; i<=n; i++)
		{
			cout<<Recusivefibonacci(i)<<" ";
		}

		cout<<"\nFibonacci number at index "<<n<<" is "<<Recusivefibonacci(n);
		break;
	case 2:
		IterativeFibonacci(n);
		break;
	default:
		cout<<"\n\tInvalid input!!";
		break;
	}
	cout<<endl;
	return 0;
}


