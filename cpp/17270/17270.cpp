#include <cstdio>
#define MIN(a,b) ((a<b)?a:b)
int v,m,a,b,c,J,S,d[101][101];
int main() {
	int i,j,k;
	scanf("%d%d",&v,&m);
	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
			d[i][j]=987654321;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		d[a][b]=d[b][a]=MIN(d[a][b],c);
	}
	scanf("%d%d",&J,&S);
	for(k=1;k<=v;k++){
		for(i=1;i<=v;i++){
			if(d[i][k]==987654321)continue;
			for(j=1;j<=v;j++){
				if(i==j||j==k||i==k)continue;
				d[i][j]=MIN(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	int dis=987654321;
	for(i=1;i<=v;i++){
		if(i==J||i==S)continue;
		dis=MIN(dis,d[J][i]+d[S][i]);
	}
	int mj=987654322;
	for(i=1;i<=v;i++){
		if(!(i == J || i == S)&&dis==d[J][i]+d[S][i] && d[J][i] <= d[S][i]){
			mj =MIN(d[J][i],mj);
		}
	}
	c = -1;
	for(i=1;i<=v;i++){
		if(mj==d[J][i]){
			c = i;
			break;
		}
	}
	printf("%d", c);
}