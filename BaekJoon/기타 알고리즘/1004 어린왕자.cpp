#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int t;
	
	cin>>t;

	for(int i = 0; i < t; i++){
		int n, x1, y1, x2, y2;
		priority_queue<pair<int, pair<int, int> > > start, end;
		
		cin>>x1>>y1>>x2>>y2;
		cin>>n;
		for(int j = 0; j < n; j++){
			int cx, cy, cr;
			
			cin>>cx>>cy>>cr;
			
			//���� �������� �Ÿ� 
			int d = ((x1-cx)*(x1-cx)) + ((y1-cy)*(y1-cy));
			//�������� ���� 
			int cs = cr * cr;
			//�������� ���� ���ϸ� 
			if(cs > d)
				start.push({cr,{cx, cy}});
			
			d = ((x2-cx)*(x2-cx)) + ((y2-cy)*(y2-cy));
			//�������� ���� ���ϸ� 
			if(cs > d)
				end.push({cr,{cx, cy}});
		}
		
		//����� �� ���� 
		while(!start.empty() && !end.empty()){
			int sx, sy, sr;
			int ex, ey, er;
			
			sr = start.top().first;
			sx = start.top().second.first;
			sy = start.top().second.second;
			
			er = end.top().first;
			ex = end.top().second.first;
			ey = end.top().second.second;
			
			//���� �ִ�ũ�� ���� ���� ������ 
			if(sr != er || sx != ex || sy != ey)
				break;
			
			//����� ���� 
			start.pop();
			end.pop();
		}
		
		//���� ��ġ�� ���ΰ� �ִ� ���� ���� �� ��� 
		cout<<end.size() + start.size()<<endl;
	}	

	return 0;
}
