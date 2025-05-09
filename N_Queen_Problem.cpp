#include <iostream>
using namespace std;
int NQueen(int r ,int n);
int x[20],count;
int place(int  r,int c)
{  int i;
	for(i=1;i<=r-1;i++)
	{
		if(x[i]==c)//column
		{
			return 0;
		}
		else
		{
			if(abs(x[i]-c)==abs(i-r))//diagonal
			{
			return 0;
			}
		}
	}
	return 1;
}
void print(int n) {
    cout << "\n\nSolution " << ++count << ":\n\n";

    // Print column headers
    cout << "   ";
    for (int i = 1; i <= n; i++)
        cout << " " << i << " ";
    cout << "\n";

    for (int i = 1; i <= n; i++) {
        // Print row number
        cout << " " << i << " ";

        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << " Q ";
            else
                cout << " - ";
        }
        cout << "\n";
    }
}


int NQueen(int r,int n)
{
	int c,i;
    for(c=1;c<=n;c++)
    {
    	   if(place(r,c))
    	   {
    		   x[r]=c;
    		   if(r==n)
    		   {
    			   print(n);
    		   }
    		   else
    		   {
    			   NQueen(r+1,n);
    		   }
    	   }
   }
    return 0;
}

int main() {
	int i,j,n,r;
		cout<<"\n ****** N-Queen Solution *****\n";
		cout<<"\n Enter the Queen:-\n";
		cin>>n;
		NQueen(1,n);

	return EXIT_SUCCESS;
}
