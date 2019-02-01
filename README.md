# cgwork_02
Bresenham's line Algorithm

find the pixels that best form a given line
limited to integer coordinates

starting assumptions:
 (x0,y0) -> (x1,y1)
1.x0,x1,y0,y1 are integers
2.x0 <= x1
3.0 <= m <= 1

octants

        \  |  /
         \ | /
          \|/
-----------------------
          /|\
	 / | \
        /  |  \
	
-----------------------------------------------------------------
|           |          |          |         |          | x1 y1  |
-----------------------------------------------------------------
|           |          |          |         |          |        |
-----------------------------------------------------------------
|eliminated | option 1 |          |         |          |        |
-----------------------------------------------------------------
| x0 y0     | option 2 |          |         |          |        |
-----------------------------------------------------------------

1. x0 + 1, y0 + 1
2. x0 + 1, y0

test midpoint: (x0 + 1, y0 + 1/2)
if above, option 1
if below, option 2
if middle, alternate
