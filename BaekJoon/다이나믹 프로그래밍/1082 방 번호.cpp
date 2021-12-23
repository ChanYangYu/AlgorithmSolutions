#include <bits/stdc++.h>

/*
	1. ���� [��������][��ȣ]���� �ִ�� ���� �� �ִ� ���� ������ ���� 
	2. top-down���� �Ʒ� ���յ��� ��� Ž���� �� ���� �ִ밡 �Ǵ� ������ ret�� ����
	
	�����Ʈ
	- 00 ó���� �ȵǾ��־���
	- str > ret �� ������ �ݴ�� �Ǿ� �־��� 
*/

using namespace std;

string cache[51][11];
int p[11];
int n, m;

string solve(int remain, int number){
	string& ret = cache[remain][number];
	
	// ������� 
	if(remain == 0 || number == n)
		return "";
	
	// �̹� [��������][��ȣ]�� ���� �� �ִ� �ִ� ���������� ���� ��� 
	if(ret != "")
		return ret;
	
	string cur = "";
	
	// ���� ���ڸ� �ȱ����� ��� Ž�� 
	ret = solve(remain, number+1);
	
	// ���� ���ڸ� ������ �� �ִ� ��ŭ ������ ��� Ž�� 
	while(remain - p[number] >= 0){
		remain -= p[number];
		
		// cur : ���� ������ ���� ��ġ 
		cur += to_string(number);
		
		// str : ���� ������ ������ �� �ִ� �ִ� �������� (top-down)
		string str = solve(remain, number+1);
		
		// ���� �� �ִ� �ִ� �������� 
		str = cur + str;
		sort(str.begin(), str.end());
		reverse(str.begin(), str.end());
		
		
		// 00 �̷������� 0���� ä���� �ִ� ��� ����ó�� 
		if(str.size() > 1 && str[0] == '0')
			continue;
		
		// ���ڰ� �� ���� ��� 
		if(str.size() > ret.size())
			ret = str;
		// ������ �� ū ��� 
		else if(str.size() == ret.size() && str > ret)
			ret = str;
	}
	
	return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
    	cin>>p[i];
	
	cin>>m;
	
	cout<<solve(m, 0);
   	return 0;
}
