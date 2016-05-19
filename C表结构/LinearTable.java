package LinearTable;

public interface LinearTable<T>{
  public T GetElem(int index);
  public boolean ListInsert(T element,int index);
  public boolean ListDelete(int index);
}
