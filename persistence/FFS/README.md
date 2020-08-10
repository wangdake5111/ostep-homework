1.  
```
./ffs.py -f in.largefile -L 4 -c
```
2.  
```
./ffs.py -f in.largefile -L 30 -c
```
3.  
```
./ffs.py -f in.largefile -L 4 -T -c
./ffs.py -f in.largefile -L 100 -T -c
```
distance will decrease
4.  
```
./ffs.py -f in.manyfiles -v -c
```
5.  
```
./ffs.py -f in.manyfiles -c -T
```
to keep the file in the group in which the dir stay
6.  
```  
./ffs.py -f in.manyfiles -i 5 -c
```
before the inodes are out of space, the step is at the same, but after, the file will just be put in the next block in order but not with the group.
在目录所在的block的inode被用完之前，和原来的layout是一致的，但是当用完了之后，文件的inode就会在后面的block里面分配，但只会根据创建顺序排列而不会根据属于哪个dir排列。
7.  
```
./ffs.py -f in.manyfiles -I 5 -A 2 -c
```
8.  
```
./ffs.py -f in.fragmented -v -c
```
we can't read sequently, thus wasting lots of time.
9.  
```
./ffs.py -f in.fragmented -v -C 2 -c
```
-C 2:如果有两个以上连续的空闲块，就会分配直到只剩下小于两个的时候。
会增加filespan和dirspan。