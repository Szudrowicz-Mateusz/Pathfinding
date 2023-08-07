This is a Visualisation of Pathfinding algorithms.

BFS, Dijkstra, A*

By the way Dijkstra doesn't work and I never comeback for him. So only BFS and A* is working.

In **main.cpp** you have showned keys to trigger appropriate actions. Here I will leave little instructions :

    Left shift + left mouse click = starting position
    Left ctrl + left mouse click = destination point
     mouse click = setting walls
    B (on keyboard) = start BFS algorithm
    A (on keyboard) = start A* algorithm
    D (on keyboard) = start Dijkstra algorithm
    R (on keyboard) = reset map

Don't be confused becasue during algorithm you can't take any actions. If algorithm ends up you can easily press "R" and check other combinations.

To run program by cmake in terminal:

    1) mkdir build
    2) cd build
    3) cmake ..
    4) make
    5) ./p

If someone doesn't like name of the project you can easily change it in 3 line in CMakeLists.txt

Project created by **https://github.com/Szudrowicz-Mateusz**
