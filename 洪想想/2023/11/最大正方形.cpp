#include<bits/stdc++.h>
using namespace std;
int tu[110][110];
int Max=0;
int n,m;
void f(int i,int j,int k){
    int ff=0;//看看是不是符合要求
    if(tu[i+k][j+k]==1 && i+k<=n && j+k<=m){//直接检查斜对角的值是否符合要求
        ff=1;
        //测试点10，代表前面都没有问题是下面的for循环出了问题
        //cout<<ff<<endl;
        for(int a=i;a<=i+k;a++){
            //
            for(int b=j;b<=j+k;b++){
                if(tu[a][b]==0){
                    
                    ff=0;
                    break;
                }
            }
            if(ff==0){
                break;
            }
        }
        
    }
    //测试点9输出全是0
    //测试点8 有输出
    if(ff==1){
        k++;
        if(k>Max){
            Max=k;
            //测试点6 猜测正确，该部分没有输出
            //
        }
        f(i,j,k);//最大值更新了才有必要去套函数
    }
    return;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tu[i][j];//把图形信息输入二维数组里
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<tu[i][j];//把图形信息输入二维数组里
        }
        cout<<endl;
    }*/ //测试点7 数组的值有成功导入
    //测试点1 没问题，有输出
    for(int i=1;i<=n;i++){
        //测试点2 有输出，但是有问题 只输出了两次，
        //实际应该输出四次，代表后面陷入死循环了
        for(int j=1;j<=m;j++){
            //测试点3 有输出，输出了8次，代表只跑了前两层，
            //后面就死循环了
            int k=0;
            if(tu[i][j]==1){
                f(i,j,k);
            }//所有的1全跑完了，代表整个图没有问题，只是ff的赋值变化有问题
        }
    }
    cout<<Max;
    return 0;
}
//测试点4 有输出了，但是样例的输出为0，不正确，代表可能，Max没有进行累加，现在对函数部分进行检查
//for循环的遍历出了问题