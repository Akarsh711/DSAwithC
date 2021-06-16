#include<bits/stdc++.h>
using namespace std;

void travelTime(int lcost,int rcost, int cfs, int destination, int N){

	if(( (cfs < lcost && cfs < rcost) && cfs!= -1) || (lcost ==-1 && rcost==-1)){
		cout<<cfs<<" ";
	}
	else{
		if((lcost<rcost && lcost!=N && lcost!=-1) || rcost==-1){
		cout<<lcost<<" ";
		}
		else if(rcost<lcost || lcost==-1){
			cout<<rcost<<" ";
			}
			else{
				cout<<"-1"<<" ";
			}
	}
}

int main(){	

	// int N, M;
	// cin>>N>>M;
	// vector<int> A;
	// vector<int> B;

	// for(int i=0; i<N; i++){
	// 	int u; cin>>u;
	// 	A.push_back(u);
	// }

	// for(int i=0; i<M; i++){
	// 	int u; cin>>u;
	// 	B.push_back(u);
	// }	

	// for(int i=0; i<M; i++){
	// 	// A[B[i]]
	// 	int cost_from_source = -1;
	// 	if(A[i] ==1){
	// 		cost_from_source = B[i]-1;
	// 	}

	// 	int temp = B[i];
	// 	temp--; //to take one less as taking arr[0]as first station
	// 	int lcost = 0;
	// 	while(A[temp]!=2){
	// 		if(temp == A.size()){
	// 			lcost = -1;
	// 			break;
	// 		}
	// 		temp++;
	// 		lcost++;
	// 	}
	// 	// cout<<"what"<<lcost<<" "<<temp<<endl;

	// 	temp = B[i];
	// 	temp--;
	// 	int rcost =0;
	// 	while(A[temp]!=1){
	// 		if(temp ==0){
	// 			rcost = -1;
	// 			break;
	// 		}
	// 		temp--;
	// 		rcost++;
	// 	}
		

	// 	 // cout<<"what"<<rcost<<" "<<temp<<endl;
	// 	 travelTime(lcost, rcost, cost_from_source, B[i], N);
	// 	 cout<<endl;
	// }



}