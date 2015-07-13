#http://www.cprogramming.com/tutorial/cpreprocessor.html

// We use a trick involving exclusive-or to swap two variables
#define SWAP(a, b)  a ^= b; b ^= a; a ^= b; 

int x = 10;
int y = 5;

// works OK
SWAP(x, y);

// What happens now?
if(x < 0)
    SWAP(x, y);
