#include <iostream>
using namespace std;

void pushZeroesEnd(int *input, int size)
{
    //Write your code here
    int nextzero=0;
    for(int i=0;i<size;i++)
    {
        if(input[i]!=0)
        {
            int temp=input[i];
            input[i]=input[nextzero];
            input[nextzero]=temp;
            nextzero++;
        }
    }
    
}

int main()
{

	int t;
	cin >> t;
	
	while (t--)
	{

		int size;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}
