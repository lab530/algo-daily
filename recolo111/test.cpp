#include<stdio.h>
  int main()
{ int l,m,k;
  scanf("%d %d",&l,&m);
  int a[l+1];
  for(k=0;k<=l;k++)
  a[k]=1;
  int u,v,j=0;
  for(k=0;k<m;k++){
    scanf("%d %d",&u,&v);
    for(;u<=v;u++)
    a[u]=0;}
  for(k=0;k<=l;k++)
  j=j+a[k];
  printf("%d",j) ;
  return 0; }
