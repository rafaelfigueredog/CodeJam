#include <iostream>
#include <set>
#include <stdio.h>

using namespace std; 

void vestigium(int v[][101], int n, int k) {

    int c = 0;
    int r = 0;  
    int p = 0; 

    bool line = true;
    bool col = true; 

    for ( int i = 0; i < n; i++ ) {
        
        int rr[101] = {}; 
        int rc[101] = {};

        for (int j = 0; j < n; j++) {
            
            int u = v[i][j]; // line
            int y = v[j][i]; // col

            if (rr[u] == 0) rr[u]++;
            else if (line) {
                r++;
                line = false; 
            } 

            if (rc[y] == 0) rc[y]++;
            else if (col) {
                c++;
                col = false;
            }
        
            if (i == j) {
                p += v[i][j]; 
            }
        }    
        line = true; 
        col = true; 
       
    }
    printf("Case #%d: %d %d %d\n", k, p, r, c); 
}

int main () {
    int t, k = 1; 
    cin >> t;
    while ( k <= t ) {
        int n; 
        cin >> n; 
        int v[101][101] = {};
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j]; 
            }
        }
        vestigium(v, n, k); 
        k++; 
    }
}