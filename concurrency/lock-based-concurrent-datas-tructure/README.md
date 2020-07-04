1.  gettimeofday() can get microsecond

2.  
threads | time(seconds)
1       | 0.024682
2       | 0.051989
3       | 0.078453
4       | 0.060833
...     | familiar
5000    | 0.259250
didn't test the cpu

3.  

threshold: 3
3CPU with 18 threads:
0.016641s
3CPU with 24 threads:
0.014895
1CPU with 1 threads:
0.033630
threshold: 1
1CPU with 1 threads:
0.047145
2 threads:
0.097707
3 threads:
0.123472
threshold: 2
1 threads:
0.036316
3 threads:
0.111115

with thresholds up, time down
4.  
when the get and insert operate frequently
