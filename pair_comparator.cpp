#include<bits/stdc++.h>
 using namespace std;
/*This “comparator” function returns a value; 
convertible to bool, which basically tells us whether 
the passed “first” argument should be placed before 
the passed “second” argument or not.
*/

//Below conditions are of standard sort 

bool sortbydesc( pair<int,int> i1, pair<int,int> i2)
{
    if (i1.first < i2.first)           return true ;
    else if( i1.first == i2.first )
    {
        if( i1.second <= i2.second )   return true ;
        else                           return false;
    }
    else                               return false;

}