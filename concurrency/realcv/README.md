1.  YES

2.  
```
./main-two-cvs-while -l 100 -m 10 -p 1 -c 1 -v -C 0,0,0,0,0,0,1
```
the num_full is limited to the buffersize and influenced by the numbers of produced items.
if you add the -C 0,0,0,0,0,0,1 . the consumer will sleep at p6 and the producer may work in a long time which makes the num_full up to the number of buffer size

3.  
in the linux, if you don't use the -C, the num_full will probably be 0 or 1.
the possibility is much larger than the mac
4.  
at least 10 seconds

5.  
the time may decrease because there may be a situation like the producer produces over 1 items, therefore there will be less c3 pause.

6.  
the time is 5 seconds, as consumers will sleep at p6, but the lock is released, therefore, other pthreads can move on.

7.  
equal to the question 6

8.  
No
9.  
like figure30.10, but i cannot write the code, as always the producer will just switch from p0 to c3 as i cannot let the consumer run first and let the producer not fall asleep in the second loop at the same time.

10. 
use while

11. 
```
./main-two-cvs-while-extra-unlock -p 1 -c 2 -m 10 -l 10 -v -C 0,0,0,0,1,0,0:0,0,0,0,0,0,0
```
the c0 fall asleep but not in queue, therefore no one wakes him up which leads to the c0 just consumes only one item.