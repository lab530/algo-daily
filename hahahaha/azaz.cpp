#include <stdio.h>
#include <math.h>
#include <string.h>

struct score{
   char name[9];
    int a , b , c;
    int sum;
    int d,e,f,g;

}x[1000];
    
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i = 0; i < n;i++){
        scanf("%s %d %d %d",x[i].name,&x[i].a,&x[i].b,&x[i].c);
        x[i].sum=x[i].a+x[i].b+x[i].c;
    }

    if(n==1){
        printf("%s",x[0].name);
    }

    else {

        for(i = 0;i < n-1;i++){

            for(j = i+1; j < n;j++){

                x[i].d=abs(x[i].a-x[j].a);

                x[i].e=abs(x[i].b-x[j].b);

                x[i].f=abs(x[i].c-x[j].c);

                x[i].g=abs(x[i].sum-x[j].sum);

                    if( x[i].d<=5 && x[i].e<=5 && x[i].f<=5){

                        if(x[i].g<=10){

                            if(strcmp(x[i].name, x[j].name) <= 0){
                                printf("%s ", x[i].name);
                                printf("%s\n",x[j].name);
                            }

                            else {   
                                printf("%s ",x[j].name);
                                printf("%s\n",x[i].name);

                            }
                        }
                    }
                }
            } 
        }
    return 0;
}