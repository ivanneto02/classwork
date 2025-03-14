a) Finding number of tilings $A_n$:

First we consider the initial conditions. We suspect that since we have three different types of tiles, we will need 3 initial conditions:

- $n=0\rightarrow0\times1$ tile: 1 tiling (the empty tiling)
- $n=1\rightarrow1\times1$ tile: 3 tilings (three possibilities for the $1\times1$ tiles, one for each color)
- $n=2\rightarrow2\times1$ tile:
  - Filling with $1\times1$ tiles:
    - If tile 1 is dark-blue
      - 3 tilings
        - (dark-blue, dark-blue)
        - (dark-blue, light-blue)
        - (dark-blue, red)
    - If tile 1 is light-blue
      - 3 tilings
        - (light-blue, light-blue)
        - (light-blue, dark-blue)
        - (light-blue, red)
    - If tile 1 is red
      - 3 tilings
        - (red, red)
        - (red, light-blue)
        - (red, dark-blue)
    - Total: 9 tilings
  - Filling with a single $2\times1$ tile:
    - 1 tiling, which is a single green tile
  - Total = 10 tilings, or $A_{2}=10$

Initial conditions:

​	$A_0 =1$

​	$A_1=1$

​	$A_2=10$

There are three main cases of tiles we can place at the end of an $n\times1$ tile:

1. Placing a $1\times1$ tile
   - There are three different colors (dark-blue, light-blue, and red) that the $1\times1$ tiles can be.
   - Further, we are looking at a depth of $-1$ from $n$, since we are placing a $1\times1$ tile to complete an $n\times1$ long tile.
   - Therefore, the case where the last tile we can place is a $1\times1$ tile represents $3A_{n-1}$. The "$3$" represents the number of colors.
2. Placing a $2\times1$ tile
   - There is a single color (green) that these tiles can be.
   - Further, we are looking at a $-2$ depth from $n$, since we are placing an $2\times1$  tile to complete an $n\times1$ long tile.
   - Therefore, the case where the last tile we can place is a $2\times1$ tile represents $A_{n-2}$. Notice now there is an implicit "$1$" in front of $A_{n-2}$, which represents the number of possible colors that a $2\times1$ tile could be.
3.  Placing a $3\times1$ tile
   - There is a single color (sky-blue) that these tiles can be.
   - Further, we are looking at a $-3$ depth from $n$, since we are placing a $3\times1$ tile to complete an $n\times1$ long tile.
   - Therefore, the case where the last tile we can place is a $3\times1$ tile represents $A_{n-3}$. Notice there is the same implicit "$1$" in front of $A_{n-3}$.

- Finally, in order to place all of these cases together, we need to realize that these are disjoint sets of possible tilings depending on how we choose the last tile to complete an $n\times1$ long tile. They are disjoint because we are placing tiles of different sizes at the end of the $n\times1$ long tile, thus it would be impossible for these sets to overlap.

- Therefore, adding these three cases together will yield the number $A_n$ of possible tilings given the configurations:
  - $A_n = 3A_{n-1}+A_{n-2}+A_{n-3}$



b) Finding number of tilings $T_n$ such that blue tiles cannot be next to each other.

Like in part a, the first step would be to compute the initial conditions. We suspect that since we have three different types of tiles, we will need 3 initial conditions:

- $n=0\rightarrow0\times1$ tile: 1 tiling (the empty tiling)
- $n=1\rightarrow1\times1$ tile: 3 tilings (three possibilities for the $1\times1$ tiles, one for each color)
- $n=2\rightarrow2\times1$ tile:
  - Filling with $1\times1$ tiles:
    - If tile 1 is dark-blue
      - 1 tilings
        - (dark-blue, red)
    - If tile 1 is light-blue
      - 1 tilings
        - (light-blue, red)
    - If tile 1 is red
      - 3 tilings
        - (red, red)
        - (red, light-blue)
        - (red, dark-blue)
    - Total: 5 tilings
  - Filling with a single $2\times1$ tile:
    - 1 tiling, which is a single green tile
  - Total = 6 tilings, or $A_{2}=6$

Initial conditions:

​	$A_0 =1$

​	$A_1=1$

​	$A_2=6$

// TODO: complete this part. I am leaving it for later because I know how to do it, it's just too tedious for now.