package bruteForce;

import java.util.Scanner;

import static java.lang.Math.*;

public class BruteForce_1051 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        int [][] map = new int[55][55];
        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt();
            for(int j=0;j<m;j++) {
                map[i][j] = tmp % 10;
                tmp = tmp / 10;
            }
        }
        int maxi = -1;
        int[] dx = {0, 1, 1};
        int[] dy = {1, 0, 1};
        for (int size = 1; size <= min(n, m); size++) {
            for (int i = 0; i <= n-size; i++) {
                for (int j = 0; j <= m-size; j++) {
                    boolean flag = true;
                    for (int a = 0; a < 3; a++) {
                        int newx = i+(size-1)*dx[a];
                        int newy = j+(size-1)*dy[a];
                        if(map[newx][newy] == map[i][j]){
                            continue;
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        maxi = max(maxi, size);
                }

            }
        }
        System.out.println((int)pow(maxi, 2));
    }
}
