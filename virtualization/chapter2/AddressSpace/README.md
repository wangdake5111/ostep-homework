4. 
when I run 
```
./memory-user 2000
```
the "used" of the Mem increases and the "available" decreases
but the other don't change
7. 
（in the -x)
I find the **source code**(i.e memory-user), **anon**(i think is the heap), **libc-2.27.so**, **ld-2.27.so** and **stack**
(in the -X)
I find the **source code**, **heap**, **libc-2.27.so**, **ld-2.27.so**, **stack**, **vvar**, **vdso**, **vsyscall**

8. when i use diffrent arguments(2, 20, 200), the heap size is different.