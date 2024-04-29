/*
题目大意： n × m n\times mn×m的网格上有p pp个人，每个人都站在一个整数坐标上，且两两位置不同。还有q qq次“阴阳龙现身”事件，每次事件会选取一个旋转中心，从这个中心出发，向横、竖、斜线上的8个方向寻找最接近的人或边界，然后取出8个位置，将这8个位置上的人（如果有的话）进行某种旋转置换，最后还是回到这8个位置上，具体看题目。求最后所有p pp个人的位置。n , m ≤ 1 0 9 , p , q ≤ 1 0 5 n,m\le 10^9, p,q\le 10^5n,m≤10 
9,p,q≤10 
5
做法： 本题需要用到map+set+模拟。
其实这道题的思路口胡起来很简单，就是实现比较复杂。如果给你一条数轴上n nn个点，每次询问一个点，让你求在这个点左右最接近的点，你很快就会想到用set，而这道题只是把“数轴”换成了行、列和斜线而已。所以我们大可以对每行、每列、每条斜线都维护一个set，这样就能求出在这些方向上最接近的点了，然后就是模拟题目中所说的过程，进行插入、删除等操作即可。不同的斜线可以用x − y x-yx−y或x + y x+yx+y来进行区分。
而考虑到网格可能很大，所以再用一个map来维护每行、每列、每条斜线对应的set，只有当被访问到时才建set。这说得像是“map套set”，但实际上在map中查找和在set中查找的操作是分别进行的，所以复杂度只有一个log ⁡ \loglog，整个解法的复杂度应该是一个常数比较大的O ( q log ⁡ p ) O(q\log p)O(qlogp)，肯定够用了。这样我们就解决了这一题。

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,p,q;

struct Point
{
	Point() {}
	
	Point(int _x, int _y, int _id)
	{
		x=_x;
		y=_y;
		id=_id;
	}
	
	int x,y;
	int id;
}pt[100010];

const bool operator < (const Point& a, const Point& b)
{
	if (a.x!=b.x) return a.x<b.x;
	else return a.y<b.y;
}

map<int,int> setid[4];
vector<set<Point>*> st;

void set_insert(int type,int x,Point pnt)
{
	if (setid[type][x]==0)
	{
		st.push_back(new set<Point>());
		setid[type][x]=st.size()-1;
	}
	
	st[setid[type][x]]->insert(pnt);
}

void set_delete(int type,int x,Point pnt)
{
	st[setid[type][x]]->erase(pnt);
}

int find_dir[4][2]={{0,4},{6,2},{7,3},{5,1}};
int dir[8][2]={{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
int find_res[8][2]; //id, k

void set_find(int type,int x,Point pnt)
{
	int id=setid[type][x];
	
	if (id==0) return;
	
	set<Point>::iterator it_upper=st[id]->upper_bound(pnt);
	set<Point>::iterator it_lower=st[id]->lower_bound(pnt);
	
	if (it_lower!=st[id]->begin())
	{
		it_lower--;
		find_res[find_dir[type][0]][0] = it_lower->id;
		find_res[find_dir[type][0]][1] = max(abs(it_lower->x - pnt.x), abs(it_lower->y - pnt.y));
	}
	
	if (it_upper!=st[id]->end())
	{
		find_res[find_dir[type][1]][0] = it_upper->id;
		find_res[find_dir[type][1]][1] = max(abs(it_upper->x - pnt.x), abs(it_upper->y - pnt.y));
	}
}

void insert_point(Point pnt)
{
	int x=pnt.x, y=pnt.y;
	set_insert(0,x,pnt);
	set_insert(1,y,pnt);
	set_insert(2,x-y,pnt);
	set_insert(3,x+y,pnt);
}

void delete_point(Point pnt)
{
	int x=pnt.x, y=pnt.y;
	set_delete(0,x,pnt);
	set_delete(1,y,pnt);
	set_delete(2,x-y,pnt);
	set_delete(3,x+y,pnt);
}

void find_point(int x,int y)
{
	for(int i=0;i<8;i++)
		find_res[i][0]=find_res[i][1]=-1;
	
	Point pnt=Point(x,y,0);
	set_find(0,x,pnt);
	set_find(1,y,pnt);
	set_find(2,x-y,pnt);
	set_find(3,x+y,pnt);
}

void solve(int x,int y,int t)
{
	find_point(x,y);
	
	int limit=min(min(x-1,n-x),min(y-1,m-y));
	int k=limit+1;
	
	for(int i=0;i<8;i++)
	{
		if (find_res[i][1]!=-1 && find_res[i][1]<=limit)
			k = min(k, find_res[i][1]);
	}
	
	if (k==limit+1) return;
	
	for(int i=0;i<8;i++)
		if (find_res[i][1]==k)
		{
			int id=find_res[i][0];
			delete_point(pt[id]);
			pt[id].x=x+dir[(i+t)%8][0]*k;
			pt[id].y=y+dir[(i+t)%8][1]*k;
		}
	
	for(int i=0;i<8;i++)
		if (find_res[i][1]==k)
		{
			int id=find_res[i][0];
			insert_point(pt[id]);
		}
}

int main()
{
	cin >> n >> m >> p >> q;
	st.push_back(new set<Point>()); //occupy index 0
	
	for(int i=1;i<=p;i++)
	{
		int x,y;
		cin >> x >> y;
		pt[i]=Point(x,y,i);
		insert_point(pt[i]);
	}
	
	for(int i=1;i<=q;i++)
	{
		int x,y,t;
		cin >> x >> y >> t;
		
		solve(x,y,t);
	}
	
	ll ans=0;
	for(int i=1;i<=p;i++)
		ans=((ll)ans)^((ll)i*(ll)pt[i].x+(ll)pt[i].y);
	cout << ans << endl;
	
	return 0;
}
