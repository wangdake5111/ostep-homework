1.  Yes, it does. It tells me what is in race(e.g read or write)

2.  if i remove one, there will be no race.
    if there is one lock, there will be a race like the question 1
    if there is two lock, no race

3.  there may be the situation that worker0 holds the m1 and worker1 holds the m2,
therefore they will always hold their own lock and never acquire the other lock or unlock successfully.

4.  the lock order violate

5.  there was no error , but the helgrind tells the same error, sometimes it's wrong

6.  the parent thread just spin in the loop but do nothing, wastes the cpu time

7.  there may be a data race. Not correct.

8.  correct and performant

9. no errormake 