1.  yes

2.  0

3.  still 0

4.  a solution: if the "os" runs the *mov  flag, %ax* with the flag = 0 just before the context switch, it will lead to a bad result

5.  see the code

6.  works.

7.  
```
./x86.py -p test-and-set.s -M mutex,count -R ax,bx -c -a bx=10,bx=10 -P 0011
```
fairness and performance

14. 
less operation of xchg, therefore, less write