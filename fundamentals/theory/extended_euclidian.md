# Algorithm
The normal algorithm of finding the gcd ends with 'b' being zero and 'a' being the gcd.
We can represent 'a' and 'b' as:
a . 1 + b.0 = g

The purpose of the extended euclidian algorithm is find the coefficient that can provide the gcd.

Lets suppose we know the coefficients for (b, a mod b) as (x1, y1), such that
b . x1 + (a mod b). y1 = g
we know that a mod b = a - floor(a/b) * b
b.x1 + (a - floor(a/b)*b) . y1 = g
b.x1 + a.y1 - b. floor(a/b).y1 = g
a.y1 + b(x1 - floor(a/b). y1) = g
x = y1
y = (x1 - floor(a/b).y1)