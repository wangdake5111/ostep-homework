1. 
```python
./lottery.py -j 3 -s 0 -c
./lottery.py -j 3 -s 1 -c
./lottery.py -j 3 -s 2 -c
```
2. 
```python
./lottery.py -j 2 -l 10:1,10:100 -c
```
Before the job which there are 100 tickets finish, another job never work
3. 
```python
./lottery.py -j 2 -l 100:100,100:100 -s 0 -c
./lottery.py -j 2 -l 100:100,100:100 -s 1 -c
./lottery.py -j 2 -l 100:100,100:100 -s 2 -c
./lottery.py -j 2 -l 100:100,100:100 -s 3 -c
./lottery.py -j 2 -l 100:100,100:100 -s 4 -c
./lottery.py -j 2 -l 100:100,100:100 -s 5 -c
```
the earlier one is early for 1~20 time
4. 
```python
./lottery.py -j 2 -l 1000:100,1000:100 -s 0 -c
./lottery.py -j 2 -l 1000:100,1000:100 -s 1 -c
```
the absolute number is larger, but the proportion is lower

5. 
TBD