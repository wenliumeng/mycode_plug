import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class threadsafe {

    public static int demo(final List list){
        ThreadGroup group = new ThreadGroup(list.getClass().getName() + "@" + list.hashCode());

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
        System.out.println(demo(list)+"/"+demo(lists));
    }
}