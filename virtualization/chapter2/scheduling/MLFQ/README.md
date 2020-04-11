1. 
```python
    ./mlfq.py -n 2 -q 2 -j 2 -m 20 -M 0 -s 0 -c
    ./mlfq.py -n 2 -q 2 -j 2 -m 20 -M 0 -s 1 -c
```
2. 
Figur 8.1:
```python
 ./mlfq.py -n 8 -j 4 -c
 ```
 Figure 8.2
 ```python
 ./mlfq.py -n 3 -q 10 -l 0,200,0 -c
 ```
 Figure 8.3
 ```python
 ./mlfq.py -n 3 -q 10 -l 0,180,0:100,20,0 -c
 ```
 Figure 8.4
 ```python
 # in 50ms-200ms, there are 25 times that B issues a IO
 ./mlfq.py -n 3 -q 10 -l 0,180,0:50,25,1 -S -i 5 -c -I
 ```
 Figure 8.5 LEFT
 ```python
./mlfq.py -n 3 -q 10 -l 0,150,0: 100,50,2:100,50,2 -S -i 2 -c
 ```
 Figure 8.5 RIGHT
 ```python
 ./mlfq.py -n 3 -q 10 -l 0,150,0: 100,50,2:100,50,2 -S -i 2 -B 50 -c
 ```
 Figure 8.6 LEFT
 ```python
 ./mlfq.py -n 3 -q 10 -l 0,160,0:70,90,9 -S -i 1 -c
 ```
 Figure 8.6 RIGHT
 ```python
  ./mlfq.py -n 3 -q 10  -l 0,160,0:70,90,9  -i 1 -c
 ```
 Figure 8.7
 ```python
 ./mlfq.py -n 3 -a 2 -Q 10,20,40 -l 0,150,0:0,150,0 -c
 ```
3. 
    1. scenario A: all come at the same time
      all parameter is okay in my opinion
    2. scenatio B: comes at the different time
        -n 1 
4. 
```python
./mlfq.py -n 2 -q 200 -l 0,2000,0:400,2000,199 -S -i 1 -c
```

5. 
60ms

6. 
```python
./mlfq.py -n 1 -q 5 -l 0,10,0:0,20,2:0,10,3  -c  -i 1 -I
```
if you remove the -I, you will find that if one's IO is done, it will still be at the end of the queue.
