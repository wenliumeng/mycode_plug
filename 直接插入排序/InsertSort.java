public class InsertSort {

    public static void main(String[] args) {
        int l[] = {0, 5, 3, 4, 6, 2};
        int i, j;
        for (i = 2; i < l.length; i++) {
            if (l[i] < l[i - 1]) {
                l[0] = l[i];
                for (j = i - 1; l[j] > l[0]; j--) {  //�ҳ��ȱ�־λ���������ǰ��
                    l[j + 1] = l[j];
                }
                l[j + 1] = l[0];
            }
        }
    }
}
