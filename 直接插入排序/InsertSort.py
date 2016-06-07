class insertsort(object):

    l=[0,5,3,4,6,2]

    def insert_sort(l):
        i = 2
        j = 0
        while i < len(l):
            if l[i] < l[i-1]:
                l[0] = l[i]
                j = i -1
                while l[j] > l[0]:
                    l[j+1] = l[j]
                    j = j -1
                l[j+1] = l[0]
            i = i + 1
        print(l)

    if __name__ == '__main__':
        insert_sort(l)
        input()
