//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
bool used[2][2300][2300];

int main()
{
    int n, sum=0, best=1000000;
    int i, j, k;
    used[0][0][0]=true, used[1][0][0]=true;
    
    cin >> n;
    for(i=0;i<n;i++){
        int b;
        cin >> b;
        sum+=b;
        for(j=0;j<2295;j++){
            for(k=0;k<2295;k++){
                if(used[i%2][j][k]){
                    used[(i+1)%2][j][k]=true;
                    used[(i+1)%2][j+b][k]=true;
                    used[(i+1)%2][j][k+b]=true;
                }
            }
        }
    }
    for(i=0;i<2295;i++){
        for(j=0;j<2295;j++){
            if(used[n%2][i][j])
                best=min(best, max(i, max(j, sum-i-j)));
        }
    }
    
    cout << best << endl;
    
    return 0;
}
