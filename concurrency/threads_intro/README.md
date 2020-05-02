1.  
```
./x86.py -p loop.s -t 1 -i 100 -R dx -c
```
2.  
```
./x86.py -p loop.s -t 2 -i 100 -a dx=3,dx=3 -R dx -c
```
not affect & no race
3.  
```
./x86.py -p loop.s -t 2 -i 3 -r -a dx=3,dx=3 -R dx -c -s 2
```
no change because never access the memory
4.  
```
./x86.py -p looping-race-nolock.s -t 1 -M 2000 -c
```
5.  
```
./x86.py -p looping-race-nolock.s -t 2 -a bx=3 -M 2000 -c
```
6
6.  
```
./x86.py -p looping-race-nolock.s -t 2 -a bx=3 -i 4 -M 2000 -c -s 0
./x86.py -p looping-race-nolock.s -t 2 -a bx=3 -i 4 -M 2000 -c -s 1
./x86.py -p looping-race-nolock.s -t 2 -a bx=3 -i 4 -M 2000 -c -s 2
```
if the critical section of two is not overlapped, it's safe.
7.  
```
./x86.py -p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 1 -c
./x86.py -p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 2 -c
./x86.py -p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 3 -c
```
if the interupt is equal to the size of critical section, it's safe
8.  
3
9.  
```
./x86.py -p wait-for-me.s -a ax=1,ax=0 -R ax -M 2000 -c
```
it will be one, the value must be 1 as the **"signal"** to the cx, which will lead to the waiter be finished.
10. 
```
./x86.py -p wait-for-me.s -a ax=0,ax=1 -R ax -M 2000 -c -i 10
```
the interval should be small but not too small, it should be carefully choosed as a middle number.
not efficiently, as there are probably some time that the waiter thread should loop without meaning. 