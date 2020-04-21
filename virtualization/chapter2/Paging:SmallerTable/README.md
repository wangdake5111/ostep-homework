1.  
    2   3

2.  
```
./paging-multilevel-translate.py -s 1 -c
./paging-multilevel-translate.py -s 2 -c
./paging-multilevel-translate.py -s 3 -c
```
if you don't know how to get the answer, contact me
3.  
in my opinion, the memory reference to the page table will be in the cache in a long time, i.e there will be a lot of hits, because all the other memory reference will first request the memory reference to the page table, therefore, they will stay in the cache for a long time.