#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include<conio.h>
void serp(float x1,float y1,float x2,float y2,float x3,float y3,int n){
    float a,b,c,d,e,f;
    if (n > 0){
    a=1.0*(x1+x2)/2;
    b =1.0*(x2+x3)/2;
    c= 1.0*(x1+x3)/2;
    d = 1.0*(y1+y2)/2;
    e=1.0*(y2+y3)/2;
    f=1.0*(y3+y1)/2;
        setcolor(1);
        line(a,d,b,e);
        line(a,d,c,f);
        line(b,e,c,f);
        floodfill(1.0*(a+b+c)/3,1.0*(e+f+d)/3,1);
        serp(x1,y1,c,f,a,d,n-1);
        serp(x2,y2,a,d,b,e,n-1);
        serp(x3,y3,c,f,b,e,n-1);
    }
    }
int main()
{
    float x1,x2,x3,y1,y2,y3;
    int n;
    scanf("%f%f%f%f%f%f%d",&x1,&y1,&x2,&y2,&x3,&y3,&n);
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm,"");

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
        serp(x1,y1,x2,y2,x3,y3,n);
    readkey();
    getch();
    closegraph();
    return 0;
}
