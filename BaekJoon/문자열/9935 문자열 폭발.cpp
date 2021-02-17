/*
1. �˰��� Ǯ�� ���� ��� 
- ó������ ������ �ΰ��� �����ߴٰ� string�� ���߹��ڿ��� �ش�ȵǴ� ���ڸ� �ְ�
  ���ÿ��� ������ ���߹��ڿ��� �����ߴµ� �̷��� �ϰԵǸ� ���ڿ��� ������ ���� �ʴ� ������ �ִ�.
  ex) ACBBABCCCD
      BA
	  ACCCCD + BB
- ������ ���� ������ �ϳ��� ����ϰ� <������� ��ġ����, ����> ������ ������ �ۼ��Ͽ� Ǯ��

2. �ð����⵵ 
- O(N*B)
*/
#include <bits/stdc++.h>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	string boom;
	string res = "";
	string str;
	int size;
	stack <pair<int, char> > s;
	
	cin>>str;
	cin>>boom;
	size = boom.size();
	
	int count = 0;
	for(int i = 0; i < str.size(); i++){
		//���������� ���߹��ڿ��� ��ġ�Ҷ� 
		if(boom[count] == str[i]){
			count++;
			if(count == size){
				//size-1�� pop 
				for(int i = 0; i < size-1; i++)
					s.pop();
				//top�� ������ count ���� 
				if(!s.empty())
					count = s.top().first;
				else
					count = 0;
			}
			else
				s.push(make_pair(count, str[i]));			
		}
		//���� ���ڿ��� ù��° ���ڿ� ������ 
		else if(boom[0] == str[i]){
			count = 1;
			s.push(make_pair(count, str[i]));
		}
		//�ƹ� ������ ���� ���ڿ� �϶� 
		else{
			count = 0;
			s.push(make_pair(count, str[i]));
		}
	}
	
	int st_size = s.size();
	
	if(st_size == 0)
		cout<<"FRULA";
	else{
		string tmp = "";
		for(int i = 0; i < st_size; i++){
			char c = s.top().second;
			tmp += c;
			s.pop();
		}
		for(int i = st_size-1; i >= 0; i--)
			res += tmp[i];
		cout<<res;
	}
    return 0;
}
