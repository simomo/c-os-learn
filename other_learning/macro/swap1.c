#define SWAP(a, b)  { a ^= b; b ^= a; a ^= b; }

int x = 10;
int y = 5;
int z = 4;

void main() {
// What happens now?
    if(x < 0)
        SWAP(x, y);  // <-- this semicolon will cause error
    else
        SWAP(x, z); 
}
