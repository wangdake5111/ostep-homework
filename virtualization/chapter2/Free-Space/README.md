1. 
```
./malloc.py -n 10 -H 0 -p BEST -s 0 -c
```
there are more and more little fragmentation which i think they will be never used anymore
2. 
```
./malloc.py -n 10 -H 0 -p WORST -s 0 -c
```
there are more and more little fragmentation which is larger than the question 1, but before the big entry of the free list use up, there is no chance for them to work.
3.  
```
./malloc.py -n 10 -H 0 -p FIRST -s 0 -c
```
The number of search item decreases
4.  
```
./malloc.py -n 10 -H 0 -p FIRST -s 0 -l ADDRSORT -c
./malloc.py -n 10 -H 0 -p FIRST -s 0 -l SIZESORT+ -c
./malloc.py -n 10 -H 0 -p FIRST -s 0 -l SIZESORT- -c
```
only use the FIRST is because the other two is global search
if the size of the request increases, the SIZESORT- will be better.

5.  
```
./malloc.py -n 1000 -H 0 -p FIRST -s 0 -c -C
./malloc.py -n 1000 -H 0 -p FIRST -s 0 -c
```
if there is no flag "-C", the free list will contain a huge number of fragmentation
6.  
```
./malloc.py -n 1000 -H 0 -p FIRST -s 0 -c -P 100 -C
./malloc.py -n 1000 -H 0 -p FIRST -s 0 -c -P 0 -C
```
After all the space uses up, all the malloc() will fail
if the percentage < 50, actually the behaviours is equal to the scene that the percentage = 50
7.  
**if with "-C"**
```
./malloc.py -p FIRST -C -A +10,+11,-1,+12,+13,+14,-3,+15 -c
// you can write indefinitely as the +a, +(a+1), -n, +(a+2) as a loop, n starts as 1 and adds 2 every loop
```
**if without "-C"**
```
millions of ways just pick one
./malloc.py -n 1000 -H 0 -p FIRST -s 0 -c
```