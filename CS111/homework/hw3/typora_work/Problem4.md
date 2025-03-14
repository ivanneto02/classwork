Find a particular solution of the recurrence equation $t_n=4t_{n-1}-4t_{n-2}+3\cdot2^n$



There are 5 steps we have to complete to find the particular solution

1. Find the characteristic equation of the homogeneous equation associated to the recurrence **and its roots**.
2. Determine whether $s$ is in the set of the roots found in step 1.
3. Given step 2, write the general form of $3\cdot2^n$ in terms of $n$ and $\beta$.
4. Plug step 3 into the recurrence, and solve for $\beta$.
5. $\beta$ is the particular solution of the given recurrence equation.



Step 1:

- The homogeneous part of the recurrence equation is $t_n=4t_{n-1}-4t_{n-2}$. To find the characteristic equation, first we realize that $t_n$ is growing exponentially, so we can replace it with $x^{n}$:

  - $x^n=4x^{n-1}-4^{n-2}$

- Dividing both sides by the term of most recurrence depth ($4^{n-2}$), we obtain a quadratic formula:

  - $x^2=4x-4$
  - $x^2-4x+4=0$

- We can factor this quadratic formula:

  - $x^2-4x+4=(x-2)(x-2)=0$

- Thus we have found two roots, $x_1$ and $x_2$, such that $x_1=x_2=2$

  

Step 2:

- The last step was extremely important because the general form of the non-homogeneous part of the recurrence equation depends on whether $s=2$ is part of the roots of the characteristic equation.
  - We have found that **it indeed is part of the root**, and in fact both roots are 2.
- There are two roots so the multiplicity $m$ is 2.



Step 3:

- Since $s$ is a root of the characteristic equation with $m=2$, we can write the particular solution in the form:
- $f^{''}(n)=n^m(\beta)s^n=\beta n^m s^n$
  - The reason the inside of the parenthesis is $\beta$ is because the polynomial associated with the non-homogeneous section of the recurrence equation is a constant $3$, so its general form is a constant $\beta$.
- Plugging in, $f^{''}(n)=\beta n^2 2^n$



Step 4:

- We found that $f^{''}(n)=\beta n^2 2^n$
- We now need to plug this solution into the original recurrence equation.
- We have:
  - $t_n=4t_{n-1}-4t_{n-2}+3\cdot 2^n$
  - $\beta n^2 2^n =4 \beta (n-1)^2 2^{n-1} - 4 \beta (n-2)^2 2^{n-2} + 3\cdot 2^n$

- Now we solve for $\beta$
  - $\beta n^2 2^n =4 \beta (n-1)^2 2^{n-1} - 4 \beta (n-2)^2 2^{n-2} + 3\cdot 2^n$
  - We recognize the fact that this equation applies for all $n$
    - Plugging in 0
      - $\beta 0^2 2^0 =4 \beta (0-1)^2 2^{0-1} - 4 \beta (0-2)^2 2^{0-2} + 3\cdot 2^0$
      - $0=4 \beta 2^{-1} - 4 \beta \cdot4\cdot 2^{-2} + 3$
      - $0=2\beta - 4\beta+3$
      - $2\beta =3$
      - $\beta = 2/3$
- $\beta=2/3$



Step 5:

- Thus $\beta=2/3$ is the particular solution to the recurrence equation.