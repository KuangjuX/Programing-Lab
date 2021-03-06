#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define MAX 210
#define MEM(arr,w) memset(arr,w,sizeof(arr));
using namespace std;
struct node
{
    int x,y;
}st1,st2,ss,tt;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,MAXT;
char map[MAX][MAX];
int visit[MAX][MAX];
int step1[MAX][MAX],step2[MAX][MAX];
void Init()
{
    MEM(visit,false);
    MAXT=INF;
    MEM(step1,0);
    MEM(step2,0);
}
void BFS(node st,int step[][210])
{
    queue<node> Q;
    Q.push(st);
    visit[st.x][st.y]=true;
    while(!Q.empty())
    {
        ss=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            tt.x=ss.x+dir[i][0];
            tt.y=ss.y+dir[i][1];
            if(tt.x>=0&&tt.x<n&&tt.y>=0&&tt.y<m&&map[tt.x][tt.y]!='#'&&!visit[tt.x][tt.y])//最基本的条件必须符合
            {
                step[tt.x][tt.y]=step[ss.x][ss.y]+1;
                visit[tt.x][tt.y]=true;
                Q.push(tt);
            }
        }
    }
    return ;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
            {
                if(map[i][j]=='Y') st1.x=i,st1.y=j;
                if(map[i][j]=='M') st2.x=i,st2.y=j;
            }
        }
        Init();
        BFS(st1,step1);
        MEM(visit,false);
        BFS(st2,step2);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(map[i][j]=='@'&&step1[i][j]!=0&&step2[i][j]!=0)
                    if(step1[i][j]+step2[i][j]<MAXT) MAXT=step1[i][j]+step2[i][j];
        printf("%d\n",MAXT*11);
  
    }
}