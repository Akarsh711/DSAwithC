#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long int step_subtractor(long int a,long int n,long int d,long int df,long int D){
		long int block_total = a+(n-1)*df;
		long int step = (n*d)-D;
		long int single_size = block_total/d;
		long int out =(single_size*step);
		return out;
	}
int main(){
	// int t; cin>>t;
 //    long int D,d,P,Q;
    
	// while(t--){
	// 	cin>>D>>d>>P>>Q;
		
	// 	long int total=0;
	// 	int inital_rate=0;
	// 	bool flag = false;
	// 	long int q = Q;
		
	// 	for(int j=0; j<D; ++j){
	// 		if(j%d==0 && j!=0){
	// 			inital_rate++;
	// 			q = inital_rate*Q;
	// 			flag = true;
	// 		}
 //            if(flag==true)
	// 		    total+=(P+q);
	// 		else
	// 		    total+=P;
	// 	}
	// 	cout<<total<<endl;
	// }
	int t;
	cin>>t;
	while(t--){
    	long int D, d;
    	long int Q, P;
    	cin>>D>>d>>P>>Q;
    	long int a =P*d;
    	float div_res = (float)D/(float)d;
    // 	cout<<div_res<<endl;
    	long int n = ceil(div_res);
    	// cout<<n;
    	long int df = Q*d;
    	
    
    	// need to find n
    	long int sum = (n*(2*a+(n-1)*df))/2;
    	// cout<<sum;
    	
    
    	long int to_minus = step_subtractor(a, n, d, df, D);
    	cout<<sum-to_minus<<endl;
	}
}	