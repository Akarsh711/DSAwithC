#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		map<int, int> f;
		map<int, int> o;

		for(int i=0; i<n; ++i){
			int temp;
			cin>>temp;
			f[temp]++;

			if(x != 0){
				f[temp^x]++;
				o[temp^x]++;
			}
		}

		int max=0, minimum=0;
		for(auto i: f){
			if(i.second> max){
				max = i.second;
				minimum = o[i.first];
			}
			else if(i.second == max){
				minimum = min(minimum, o[i.first]);
			}
		}
		cout<<max<< ' ' <<minimum<<endl;
		
	}
	
return 0;
}