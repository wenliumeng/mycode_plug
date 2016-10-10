/**
 * 最大公约数
 */
public class GreatestCommonDivisor {

    //枚举
    static int getGCD1(int i, int j) {
        int big = i > j ? i : j;
        int sma = i < j ? i : j;
        if (big % sma == 0)
            return sma;
        int result = 1;
        for (int k = 2; k < sma / 2; k++) {
            if (big % k == 0 & sma % k == 0)
                result = k;
        }
        return result;
    }

    //辗转相除 更相减损
    static int getGCD2(int i, int j) {
        int result = 0;
        if (i > j)
            result = getGCD2s(i, j);
        if (i < j)
            result = getGCD2s(j, i);
        return result;
    }

    static int getGCD2s(int k, int l) {
        if (k % l == 0)
            return l;
        else
//            return getGCD2s(k, k % l);
            return getGCD2s(k, k - l);
    }

    //综合两种
    static int getGCD3(int i, int j) {
        int result = 0;
        if (i == j)
            result = i;
        if (i < j)
            getGCD3(j, i);
        else {
            //两者都为偶数，公约数=getGCD(i/2,j/2)*2
            if ((i & 1) == 0 && (j & 1) == 0)
                return getGCD3(i >> 2, j >> 2) << 1;
            //其中一个为偶数，公约数=getGCD(x/2,x/2)
            else if ((i & 1) == 0 && (j & 1) != 0)
                return getGCD3(i >> 2, j);
            else if ((i & 1) != 0 && (j & 1) == 0)
                return getGCD3(i, j >> 2);
            //更相减损
            else
                return getGCD3(i, i - j);
        }
        return result;
    }

    public static void main(String[] args) {

//        System.out.println(getGCD2(24, 16)
    }
}
