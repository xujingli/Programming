//���ڣ�2018/ ʱ�䣺
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
using namespace std;
//map ���Խ��κλ������ͣ�����STL������ӳ�䵽�κλ������ͣ�����STL������ 

/* 
int main(){
	vector<int> nums;
	
	for(int i=0;i<10;i++)
		nums.push_back(2 * i);
	
	int target = 6;
		
	map<int,int> hash;
    vector<int> res;
    
    
    for(int i=0,len=nums.size();i<len;i++){
      	hash[nums[i]] = i;
    }    
    
    for(int i=0,len=nums.size(); i<len;i++){
      	int val2 = target - nums[i];
        	
      	if(hash.find(val2) != hash.end()){
       		res.push_back(hash[val2]);
       		res.push_back(i);
        		
       		printf("%d %d\n",res[0],res[1]);
       		return 0;
       	}
    }
       
    return 0;	
	
}
*/
/**/
int main(){
	unordered_map<char,int> mp;
	mp['c'] = 5;
	mp['c'] = 10;	//����
	mp['m']	= 20;
	mp['a'] = 30;
	mp['p'] = 40;
	
	unordered_map<char,int>::iterator it;
	it = mp.find('c');
	//mp.erase(it);
	
	for(it=mp.begin();it!=mp.end();it++){
		printf("%c %d\n",it->first,it->second);
	}
	
	it = mp.find('a');

	return 0;
}
