#include<bits/stdc++.h>
using namespace std;
struct Node{
        int data;
        Node* next;
    };

template <class K, class V>
class HashMap{
    public:
        

        vector<Node*> v; 
        void put(K key, V value){
            int bi = hashfn(key);
            int di = getIndexWithinBucket(key, bi);
        }
};
