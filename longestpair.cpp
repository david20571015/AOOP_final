#include "longestpair.h"

LongestPair::LongestPair()
{

}

string LongestPair::solve(string s)
{
   vector<double> point = stringtoVectorDouble(s);
   int n=point.size()/3;

   double dist=distSqrt(point[0]-point[4],point[1]-point[5],point[2]-point[6]);

   for(int i=0;i<3*n-3;i+=3)
       for(int j=i+3;j<3*n;j+=3)
           dist=max(dist,distSqrt(point[i]-point[j],point[i+1]-point[j+1],point[i+2]-point[j+2]));

   stringstream ss;
   ss<<fixed<<setprecision(2)<<sqrt(dist);
   string str;
   ss>>str;

   return str;
}
