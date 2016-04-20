package Stack;

import org.junit.Test;

/**
 * xxx
 * Created by seyMour on 2016/4/20.
 * ☞120465271@qq.com☜
 */
public class Match {
    public boolean isMatch(String str){
        SequenceStack<Character> mystack = new SequenceStack<Character>(3);
        char[] arr = str.toCharArray();

        for(char c :arr){
            Character temp = mystack.pop();
            if(temp == null){
                mystack.push(c);
            }
            else if (temp == '[' && c == ']'){

            }
            else {
                mystack.push(temp);
                System.out.println(mystack.Top_Seq());
                mystack.push(c);
            }
        }
        return mystack.isEmpty();
    }

    @Test
    public void testMatch(){
        boolean b = isMatch("[abfgh");
    }
}
