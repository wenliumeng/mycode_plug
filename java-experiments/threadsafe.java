import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class threadsafe {

    public static int demo(final List list){

        for (int i = 0; i < 1000; i++) {
            final int finalI = i;
            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        Thread.sleep(3);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    list.add(finalI);
                }
            }).start();
        }

        //�ȴ�δ�������ݵ��߳�ִ�����
        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return list.size();
    }

    public static void main(String[] args) throws InterruptedException {
        List list = new ArrayList();
        List lists = Collections.synchronizedList(new ArrayList());
        //��������ݶ�������ģ������̰߳�ȫ����̰߳�ȫֻ�Ǳ�֤�����̶߳�ʵ��ִ������ȷ�Ĳ������
        System.out.println(demo(list)+"/"+demo(lists));
    }
}
