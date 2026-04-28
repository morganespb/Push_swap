

DATA STRUCTRURE:
- create linked list
- stack size
- add node
- free stack
- print stack


PARSING
- check valid input: non numbers, duplicates, INTMIN INTMAX, empty input, display error/n
  stderr

BASIC STACK OPERATIONS
sa sb ss papb ra rb rr rra rrb rrr

OUTPUT
- modify stack
- print operation name
- count operations (bench)

SIMPLE ALGO
- min/max extraction ?

MEDIUM ALGO
- chunk based algo ?
- Turk algo ?
1) push all from A to B except 3 elements
2) sort A // A = small sorted base , B = everything else
3) reeinsertion: compute for each B element targer position in A
4) cost to move in B? cost to prepare A?
5) choose cheapest movement
6) execute move

COMPLEX ALGO
- radix ?
1) replace values by index
2) pass 1) even ? send to stack b(pb) , odd ? rotate in a(ra)
3) pass 2) digit % 2 == 0 ? pb, else ra
4) pass 3) digit % 4 == 0 ? pb, else ra

ADAPTIVE
- Disorder based selector. low disorder < 0.2, medium 0.2 - 0.5, high >= 0.5
