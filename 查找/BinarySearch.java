public class BinarySearch{
	public static int binarySearch1(Integer[] a,int n,int key)
	{
		int low, high, mid;
		low = 0;
		high = n;
		while(low <= high)
		{
			mid = (low + high)>>1;
			if(key < a[mid])
				high = mid-1;
			else if(key > a[mid])
				low = mid +1;
			else
				return mid;
		}
		return 0;
	}
	
	public static int binarySearch2(Integer[] a,int l,int h,int key)
	{
		int mid = (l + h) >> 1;
		if(l < h)
		{
			if(key < a[mid])
				binarySearch2(a,0,mid-1,key);
			else if(key > a[mid])
				binarySearch2(a,mid+1,h,key);
			else
				return mid;
		}
		return 0;
	}
}