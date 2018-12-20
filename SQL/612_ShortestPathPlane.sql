Table point_2d holds the coordinates (x,y) of some unique points (more than two) in a plane.

Write a query to find the shortest distance between these points rounded to 2 decimals.
| x  | y  |
|----|----|
| -1 | -1 |
| 0  | 0  |
| -1 | -2 |
The shortest distance is 1.00 from point (-1,-1) to (-1,2). So the output should be:
| shortest |
|----------|
| 1.00     |
Note: The longest distance among all the points are less than 10000.

SELECT ROUND(SQRT(MIN(POWER((t1.x - t2.x), 2) + POWER((t1.y - t2.y), 2))), 2) AS shortest
FROM point_2d t1 JOIN point_2d t2 ON t1.x !=t2.x OR t1.y!=t2.y

select ROUND(SQRT(min((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))),2) as shortest
from point_2d p1,point_2d p2
where p1.x <> p2.x or p1.y <> p2.y;