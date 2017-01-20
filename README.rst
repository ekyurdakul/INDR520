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
- `Output`_
- `References`_

Algorithms
----------
- Original
    Time complexity :math:`O(V^2)`.
- Priority Queue
    Time complexity :math:`O(ElogV + VlogV)`.
- Fibonacci Heap
    Time complexity :math:`O(E + VlogV)`.

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
======= ========= ========== =========== ============
   Sparse Graphs   Algorithm Execution Time (seconds)
----------------- -----------------------------------
Nodes   Edges     Original   Priority Q. Fibonacci H.
======= ========= ========== =========== ============
5000	7551	  0.01453350  0.00225474  0.00157541
10000	15083	  0.05645620  0.00603183  0.00316576
15000	22487	  0.12675300  0.00718556  0.00494829
20000	29924	  0.21752400  0.01034570  0.00710255
25000	37472	  0.34081000  0.01231350  0.00912960
30000	44972	  0.49399400  0.01981080  0.01279050
35000	52493	  0.67769400  0.03279780  0.01458860
40000	59703	  0.87710800  0.02685750  0.01784510
45000	67421	  1.11453000  0.02989110  0.02079070
50000	74995	  1.38177000  0.03258490  0.02481610
======= ========= ========== =========== ============

======= ========= ========== =========== ============
   Dense Graphs   Algorithm Execution Time (seconds)
----------------- -----------------------------------
Nodes   Edges     Original   Priority Q. Fibonacci H.
======= ========= ========== =========== ============
5000	6265651	  0.02480550 0.34428200	 0.01225290
10000	25161345  0.09720100 0.90417800	 0.04267040
15000	56801856  0.22274300 2.41470000	 0.09146120
20000	99821596  0.39241200 5.08784000	 0.15884700
25000	157286814 0.61514000 8.84425000	 0.24630600
30000	224689239 0.88431300 11.18020000 0.35419200
35000	305295027 1.20697000 14.64010000 0.47419900
40000	398811582 1.58194000 20.23180000 0.61352200
45000	506352340 2.03314000 35.35780000 0.77981400
50000	628455174 2.52489000 43.11340000 0.99360200
======= ========= ========== =========== ============

Output
------
A sample output is in **src/output.txt**

References
----------
.. [#] http://www.boost.org/doc/libs/1_49_0/doc/html/boost/heap/fibonacci_heap.html
