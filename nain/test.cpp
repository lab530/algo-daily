#include <cstdio>
#include <queue>
using namespace std;
void work() {
    priority_queue<int,vector<int>, greater<int> > heap1;
    priority_queue<int> heap2;
    int n=0,x;
    for(scanf("%d",&x);x;scanf("%d",&x)) {
        if(~x) {
            ++n;
            if(n==1||x>=heap1.top()) {
                heap1.push(x);
                if(!(n&1))
                    heap2.push(heap1.top()),heap1.pop();
            }
            else {
                heap2.push(x);
                if(n&1)
                    heap1.push(heap2.top()),heap2.pop();
            }
        }
        else {
            if(n&1) 
                printf("%d\n",heap1.top()),heap1.pop();
            else
                printf("%d\n",heap2.top()),heap2.pop();
            --n;
        }
    }
}
int main() {
    int t;
    std::scanf("%d",&t);
    while(t--)
        work();
    return 0;
}