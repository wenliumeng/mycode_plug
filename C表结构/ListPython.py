# -*- coding: utf-8 -*-

class Node(object):
    def __init__(self,val,p=0):
        self.data = val
        self.next = p

class LinkList(object):
    def __init__(self):
        self.head = 0

    def getlength(self):
        p = self.head
        length = 0;
        while p!=0:
            length+=1
            p = p.next
        return length


    def is_empty(self):
        if self.getlength() == 0:
            return True
        else:
            return False

    def clear(self):
        self.head = 0

    def getitem(self,index):
        if self.is_empty():
            print 'Linklist is empty.'
            return
        j= 0;
        p = self.head
        while p.next != 0 and j < index:
            p = p.next
            j+=1
        if j == index:
            return p.data
        else:
            print 'target is not exist'

    def initlist(self,data):
        self.head = Node(data[0])

        p = self.head

        for i in data [1:]:
            node = Node(i)
            p.next = node
            p = p.next

    def __getitem__(self,i):
        if self.is_empty():
            print 'linklist is empty.'
            return
        elif i < 0 or i > self.getlength():
            print 'the given key is error'
            return
        else:
            return self.getitem(i)

    def insert(self,index,item):
        if self.is_empty() or index < 0 or index > self.getlength():
            print 'Linklist is empty'
            return

        p = self.head
        post = self.head
        j = 0
        while p.next != 0 and j<index:
            post = p
            p = p.next
            j+=1

        if index == j:
            q = Node(item,p)
            post.next = q
            q.next = p

    def delete(self,index):
        if self.is_empty() or index < 0 or index > self.getlength():
            print 'Linklist is empty'
            return

        p = self.head
        post = self.head
        j=0
        while p.next != 0 and j < index:
            post = p
            p = p.next
            j++
        if index == j:
            post.next = p.next
