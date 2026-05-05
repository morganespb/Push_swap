*This activity has been created as part of the 42 curriculum by mosimon, lcoant--*

# Push_Swap

## Description
The goal of this activity was to use a set of operation to sort a given stack with as less operations as possible.
The algorithms were of :
- O(n^2)
- O(n√n)
- O(n log n)<br><br>
#### And the operations were :
- sa
- sb
- ss
- pa
- pb
- ra
- rb
- rr
- rra
- rrb
- rrr<br><br>
#### And we had to handle 5 kind of flag :
- --simple<br>
  Which trigered the O(n^2) algorithm
- --medium<br>
  Which trigered the O(n√n) algorithm
- --complex<br>
  Which trigered the O(n log n) algorithm
- --adaptive<br>
  Which trigered an algorithm depending on the disorder value of the given stack
- --bench<br>
  Which trigered the benchmark mode to display info on the operations

## Instructions
To compile our project you can use the make command
    make
Then you just have to use the "push_swap" executable with a stack and/or some flags

## Resources
As resources we used :
- StackOverflow
- Reddit
- Google
- Algorithms visualisation website
- Youtube tutorial

For the IA use :
- I use IA to find usefull resources such as visualisation website and divers youtube videos

## The Algorithms that we used
### O(n^2)
- Insertion_sort
The insertion sort is the most optimised algorithms for this kind of operations, it's pretty staigth forward and can be combined with a bucket_sort
Moreover it can be optimised to have way better performance than a bubble sort that we also tried to use !
### O(n√n)
- Chunk_sort
### O(n log n)
- Radix_sort
### Parsing algorithm
We also used a parsing algorithm to handle flag and to populate our stack !
