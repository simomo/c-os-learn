#define SWAP(a, b)  do { a ^= b; b ^= a; a ^= b; } while ( 0 )

int x = 10;
int y = 5;
int z = 4;

void main () {
    // What happens now?
    if(x < 0)
        SWAP(x, y);
    else
        SWAP(x, z); 
}
