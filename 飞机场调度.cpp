#include<cstdio>
#include<cstdlib>
using namespace std;
struct plane
{
	int id;
	int type;
	int waittime;
	struct plane* next;
};
struct runway
{
	int id;
	int waittime;
	int busytime;
	struct runway* next;
};
int n,time=0,landtime,taketime,landnum,takenum,runwayid=1,landid=5001,takeid=1,i,j,k,judge1=1,judge2=1;
float waitland=0,waittake=0,plane1=0,plane2=0,sum=0;
struct runway *rhead=NULL,*rp,*rq;
struct plane *ahead1=NULL,*arear1,*ap1,*aq1,*asearch1,*ahead2=NULL,*arear2,*ap2,*aq2,*asearch2;
void Free(struct runway* &rp)
{
	while(rp!=NULL)
	{
		if(rp->waittime!=0)
		{
			rp->waittime--;
			if(rp->waittime==0)
			    printf("runway %02d is free\n",rp->id);
		}
		rp=rp->next;
	}
	return ;
}
void Land(struct plane* &asearch1)
{
	while(asearch1!=NULL)
	{
	    rq=rhead;
	    int flag=0;
	    while(rq!=NULL)
	    {
	    	if(rq->waittime==0)
	    	{
	    		flag=1;
	    		printf("airplane %04d is ready to land on runway %02d\n",asearch1->id,rq->id);
		    	rq->waittime=landtime;
		    	rq->busytime+=landtime;
		    	if(ahead1->next!=NULL)      //减少一架飞机 
		    	    ahead1=ahead1->next;
		    	else
			        ahead1=NULL;
			    break;
		    }
		    rq=rq->next;
		} 
	    if(flag==0)
	        waitland++;   //遍历一遍以记录时间 
	    asearch1=asearch1->next;
	}
	return ;
}
void Takeoff(struct plane* &asearch2)
{
	while(asearch2!=NULL)
	{
	    rq=rhead;
	    int flag=0;
	    while(rq!=NULL)
	    {
	    	if(rq->waittime==0)
	    	{
	    		flag=1;
		    	printf("airplane %04d is ready to takeoff on runway %02d\n",asearch2->id,rq->id);
		    	rq->waittime=taketime;
		    	rq->busytime+=taketime;
		    	if(ahead2->next!=NULL)      //减少一架飞机 
			        ahead2=ahead2->next;
		    	else
			        ahead2=NULL;
		    	break;
		   }
	    	rq=rq->next;
	    }
	    if(flag==0)
	        waittake++;   //遍历一遍以记录时间 
	    asearch2=asearch2->next;
	}
	return ;
}
int main()
{
	scanf("%d %d %d",&n,&landtime,&taketime);
	for(i=0;i<n;i++)
	{
		rp=(struct runway*)malloc(sizeof(struct runway));
		rp->busytime=0;
		rp->id=runwayid++;
		rp->waittime=0;
		rp->next=NULL;
		if(rhead==NULL)
		    rhead=rq=rp;
		else
		{
			rq->next=rp;
			rq=rp;
		}
	}
	while(true)
	{
		printf("Current Time: %4d\n",time++);
		rp=rhead;
		Free(rp);
		if(judge1>=0&&judge2>=0)
		{
			scanf("%d %d",&landnum,&takenum);
			judge1=landnum;
			judge2=takenum;
			plane1+=landnum;
			plane2+=takenum;
		}
		for(i=0;i<landnum;i++)
		{
			ap1=(struct plane*)malloc(sizeof(struct plane));
			ap1->id=landid++;
			ap1->type=1;
			ap1->next=NULL;
			if(ahead1==NULL)
			    ahead1=arear1=ap1;
			else
			{
				arear1->next=ap1;
				arear1=ap1;
			}
		}
		for(i=0;i<takenum;i++)
		{
			ap2=(struct plane*)malloc(sizeof(struct plane));
			ap2->id=takeid++;
			ap2->type=2;
			ap2->next=NULL;
			if(ahead2==NULL)
			    ahead2=arear2=ap2;
			else
			{
				arear2->next=ap2;
				arear2=ap2;
			}
		}
		aq1=asearch1=ahead1;
		aq2=asearch2=ahead2;
		Land(asearch1);
		Takeoff(asearch2);
		int flag=0;
		rp=rhead;
		while(rp!=NULL)    //是否所有已完成 
		{
			if(rp->waittime==0)
			    flag++;
			else
			    break;
			rp=rp->next;
		}
		if(ahead1==NULL&&ahead2==NULL&&flag==n&&judge1<0&&judge2<0)
		    break;
	}
	float timet=time,nt=n,sum=0;
	printf("simulation finished\n");
    printf("simulation time: %4d\n",time-1);
    printf("average waiting time of landing: %4.1f\n",waitland/(plane1-landnum));
    printf("average waiting time of takeoff: %4.1f\n",waittake/(plane2-takenum));
    rq=rhead;
    while(rq!=NULL)
    {
    	printf("runway %02d busy time: %4d\n",rq->id,rq->busytime);
    	sum+=rq->busytime;
    	rq=rq->next;
	}
	printf("runway average busy time percentage: %4.1f%%\n",sum/nt*100.0/(timet-1));
	return 0;
}
