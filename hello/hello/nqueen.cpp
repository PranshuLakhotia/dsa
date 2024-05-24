#include <stdio.h>
#include <iostream>
using namespace std;


void printboard(int** arr, int n) {
    cout << endl<<"Print"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool safe(int** arr, int r, int c, int n) {
    for (int i = 0; i < r; i++) {

        if (arr[i][c] == 1) {
            return false;
        }
    }
    while (c >= 0 && r >= 0) {
        if (arr[r][c] == 1) {
            return false;
        }
        c--;
        r--;
    }
    while (r >= 0 && c < n) {
        if (arr[r][c] == 1) {
            return false;
        }
        c++;
        r--;
    }
    return true;
}

	
      bool recursion(int **arr, int r,int n) {
          if (r >= n) {
              return true;
            }
            for (int c = 0; c < n; c++) {
                if (safe(arr, r,c,n)) {
                    arr[r][c] = 1;
                    cout << endl << "r, c = " << r << " " << c << endl;
                    printboard(arr, n);
                    if (recursion(arr, r + 1,n)) {
                        return true;
                    }
                    arr[r][c] = 0;
                }
            }
            return false;
       }


   



   



	
