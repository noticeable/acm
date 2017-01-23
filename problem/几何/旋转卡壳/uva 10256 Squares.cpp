#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#define pi acos(-1.0)
using namespace std;
struct Point
{
    double x, y;
    Point(double x=0, double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B){return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p){return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, double p){return Vector(A.x/p, A.y/p);}
bool operator < (Point a, Point b)
{
    return a.x<b.x ||(a.x == b.x && a.y < b.y);
}
const double eps = 1e-6;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0; else return x < 0 ? -1 : 1;
}
bool operator == (Point a, Point b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
//���
double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
//����
double Length(Vector A) {return sqrt(Dot(A,A));}
//�н�
double Angle(Vector A, Vector B)
{
	return acos(Dot(A,B)/Length(A)/Length(B));
}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}
double Area2(Point A,Point B,Point C)
{
	return Cross(B-A,C-A);
}
Vector Rotate(Vector A, double rad)
{
    return Vector(A.x * cos(rad) - A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P -Q;
    double t = Cross(w,u) / Cross(v,w);
    return P+v*t;
}
double DistanceToline(Point P, Point A, Point B)
{
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2)) / Length(v1);
}
double DistanceToSegment(Point P, Point A, Point B)
{
    if(A==B) return Length(P-A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if(dcmp(Dot(v1, v2))>0) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1,v2)) / Length(v1);
}
//�߶��ཻ�ж�
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
           c3 = Cross(b2-b1,a1-b1), c4 = Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
//�߶��ཻ�Ƿ����߶��ϣ��������˵㣩
bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p, a2-p))<0;
}

double PolygonArea(Point* p, int n)
{
    double area = 0;
    for(int i = 0 ; i < n-1 ; ++ i)
    {
        area += Cross(p[i] - p[0], p[i+1]-p[0]);
    }
    return area/2;
}
//��͹���㼯
int ConvexHull(Point* p, int n, Point* ch)
{
    sort(p, p+n);
    n = unique(p, p+n) - p; //ȥ��
    int m = 0;
    for(int i = 0 ; i < n ; ++ i)
    {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i] - ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2 ; i >= 0 ; -- i)
    {
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i] - ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}
double RotatingCalipers( Point *ch, int n )//��ת����
{
    int q = 1;
    double ans = 0;
    for ( int i = 0; i < n; ++i )
    {
        while ( Cross( ch[i + 1] - ch[i], ch[q + 1] - ch[i] ) > Cross( ch[i + 1] - ch[i], ch[q] - ch[i] ) )
            q = ( q + 1 ) % n;
        ans = max( ans, max( Length(Vector(ch[i]-ch[q])), Length(Vector(ch[i+1]-ch[q+1])) ) );
    }
    return ans;
}
const int maxn=500000+10;
Point p[maxn],ch[maxn];
int main()
{
    //freopen("a.txt","r",stdin);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double x,y,w;
        int m=0;
        for(int i=0;i<n;++i)
        {
            scanf("%lf%lf%lf",&x,&y,&w);
            Point o(x,y);
            p[m++]=o;
            p[m++]=o+Vector(w,w);
            p[m++]=o+Vector(w,0);
            p[m++]=o+Vector(0,w);
        }
        int z=ConvexHull(p,m,ch);
        double ans=RotatingCalipers(ch,z);
        double pp=ans*ans;
        //int res=(int)pp;
        printf("%.0lf\n",pp);
    }
    return 0;
}
