package Stack;

import java.util.Arrays;

/**
 * 顺序栈
 * Created by seyMour on 2016/4/20.
 * ☞120465271@qq.com☜
 */
public class SequenceStack<T>{

    private Object[] data = null;

    private int top = 0;
    private int MAXSIZE;

    public SequenceStack() {
        data = new Object[10];
    }

    public SequenceStack(int intSize) {
        data = new Object[intSize];
    }

    public SequenceStack(T element){
        this();
        data[0] = element;
        top++;
    }

    public SequenceStack(T element,int intsize){
        this.MAXSIZE = intsize;
        data = new Object[MAXSIZE];
        data[0] = element;
        top++;
    }

    public boolean isEmpty(){
        return top == 0;
    }

    //入栈
    public void push(T element){
        if((top + 1) > data.length){
            data = Arrays.copyOf(data, top +1);
        }
        data[top++] = element;
    }

    //出栈
    public T pop(){
        if(!isEmpty()){
            T oldValue = (T) data[top -1];
            //释放栈顶元素
            data[top--] = null;
            return oldValue;
        }else{
            return null;
        }
    }

    public T peek(){
        if(!isEmpty()){
            return (T) data[top -1];
        }else {
            throw new IndexOutOfBoundsException("空栈异常");
        }
    }
}
