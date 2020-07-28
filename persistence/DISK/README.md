1.  
```
./disk.py -a 0
Block:   0  Seek:  0  Rotate:165  Transfer: 30  Total: 195

TOTALS      Seek:  0  Rotate:165  Transfer: 30  Total: 195
```
```
./disk.py -a 6
REQUESTS ['6']

Block:   6  Seek:  0  Rotate:345  Transfer: 30  Total: 375

TOTALS      Seek:  0  Rotate:345  Transfer: 30  Total: 375
```
```
./disk.py -a 30
Block:  30  Seek: 80  Rotate:265  Transfer: 30  Total: 375

TOTALS      Seek: 80  Rotate:265  Transfer: 30  Total: 375
```
```
./disk.py -a 7,30,8
Block:   7  Seek:  0  Rotate: 15  Transfer: 30  Total:  45
Block:  30  Seek: 80  Rotate:220  Transfer: 30  Total: 330
Block:   8  Seek: 80  Rotate:310  Transfer: 30  Total: 420

TOTALS      Seek:160  Rotate:545  Transfer: 90  Total: 795
```
```
./disk.py -a 10,11,12,13
Block:  10  Seek:  0  Rotate:105  Transfer: 30  Total: 135
Block:  11  Seek:  0  Rotate:  0  Transfer: 30  Total:  30
Block:  12  Seek: 40  Rotate:320  Transfer: 30  Total: 390
Block:  13  Seek:  0  Rotate:  0  Transfer: 30  Total:  30

TOTALS      Seek: 40  Rotate:425  Transfer:120  Total: 585
```
2.  
```
./disk.py -a 30 -S 2
Block:  30  Seek: 40  Rotate:305  Transfer: 30  Total: 375

TOTALS      Seek: 40  Rotate:305  Transfer: 30  Total: 375
```
S will decrease the time of seek, but the total time won't be affected which the transfer time is without change but the rotation time increase.
3.  
```
./disk.py -a 30 -S 0.5

Block:  30  Seek: 80  Rotate:610  Transfer: 60  Total: 750

TOTALS      Seek: 80  Rotate:610  Transfer: 60  Total: 750
```
R will affect the rotation time and the transfer time.
4.  
SSTF:
Block:   7  Seek:  0  Rotate: 15  Transfer: 30  Total:  45
Block:   8  Seek:  0  Rotate:  0  Transfer: 30  Total:  30
Block:  30  Seek: 80  Rotate:190  Transfer: 30  Total: 300

TOTALS      Seek: 80  Rotate:205  Transfer: 90  Total: 375


5.  
```
./disk.py -a 7,2,23 -G -p SSTF
Block:   7  Seek:  0  Rotate: 15  Transfer: 30  Total:  45
Block:   2  Seek:  0  Rotate:180  Transfer: 30  Total: 210
Block:  23  Seek: 40  Rotate:200  Transfer: 30  Total: 270

TOTALS      Seek: 40  Rotate:395  Transfer: 90  Total: 525
```
```
./disk.py -a 7,2,23 -G -p SATF
Block:   7  Seek:  0  Rotate: 15  Transfer: 30  Total:  45
Block:  23  Seek: 40  Rotate: 50  Transfer: 30  Total: 120
Block:   2  Seek: 40  Rotate: 20  Transfer: 30  Total:  90

TOTALS      Seek: 80  Rotate: 85  Transfer: 90  Total: 255
```
if the SATF will cost more time in rotation, the SSTF will be better

6.  
when the seek occurs, it will rotate to the end of the 12, which will make us rotate one more circle.
skew = ceil(40/(S*30))

8.  
-w 1
TOTALS      Seek:20960  Rotate:169165  Transfer:30000  Total:220125
-w 10
TOTALS      Seek:8080  Rotate:26555  Transfer:30000  Total:64635
-w 100
TOTALS      Seek:1440  Rotate:5835  Transfer:30000  Total:37275
-w 1000 //best
TOTALS      Seek:1520  Rotate:3955  Transfer:30000  Total:35475

9.  
```
./disk.py -a 7,8,9,10,33,34,35,11,0,1,2,3,4,5,6 -p BSATF -w 4
```
thiw will solve the starvation. It will select the next request in the 4 blocks but not in the whole requests. Therefore, it will decrease the performance.
10. 
```
./disk.py -a 9,20 -c 
TOTALS      Seek: 40  Rotate:335  Transfer: 60  Total: 435
```
```
./disk.py -a 9,20 -c -p SATF
TOTALS      Seek: 80  Rotate:325  Transfer: 60  Total: 465
```


