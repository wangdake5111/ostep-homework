1.  
the output will change as which thread runs first.
2.  
there may be deadlock. not always
```
./vector-deadlock -n 2 -l 10000 -d -v
```
3.  
if the value is 1, no deadlock
4.  
the lock is always the same order.
because calling lock to the same lock twice will leads to the deadlock
5.  
0.02seconds
all increase
6.  
the time will decrease as they won't be blocked when they call the lock
7.  
faster than the global order
the retries increase as the number of threads increases
8.  
is correct but performance is not well when there are lots of vectors, because all vectors run add should call the global_lock.
9.  
yes. Using the fetch\_and\_add
10. 
Using the -p will make the performance better.
