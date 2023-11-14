```c++
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (p3-obuf<1000000)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
template<typename item>
inline void read( item &x){
    x=0; int f=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=f;
}
template<typename item>
inline void uread( item &x){
    x=0; char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
static char cc[20];
template<typename item>
inline void print( item x){
    int len=0;
    if(x<0)x=-x,putchar('-');
    while(x)cc[len++]=x%10+'0',x/=10;
    while(len--)putchar(cc[len]);
}
template<typename item>
inline void uprint( item x){
    int len=0;
    while(x)cc[len++]=x%10+'0',x/=10;
    while(len--)putchar(cc[len]);
}
```

