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

        //等待未插入数据的线程执行完毕
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
        //里面的数据都是乱序的，无论线程安全与否，线程安全只是保证所有线程都实际执行了正确的插入操作
        System.out.println(demo(list)+"/"+demo(lists));
    }
}
