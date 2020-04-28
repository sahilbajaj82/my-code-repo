#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long sum=0,a3,a2,a1=1;
        for(a2=2;a2<n;)
        { if((a2&1)==0)
            sum+=a2;
            a3=a2;
          a2=a2+a1;
          a1=a3;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
