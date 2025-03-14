problem 1b

- First we prove that there are no such integers $n$ such that $n$ is prime and $n^2 + 2$ is prime, other than $n=3$:

  - Notice that dividing multiple prime numbers $l=n^2+2$ yields a remainder of 0 for $n>3$. For example, $\frac{(7)^2+2}{3}=\frac{49+2}{3}=\frac{51}{3}=17\cdot 3 + 0$. This could also be written as $(7^2 + 2) (rem 3)=0$
    - $(3^2 + 2)(rem 3)=2$  <-- n = 3 does not obey this
    - $(7^2 + 2)(rem 3)=0$
    - $(11^2 + 2)(rem3)=0$
    - $(13^2 + 2)(rem3)=0$
  - With this insight, we can prove by cases for $n>3$:
    - $n (rem 3)=0$
      - In this case, $n$ is not a prime since it is divisible by 3 if $n(rem3)=0$.
    - $n(rem 3)=1$
      - In this case, $(n^2+2)(rem3)=(1^2 +2)(rem3)=0$. So $n^2+2$ is not a prime since it is divisible by 3 if $n(rem3)=1$.
    - $n(rem3)=2$ 
      - In this case, $(n^2 + 2)(rem3)=(2^2 + 2)(rem3)=6(rem3)=0$. So $n^2 + 2$ is not a prime since it is divisible by 3 if $n(rem3)=2$.
    - Now we only have to prove that the claim only works for $3$, and not $2$ or $1$ (which are both also prime).
      - Case $n=1$:
        - $(n^2 + 2)(rem3)=(1^2 + 2)(rem3)=0$. So $n^2 + 2$ is not prime if $n=1$, since it is divisible b 3.
      - Case $n=2$:
        - $(n^2 +2)(rem3)=(2^2 + 2)(rem3)=6(rem3)=0$. So $n^2 + 2$ is not prime if $n=2$ since it is divisible by 3.
      - Last case, $n=3$:
        - $(n^2 + 2)(rem3)=(3^2 + 2)(rem3)=11(rem 3)=2$.
        - Here we can observe that both $n$ and $n^2 + 2$ are prime.

- Now that we know that only $n=3$ obeys the property where $n$ is a prime such that $n^2 + 2$ is a prime. 

- So since $n=3$ is the only case where this holds, to prove that if $n=3$, $m=n^3 + 2$ is a prime:

  - $n=3$:  $n^3 + 2=3^3 + 2=27+2=29$
  - $29$ is a prime, so the property holds that for all $n$ such that $n$ is a prime and $n^2 + 2$ is a prime, $m=n^3 + 2$ is also a prime.

- Thus we have proved by cases of all possibilities of the remainder of all prime numbers $n>3$ and seeing whether both $n$ and $n^2 +2$ are primes for such cases.

  

problem 3d

- We know that $\phi(n)$ denotes all numbers $q$ less than $n$ such that $q$ and $n$ are coprime.
- Further, we know that if $p$ is a prime, then $\phi(p^k)=p^k - p^{k-1}$.
-  Finally, we know that the inverse $i$ of a number $a\pmod{p}$ can only exist if $a$ and $p$ are coprime.
- Thus to find how many integers have inverses modulo $144$, we need to find $\phi(144)$.
  - $\phi(144)=\phi(72\cdot 2)=\phi(36\cdot2\cdot2)=\phi(18\cdot2\cdot2\cdot2)=\phi(9\cdot2\cdot2\cdot2\cdot2)$
  - $\phi(9\cdot2\cdot2\cdot2\cdot2)=\phi(3^2 \cdot 2^4)$
- From the property $\phi(m\cdot n)=\phi(m)\cdot \phi(n)$:
  - $\phi(3^2 \cdot 2^4)=\phi(3^2) \cdot \phi(2^4)$
- $3$ and $2$ are prime, and if $p$ is prime, then $\phi(p^k)=p^k - p^{k-1}$. We can use this to solve for $\phi(144)$:
  - $\phi(144)=\phi(3^2) \cdot \phi(2^4)$
  - $\phi(3^2) \cdot \phi(2^4)=(3^2 - 3^1) \cdot(2^4 - 2^3)=(9-3)\cdot(16-8)=6\cdot8=48$

- Thus there are $48$ integers that have inverses modulo $144$.

- Extra:

  - To ensure this number works, we wrote a small Python script:

    ```python
    coprime_count = 0;
    # For numbers i=1 up to and incluing 143
    for i in range(1, 144):
        
        # Check if i and 144 are coprime
    	if gcd(i, 144) == 1:
    		# Add one to the count
    		coprime_count += 1
    
    # Thus we are counting how many numbers from 1 to 143 are coprime with 144, all of which would have inverses.
    # Result was indeed 48.
    ```

    
