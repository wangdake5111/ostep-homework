1. 
Segmentation Fault
2. 
it shows me where the Segmentation Fault occurs
3. 
```
==20966== Memcheck, a memory error detector
==20966== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==20966== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==20966== Command: ./a.out
==20966== 
==20966== Invalid read of size 4
==20966==    at 0x1086AC: main (null.c:7)
==20966==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==20966== 
==20966== 
==20966== Process terminating with default action of signal 11 (SIGSEGV)
==20966==  Access not within mapped region at address 0x0
==20966==    at 0x1086AC: main (null.c:7)
==20966==  If you believe this happened as a result of a stack
==20966==  overflow in your program's main thread (unlikely but
==20966==  possible), you can try to increase the size of the
==20966==  main thread stack using the --main-stacksize= flag.
==20966==  The main thread stack size used in this run was 8388608.
==20966== 
==20966== HEAP SUMMARY:
==20966==     in use at exit: 4 bytes in 1 blocks
==20966==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==20966== 
==20966== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==20966==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==20966==    by 0x10869B: main (null.c:5)
==20966== 
==20966== LEAK SUMMARY:
==20966==    definitely lost: 4 bytes in 1 blocks
==20966==    indirectly lost: 0 bytes in 0 blocks
==20966==      possibly lost: 0 bytes in 0 blocks
==20966==    still reachable: 0 bytes in 0 blocks
==20966==         suppressed: 0 bytes in 0 blocks
==20966== 
==20966== For counts of detected and suppressed errors, rerun with: -v
==20966== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```
the memory leak because of the x(pointer) is set to the address of 0x0, which the program cannot access

4. 
behave "correctly"
gdb cannot find, but valgrind can find
5. 
behave "correctly"
gdb cannot find, but valgrind can find
not correct
6. 
run and print 0(data[2])
gdb cannot find ,but valgrind can find
```
==22317== Invalid read of size 4
==22317==    at 0x108704: main (question6.c:7)
==22317==  Address 0x522d048 is 4 bytes after a block of size 4 free'd
==22317==    at 0x4C30D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
```

7. 
when run
```
free(): invalid pointer
Aborted (core dumped)
```
gdb
```
free(): invalid pointer

Program received signal SIGABRT, Aborted.
```
valgrind
```
==22411== Invalid free() / delete / delete[] / realloc()
==22411==    at 0x4C30D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==22411==    by 0x1086AF: main (question7.c:5)
==22411==  Address 0x522d048 is 8 bytes inside a block of size 400 alloc'd
==22411==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==22411==    by 0x10869B: main (question7.c:4)
```
8. 
See test8.c