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

we can use 16 to check if at 4th place there is 0 or 1 in a number x by simply doing and with 16.
example
	   10000
	&1011101
	--------
	 1010000
	--------


*/

void convertToBinary(int no){
	for
}
#include <iostream>
using namespace std;
int main(){
	int x;
	cin >> x;
	for(int i=0; i<=x; i++){
		if((x&(1 << i)) !=0) cout << i;
	}
	cout<<endl;
	for(int i=x; i>=0; i--){
		if((x&(1 << i)) !=0) cout << 1;
		else cout << 0;
	}
}