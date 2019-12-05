# lem_in - 42 project

#### This project is meant to make you code an ant farm manager.

-------------



## Challenge

The goal of this project is to find the quickest way to get n ants across the farm. Quickest way means the solution with the least number of lines, respecting the output format requested below.

Your program cannot have memory leaks. You have to handle errors in a sensitive manner. In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc). Your project must be written in C in accordance with the Norm. Within your mandatory part you are allowed to use the following functions:
`* malloc`
`* free`
`* read`
`* write`
`* strerror`
`* perror`
`* exit`



-------------
## Installation and usage

Simply clone repository and run following commands:

    make
    
    ./lem-in < input_/input10nodes1

'input_/input10nodes1' is an exemple, you can try with other map.



-------------
## How lem_in works

The executable reads the map sent previously to the standard input; several steps will then take place.


#### First, we check if the map is valid, it must respect the following constraints :

    `* Number of ant at the top of the file then declaration of rooms and finally connections between rooms`

    `* Start and end declared`

    `* A path between start and end`

Example below :

![Capture d’écran 2019-12-05 à 15 18 49](https://user-images.githubusercontent.com/44836297/70245581-99ac3100-1776-11ea-9bed-1671b3716e09.png)


#### Then, we search with our algo the best path for the number of given ants

Big steps :

    `* Storage of rooms & connections in adjacent lists`

    `* A version similar to the Edmonds-Karp algorithm (& BFS) -> Our capacities are not on the connections but on the rooms (go see 'ressources/Schéma Edmonds-Karp - Graphe compliqué.pdf' if you want a concrete example)`

    `* Finding the best paths in terms of our number of ants to pass`


#### Finally, we print the maps and the ants taking the paths step by step :

![Capture d’écran 2019-12-05 à 15 37 30](https://user-images.githubusercontent.com/44836297/70245573-95801380-1776-11ea-9e32-c005a6229d2a.png)

-------------
## Author

Gaspard Moindrot (gmoindro)
Raphael Beaufret (rbeaufre)
