INDR 520 - Network Models and Optimization Term Project
=======================================================

Performance wise comparison of Dijkstra's original and modified algorithms on the same data.

Index
-----
- `Algorithms`_
- `Builds`_
- `Build Debug`_
- `Build Release`_
- `Run`_
- `Performance`_

Algorithms
----------
- Original
    Runs in O(V^2).
- Priority Queue
    Runs in O(ElogV + VlogV).
- Fibonacci Heap
    Runs in O(E + VlogV).


Builds
------
- Debug
    Displays additional information: distance and previous arrays. Suited for debugging.
- Release
    Displays paths between source and target nodes, and execution times. Suited for evaluating performance.

Build Debug
-----------
Execute in terminal:

::

    cd src/
    make clean && make debug

Build Release
-------------
Execute in terminal:

::

    cd src/
    make clean && make

Run
---
Execute in terminal:

::

    cd src/
    make run

Performance
-----------
======= ======= ========== =========== =======
     Graph         Algorithm Time (seconds)
--------------- ------------------------------
Nodes   Edges   Original   Modified    Speedup
======= ======= ========== =========== =======

======= ======= ========== =========== =======

References
----------
.. [#] http://www.boost.org/doc/libs/1_49_0/doc/html/boost/heap/fibonacci_heap.html