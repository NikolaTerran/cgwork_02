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


y = mx + b
0 = mx - y + b
0 = (delta y/delta x)x -y -b
0 = (delta y )x - (delta x)y + (delta x)b
A = delta y
B = - delta x
C = delta x * b



/*

y2 > y1
x2 > x1

m = (y1 - y2) / (x2 - x1)

determine octants

 32
4  1
5  8
 67

if(y2 < y1){
	if(x2 > x1){
	    if( m <= 1 ){
	         1
	    }else{
	         2
	    }
	}else{
	    if( m <= -1 ){
	         3
	    }else{
	         4
	    }
	}
}else{
   if(x2 < x1){
	    if( m <= 1 ){
	         5
	    }else{
	         6
	    }
	}else{
	    if( m <= -1 ){
	         7
	    }else{
	         8
	    }
	}
}

switch(octants){
	case 1: right up
	break;
	case 2: up right
	break;
	case 3: up left
	break;
	case 4: left up
	break;
	case 5: left down
	break;
	case 6: down left
	break;
	case 7: down right
	break;
	case 8: right down
	break;
}









*/























