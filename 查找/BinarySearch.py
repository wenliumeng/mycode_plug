def binarysearch(a,n,key):
	low = 0;
	high = n;
	while(low <= high):
		mid = (low + high)/2
		if a[mid] > key:
			low = mid - 1
		elif a[mid] < key:
			high = mid + 1
		else:
			return mid
	return 0
	
def binarysearch2(a,l,h,key):
	if(l < h):
		mid = (l + h)/2
		if a[mid] > key:
			binarysearch2(a,l,mid-1,key)
		elif a[mid] < key:
			binarysearch2(a,mid-1,h,key)
		else:
			return mid
	else:
		return 0
			