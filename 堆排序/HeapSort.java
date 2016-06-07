package com.smartkitchen.device.domain;

import java.util.Arrays;
import java.util.List;

/**
 * xxx
 * Created by seyMour on 2016/6/7.
 * ☞120465271@qq.com☜
 */
public class HeapSort {
    public static void main(String[] args) {
        int l[] = {0,50,10,90,30,70,40,80,60,20};
        for (int i = l.length/2; i > 0; i--) {
            HeapAdjust(l,i,l.length);
        }

        int temp;
        for(int i = l.length-1;i > 2;i--){
            temp = l[i];
            l[i] = l[1];
            l[1] = temp;
            HeapAdjust(l,1,i-1);
        }

        System.out.println(Arrays.toString(l));
    }

    //调整为大顶堆
    static void HeapAdjust(int l[],int s,int m){
        int temp,j;
        temp = l[s];
        for (j = s*2; j < m; j*=2) {
            if(j < m && l[j] < l[j+1])
                ++j;
            if(temp > l[j])
                break;
            l[s] = l[j];
            s = j;
        }
        l[s] = temp;
    }
}
