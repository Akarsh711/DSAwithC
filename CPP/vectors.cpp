// Vector : It is nothing but Dynamic Vector
#include<iostream>
#include<vector>

using namespace std;

template <class X>
void display(vector<X> &v){
	cout<<"Displaying this vector"<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<< " ";
	}
	cout<<endl;
}
int main(){
	vector<int> vec1; // zero-element vector
	vector<char> vec2(4); // 4-element char vector
	vec2.push_back('B');
	vector<char> vec3(vec2); // 4-element character vector from vec2
	vector<int> v(6, 3); // 6-element vector of 3s
	// int element;
	// for (int i = 0; i < 4; ++i)
	// {
	// 	cout<<"Enter an element to add to this vector";
	// 	cin>>element;
	// 	vec1.push_back(element);
	// }
	// To insert an element at certain position 
	cout << "Printing char vector"<< vec2[4]<< endl;
	vector<int> :: iterator iter = vec1.begin();
	vec1.insert(iter,3, 5000);
	display(vec1);
	return 0;
}