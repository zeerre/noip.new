#include <iostream> 

using namespace std; 

int main() 
{ 
unsigned short x, y;
cin >> x >> y;
x = (x | x << 2) & 0x33; 
x = (x | x << 1) & 0x55; 
y = (y | y << 2) & 0x33; 
y = (y | y << 1) & 0x55; 
unsigned short z = x | y << 1; 
cout << z << endl;
return 0;
}