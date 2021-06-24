package math;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Math_1546{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt(), tmp;
        ArrayList<Integer> arr = new ArrayList<Integer>();
        double sum = 0;
        for(int i=0;i<num;i++) {
            tmp = sc.nextInt();
            arr.add(tmp);
        }
        int maxi = Collections.max(arr);
        for(int i=0;i<num;i++)
            sum += (arr.get(i)/(double)maxi)*100;
        System.out.println(sum/num);
    }
}