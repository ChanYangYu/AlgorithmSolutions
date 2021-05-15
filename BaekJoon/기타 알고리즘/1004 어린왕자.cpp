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
			
			//원과 시작점의 거리 
			int d = ((x1-cx)*(x1-cx)) + ((y1-cy)*(y1-cy));
			//반지름의 제곱 
			int cs = cr * cr;
			//시작점이 원에 속하면 
			if(cs > d)
				start.push({cr,{cx, cy}});
			
			d = ((x2-cx)*(x2-cx)) + ((y2-cy)*(y2-cy));
			//도착점이 원에 속하면 
			if(cs > d)
				end.push({cr,{cx, cy}});
		}
		
		//공통된 원 제거 
		while(!start.empty() && !end.empty()){
			int sx, sy, sr;
			int ex, ey, er;
			
			sr = start.top().first;
			sx = start.top().second.first;
			sy = start.top().second.second;
			
			er = end.top().first;
			ex = end.top().second.first;
			ey = end.top().second.second;
			
			//현재 최대크기 원이 같지 않으면 
			if(sr != er || sx != ex || sy != ey)
				break;
			
			//공통원 제거 
			start.pop();
			end.pop();
		}
		
		//각각 위치를 감싸고 있는 원의 개수 합 출력 
		cout<<end.size() + start.size()<<endl;
	}	

	return 0;
}
