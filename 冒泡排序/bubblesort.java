public class bubbleSort(){
int l[] = {2,3,4,1,8,6,5,7};
        System.out.println(Arrays.toString(l));
        int flag = 0;
        for(int i =1;i<l.length;i++){
            flag = flag+  1;
            for(int j = l.length;j > i;j--){
                if(l[j-2] > l[j-1]){
                    int temp = l[j-2];
                    l[j-2] = l[j-1];
                    l[j-1] = temp;
                }
                System.out.println(flag + Arrays.toString(l));
            }
        }
        System.out.println(Arrays.toString(l));
}
