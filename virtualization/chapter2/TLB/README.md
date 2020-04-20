1.  
if you use gettimeofday(), its measurement accuracy is microseconds, therefore, but as the material says above, one access time is about 5 nanaseconds, therefore, we should time at least 1000 access time per gettimeofday().
3.  
I choose 500

5.  
gcc -O0 tlb tlb.c

6.  
you should do in linux(which mine is macos)

7.  
change the malloc to calloc