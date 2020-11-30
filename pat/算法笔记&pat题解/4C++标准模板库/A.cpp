/*
题意：

考察点：
思路：
易错点：
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> find(string s,int len){
    int pre,post;
    vector<string> ans;
    for(int i=0;i<len;i++){
        int fr = i-1; int to = i+1;
        string tmp;
		tmp += s[i];
        while(1) {
            if(fr >= 0 && to < len && s[fr] == s[to]) {
                tmp += s[to];
                fr --; to ++;
            } else break;
        }
        if(tmp.length() == 1) continue;
        string tmp2 = tmp.substr(1, tmp.length()- 1);
        reverse(tmp2.begin(), tmp2.end());
        tmp = tmp2 + tmp;
        ans.push_back(tmp);
    }
    return ans;
}

int main(){
	string tmp;
	cin >> tmp;
	vector<string> ans = find(tmp, tmp.length());
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
}
