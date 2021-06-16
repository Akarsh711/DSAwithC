// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int t; cin>>t;
// 	vector<vector<int>> arr(t);
// 	vector<int> op(t, 0);
	
//     int i =0;
//     unsigned int D,d,P,Q;
// 	while(t--){
// 		cin>>D>>d>>P>>Q;
// 		arr[i].push_back(D);
// 		arr[i].push_back(d);
// 		arr[i].push_back(P);
// 		arr[i].push_back(Q);
// 		i++;
// 	}
	

// // 	for(int i=0; i<arr.size(); i++){
// // 	    cout<<endl;
// //     	for(int j=0; j<4; j++){
// //     	    cout<<arr[i][j]<<" ";
// //     	}
// // 	}

	
// 	for(int i=0; i<arr.size(); i++){	
// 		long total=0;
// 		int inital_rate=0;
// 		bool flag = false;
// 		long Q=arr[i][3];
// 		for(int j=0; j<arr[i][0]; j++)	{
// 			if(j%arr[i][1]==0&&j!=0){
			    
// 				inital_rate++;
// 				// cout<<j<<inital_rate<<endl;
// 				int temp = arr[i][3];
// 				Q = inital_rate*temp;
// 				flag = true;
// 			}
//             if(flag==true)
// 			    total+=arr[i][2]+Q;
// 			else
// 			    total+=arr[i][2];
//     //  total+=arr[i][2]+arr[i][3];
// // 			op[i] = total;
// 		}
// 		cout<<total<<endl;
// 	}

// // 	for(int i=0; i<op.size(); i++)
// // 		cout<<op[i];
// }


#include<bits/stdc++.h>
using namespace std;


	
	void total(unsigned int D, unsigned int d, unsigned int  P, unsigned int Q){
		long total=0;
		int inital_rate=0;
		bool flag = false;
		long q = Q;
// 		cout<<D<<d<<P<<Q;
		
		for(int j=0; j<D; j++){
			if(j%d==0 && j!=0){
			    
				inital_rate++;
				// cout<<j<<inital_rate<<endl;
				q = inital_rate*Q;
				flag = true;
			}
            if(flag==true)
			    total+=(P+q);
			else
			    total+=P;
    //  total+=arr[i][2]+arr[i][3];
// 			op[i] = total;
		}
		cout<<total<<endl;
	}

int main(){
	int t; cin>>t;
	vector<vector<int>> arr(t);
	vector<int> op(t, 0);
// 	int total(int D, int d, int P, int Q);
    unsigned int D,d,P,Q;
	while(t--){
		cin>>D>>d>>P>>Q;
		total(D, d, P, Q);
	   // cout<<total(D, d, P, Q)<<endl;
	}
}