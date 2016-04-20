/**
 * Created by SeyMour on 2016/2/16.
 */
public class StaticTest {
    private static String name = "sd";
    private String num = "100";

    //静态内部类可以使用public,protected,private修饰
    static class Person {
        //静态内部类中可以定义静态或非静态成员
        private String address = "China";
        private static String x = "as";
        public String mail = "fa@yahoo.com";

        public void display() {
            //不能访问外部类中的非静态成员，这是由Java语法中"静态方法不能直接访问非静态成员"所限定
            System.out.println(num);//报错
            System.out.println(name);//正常
        }
    }

    static String i = "sdf";
    static final String i2 = "sc";

    class InterClass {
    }

    public void printInfo() {
        Person person = new Person();
        //外部类访问内部类的非静态成员，实例化内部类即可
        person.display();
        //外部类不能直接访问内部类的成员，必须通过内部类的实例
        System.out.println(mail);//报错
        System.out.println(person.mail);
        //可以访问内部类的私有成员
        System.out.println(person.address);
        //可以访问内部类的静态成员
        System.out.println(person.x);
    }
}
