//���ڣ�2018/ ʱ�䣺
#include <vector>
#include <stdio.h>
using namespace std; 

int main(){
	vector<int> vi;
	for(int i=1;i<=5;i++)
		vi.push_back(i);
	
	vi.insert(vi.begin()+2,-1);
	vi.erase(vi.begin()+1);
	vi.erase(vi.begin()+1,vi.begin()+3);					//erase(first,last)ɾ��[first,last)������Ԫ�� 
	
	vector<int>::iterator it;
	for(it=vi.begin();it!=vi.end();it++){
		printf("%d ",*it);
	}

	return 0;
}

