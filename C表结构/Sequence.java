package LinearTable;

/**
 * xxx
 * Created by seyMour on 2016/5/9.
 * ☞120465271@qq.com☜
 */
public class Sequence<T> implements LinearTable<T> {

    private T[] data;
    private int length;

    public Sequence(int length) {
        this.data = (T[])new Object[length];
        this.length = 0;
    }

    @Override
    public T GetElem(int i) {
        if(this.length  == 0 || i < 1 || i > this.length )
            return null;
        return this.data[i];
    }

    @Override
    public boolean ListInsert(T element, int i) {
        if(i < 1 || i > this.length)
            return false;
        if(this.length == this.data.length){
            T[] tmp = this.data;
            this.data = (T[])new Object[tmp.length * 2];
            for(int i1 =0;i<tmp.length;i1++){
                this.data[i1] = tmp[i1];
            }
        }
        for(int j = this.length-1;j >= i;j--){
            this.data[j+1] = this.data[j];
        }
        this.data[i] = element;
        this.length++;
        return false;
    }

    @Override
    public boolean ListDelete(int index) {
        for(int i = index; i < this.length-1;i++){
            this.data[i] = this.data[i+1];
        }
        this.data[this.length-1] = null;
        this.length--;
        return true;
    }
}
