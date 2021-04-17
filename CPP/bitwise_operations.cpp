// In this file I am gonna do bitwise operations. (must read HackerEarth's basic programming tut.)
// A^B  (A XOR B) equivalent (A!=B)
// A|B (A OR B)
// A&B (A AND B)

/*
Bitwise Shift
	LEFT
	1101 (13)
	left shift by 2 (if 2 = k then 2^k will be the multiplier) on left shift, number get's multiply by 2^k. 
	110100 (52)
	it is represented by 
	x << k; so this is equivalent to x.2^k

	RIGHT
	1101
	right shift by 2, Now this divide by 2^k: floor(x/2^k)
	11 
	x>>k;
*/

/*
SPECIAL USAGE
16=10000 as 2^4
1<<4;

we can use 16 to check if at 4th place there is 0 or 1 in a number x by simply doing AND with 16.
example
	   10000
	&1011101
	--------
	 1010000
	--------


*/

// TODO
	// Integer Over flow, Also watch first video of Errichto's DSA as it describe something about overflow in 8:20
#include<iostream>

using namespace std;

namespace bitwise{
	int check_power_of_two(int N){
		// if(N == 0)
		// 	return 45;
		// if(!(N & (N-1)))
		// 	return 1; 
		// else
		// 	return 0;

		// or can ues this single line

		return (N && !(N & (N - 1)));
	}

	int count_one(int N){
		int count = 0;
		while(N){
			N = N&(N-1);
			count++;
		}
		return count;
	}

	int set_or_not(int N, int i){
		if(N&(1<<i))
			return 1;
		else
			return 0;
		// return (N&(1<<i)); not used that as it returned actual number when there is 1 
	}

	void possible_subsets()
    {
    	char A[] = {'a', 'b', 'c'};
    	int N = 3;
        for(int i = 0;i < (1 << N); ++i)
        {
            for(int j = 0;j < N;++j)
                if(i & (1 << j))
                    cout << A[j] << ' ';
            cout << endl;
    	}
    }
}

namespace normalfunctions{
	int check_power_of_two(int N){
		while(N%2 == 0) N = N/2;
		return (N == 1);
	}
}

int main(){
	int N;
	cout <<"Enter N:";
	cin>>N;
	// for(int i=0; i <(1 << N); ++i){ //1 << N is equivalent to 2^N as when we left shift 2 gets multiplies
	// 	cout<< i << endl;
	// }
	cout<< (1<<N)<<endl;
	puts("arrey ye bhi hota hai yahan");
	// 1. Check weather the number is power of 2 or not 
		// We can Either do by (a)dividing 2 again till we'll get 1 or use (b)bitwise
	cout << "Is the power of 2:"<<bitwise::check_power_of_two(N) <<endl;

	// 2. Check how many one's are there in a number if represented as binary
	cout << "The total numbers of one's are:" << bitwise::count_one(N)<<endl;

	// 3. To check wheather number is 1 or 0, (set or not) at specific place i  
	int i;
	cout << "Enter the place for checking weather set or not:";
	cin >> i;
	cout <<"Entered place is :"<< bitwise::set_or_not(N, i);

	// 4. 
	bitwise::possible_subsets();
}