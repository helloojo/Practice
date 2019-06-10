#include <cstdio>
#define MIN(a,b) ((a<b)?a:b)
int v,m,a,b,c;
int J,S;
int d[101][101];
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
	int minji=987654322;
	for(i=1;i<=v;i++){
		if(i==J||i==S)continue;
		if(dis==d[J][i]+d[S][i]){
			if(d[J][i]<=d[S][i]){
				minji=MIN(d[J][i],minji);
			}
		}
	}
	for(i=1;i<=v;i++){
		if(minji==d[J][i]){
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
}