1.  
```
./paging-linear-translate.py -P 1k -a 1m -p 512m -n 0 -v
./paging-linear-translate.py -P 1k -a 2m -p 512m -n 0 -v
./paging-linear-translate.py -P 1k -a 4m -p 512m -n 0 -v
```
**as the size of the address space increases, the number of the entry of the page table will increases too**
```
./paging-linear-translate.py -P 1k -a 1m -p 512m -n 0 -v
./paging-linear-translate.py -P 2k -a 1m -p 512m -n 0 -v
./paging-linear-translate.py -P 4k -a 1m -p 512m -n 0 -v
```
**as the size of the Page size increases, the number of the entry of the page table will decreases**
2.  
```
./paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 0 -c
./paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 25 -c
./paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 50 -c
./paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 75 -c
./paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 100 -c
```
**the number of valid bits increase**
3.  
```
./paging-linear-translate.py -P 8 -a 32 -p 1024 -v -s 1
./paging-linear-translate.py -P 8k -a 32k -p 1m -v -s 2
./paging-linear-translate.py -P 1m -a 256m -p 512m -v -s 3
```
in the case:**the second**, because the **Virtual Address Trace** it generates all points to the page which is not valid
in general: **the first**, which the page size and the address space is too small, **the third**, which the page size is too big
4.  
```
./paging-linear-translate.py -P 1m -a 256m -p 128m -v -s 3 -c
```
It's the scene that the address space > the physical space
print out **Error: physical memory size must be GREATER than address space size (for this simulation)**
```
./paging-linear-translate.py -P 1024m -a 256m -p 512m -v -s 3 -c
```
It's the scene that the Page size > the address space
print out: 
**Page Table (from entry 0 down to the max size)**

**Virtual Address Trace**
**Traceback (most recent call last):**
  **File "./paging-linear-translate.py", line 174, in <module>**
    **if pt[vpn] < 0:**
**IndexError: array index out of range**