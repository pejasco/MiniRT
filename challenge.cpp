/*
But looking at (4, -4, 3) and (-4, 4, -3), it’s impossible to know that one is a point
and the other is a vector. Let’s add a fourth component to these (x, y, z) tuples,
called w, to help us tell them apart. Set w to 1 for points, and 0 for vectors.
Thus, your point becomes (4, -4, 3, 1), and your vector becomes (-4, 4, -3, 0).
*/

Beware of comparing floating point values using simple equivalency.
Round-off error can make two numbers that should be equivalent instead 
bt slightly different.

Now that you have these tuples. You're faced with the question of how to use
them. But to plug these vectors and points into your calculations, you need to
implement a few basic operation on them.

Let's start with some familiar operation from arithemet


