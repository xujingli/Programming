#include <unordered_map>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){
	vector<int> nums;
	for(int i=0;i<10;i++){
		nums[i] = 2*i;
	}
	
	unordered_map<int,int> hash;
	for(int i=0;i<10;i++){
		hash[nums[i]] = i;
	}  
	
	for(int i=0;i<10;i++){
		printf(" %d",hash[nums[i]]);
	}

	return 0;
}

