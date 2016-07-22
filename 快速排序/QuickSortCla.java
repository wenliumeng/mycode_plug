package quicksort;

import java.util.Arrays;

public class QuickSortCla {

    public static void main(String[] args) {
        int r[] = {0, 50, 10, 90, 30, 70, 40, 80, 60, 20};
        QuickSortCla q = new QuickSortCla();
        q.QuickSort(r,1,9);
        System.out.println(Arrays.toString(r));
    }

    protected void QuickSort(int i[],int low ,int high) {
        int gotomid;
        if (low < high) {
            gotomid = Gotomid(i,low,high);
            QuickSort(i,low,gotomid-1);
            QuickSort(i,gotomid+1,high);
        }
    }

    protected int Gotomid(int i[],int low ,int high) {
        int key = i[low];
        while (low < high) {
            while(low < high && i[high] >= key)
                high--;
            swap(i,low,high);
            while(low < high && i[low] <= key)
                low++;
            swap(i,low,high);
        }
        return low;
    }

    void swap(int r[] ,int i,  int j){
        int temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }
}
