1.  
the column "us" in CPU increases by the number of "mem"(or the program) you run
2.  
the swpd is always 0, and the free decreases when I run men and the free increases when I ctrl+c
3.  
As the machine I use it's a Virtual machine which holds 6GB, therefore, when I use ./mem 5000, the swpd is none-zero but 54.
The si is still 0 but the so is none-zero, but after the first loop, the so is back to zero
when i enter 6000,
the swpd is up to 700000, the si and so is both none-zero, but about 250000, the number of si&so in the first loop is lower than the next loops.
Besides, the bandwidth rate decreases a lot by the loop, while if you just type 5000, 5500 or less, the bandwidth rate increase.
4.  
the bi&bo increase a lot which is up to 200000, but the us decrease and the sy increases which I think it's because the OS should invoke the paging a lot.
5.  

6.  
    90% of total memory plus total swap.