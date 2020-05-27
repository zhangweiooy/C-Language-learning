#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

typedef struct a
{
	int period;
	int qnum;
	int next;
}mp;
priority_queue<mp> pos;

bool operator <(const mp& a,const mp& b){  
    if (a.next != b.next)
        return a.next > b.next;
    else
        return a.qnum > b.qnum;
}
void execute(int k)
{
	for (int i = 0; i < k; i++) {
        mp now = pos.top();
        pos.pop();

        printf("%d\n", now.qnum);
        
        now.next += now.period;
        pos.push(now);
    }
 } 
int main()
{
	char t[10];
	int i=0,j,k;
	while(scanf("%s",t)!=EOF)
	{
		while(t[0]!='#')
		{
			mp temp;
			scanf("%d %d",&temp.qnum,&temp.period);
			temp.next=temp.period;
			pos.push(temp);
			scanf("%s",t);
		}
		scanf("%d",&k);
		execute(k);
	}
	return 0;
}

