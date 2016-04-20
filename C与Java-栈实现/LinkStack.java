package Stack;

/**
 * 链式栈
 * Created by seyMour on 2016/4/20.
 * ☞120465271@qq.com☜
 */
public class LinkStack<T> {

    private class Node{
        private T data;//保存节点的数据

        private Node next;//指向下个节点的引用

        public Node() {
        }

        public Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    private Node top;

    private int size = 0; //保存该链栈中已包含的节点数,即栈的长度

    public LinkStack() {
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public T peek(){
        return top.data;
    }

    public LinkStack(T element){
        top = new Node(element,null);
        size++;
    }

    /**
     * 入栈
     * @param element
     */
    public void push(T element){
        top = new Node(element,top);
        size++;
    }

    /**
     * 出栈
     * @return
     */
    public T pop(){
        Node oldTop = top;
        top = top.next;
        oldTop.next = null;
        size--;
        return oldTop.data;
    }
}
