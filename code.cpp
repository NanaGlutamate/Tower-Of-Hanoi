#include<cstdio>
#include<cstring>

int main(){
    char a[3];char b[3];char*c;
    char s[4]="ABC";
    int n,ewq=0;
    while(scanf("%d",&n)==1){
        if(n>=64){printf("Bad Input!");break;}
        if(ewq)printf("\n");else ewq++;
        c=new char[n+10];memset(c,0,n+2);
        if(n%2){
            a[0]=1;a[1]=2;a[2]=0;
            b[0]=2;b[1]=0;b[2]=1;
        }else{
            b[0]=1;b[1]=2;b[2]=0;
            a[0]=2;a[1]=0;a[2]=1;
        }
        unsigned long long max=1<<n;int now;
        for(unsigned long long i=1;i<max;++i){
            now=1;
            for(unsigned long long j=1;(!(j&i))&&(j<=i);j<<=1)++now;
            if(now&1){
                printf("%c to ",s[c[now]]);c[now]=a[c[now]];
                printf("%c\n",s[c[now]]);
            }else{
                printf("%c to ",s[c[now]]);c[now]=b[c[now]];
                printf("%c\n",s[c[now]]);
            }
        }
        delete[] c;c=NULL;
    }
    return 0;
}
