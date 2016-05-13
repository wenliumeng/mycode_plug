public class MergeSort {

    /**
      * <pre>
      * 二路归并
      * 原理：将两个有序表合并和一个有序表
      * </pre>
      *
      * @param a
      * @param s
      * 第一个有序表的起始下标
      * @param m
      * 第二个有序表的起始下标
      * @param t
      * 第二个有序表的结束小标
      *
      */
    private static void merge(int[] a, int s, int m, int t) {
        System.out.println("进行了归并排序");
        //分配了能容纳两个数组的空间
        System.out.println("s="+s);
        System.out.println("m="+m);
        System.out.println("t="+t);

        int[] tmp = new int[t - s + 1];//得到需调整字符串的长度
        int i = s, j = m, k = 0;
        while (i < m && j <= t) {
            if (a[i] <= a[j]) {
                tmp[k] = a[i];
                k++;
                i++;
            } else {
                tmp[k] = a[j];
                j++;
                k++;
            }
        }
        while (i < m) {
            tmp[k] = a[i];
            i++;
            k++;
        }
        while (j <= t) {
            tmp[k] = a[j];
            j++;
            k++;
        }
        System.arraycopy(tmp, 0, a, s, tmp.length);//源数组，开始，目标数组，目标数组开始位置，复制的长度
        for(int ii = 0; ii < a.length; ii++) {
            System.out.print(a[ii] + " ");
        }
    }
    /**
      *
      * @param a
      * @param len
      * 每次归并的有序集合的长度
      */
    public static void mergeSort(int[] a, int len) {
        System.out.println("======start======");
        for(int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        int s;
        int size = a.length;
        int mid = size / (len << 1);
        int c = size & ((len << 1) - 1);
        System.out.println("");
        System.out.println("当前 size = " + a.length);
        System.out.println("当前 len = " + len);
        System.out.println("当前 mid = " + mid);
        // -------归并到只剩一个有序集合的时候结束算法-------//
        if (mid == 0)
        return;
        // ------进行一趟归并排序-------//
        for (int i = 0; i < mid; ++i) {
            System.out.println("循环次数 " + i);
            s = i * 2 * len;
            merge(a, s, s + len, (len << 1) + s - 1);
        }
        // -------将剩下的数和倒数一个有序集合归并-------//
        if (c != 0)
        merge(a, size - c - 2 * len, size - c, size - 1);
        // -------递归执行下一趟归并排序------//
        mergeSort(a, 2 * len);
        System.out.println("======end======");
    }

    public static void main(String[] args) {
        int[] a = new int[] {6,202,100,301,38,8,1};
        mergeSort(a,1);
        for(int i = 0; i < a.length; i++) {
//            System.out.print(a[i] + " ");
        }

        /*int[] d = {1,6,3,4,5,7};
        merge(d,0,2,5);
        for(int i = 0; i < d.length; i++) {
            System.out.print(d[i] + " ");
        }*/

        /*int[] b = new int[] {6,202,100,301};
        merge(b,0,2,3);
        for(int i = 0; i < b.length; ++i) {
            System.out.print(b[i] + " ");
        }*/
    }
}
