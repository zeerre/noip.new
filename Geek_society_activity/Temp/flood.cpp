#include <bits/stdc++.h> 
using namespace std; 
const int ROWS = 8; 
const int COLS = 8; 
struct Point { 
    int r, c;
    Point(int r, int c) : r(r), c(c) {} 
}; 
bool is_valid(char image[ROWS][COLS], Point pt, 
int prev_color, int new_color) {
    int r = pt.r;
    int c = pt.c;
    return (0 <= r && r < ROWS && 0 <= c && c < COLS && 
    ① && image[r][c] != new_color); 
} 
void flood_fill(char image[ROWS][COLS], Point cur, int new_color) { 
    queue<Point> queue;
    queue.push(cur);
    int prev_color = image[cur.r][cur.c]; 
    ②; 
    while (!queue.empty()) {
        Point pt = queue.front();
        queue.pop();
        Point points[4] = {③, Point(pt.r - 1, pt.c), 
        Point(pt.r, pt.c + 1), Point(pt.r, pt.c - 1)}; 
        for (auto p : points) { 
            if (is_valid(image, p, prev_color, new_color)) {
                ④; 
                ⑤; 
            }
        }
    }
} 
int main() { 
    char image[ROWS][COLS] = {{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'},
    {'g', 'g', 'g', 'g', 'g', 'g', 'r', 'r'},
    {'g', 'r', 'r', 'g', 'g', 'r', 'g', 'g'},
    {'g', 'b', 'b', 'b', 'b', 'r', 'g', 'r'},
    {'g', 'g', 'g', 'b', 'b', 'r', 'g', 'r'},
    {'g', 'g', 'g', 'b', 'b', 'b', 'b', 'r'},
    {'g', 'g', 'g', 'g', 'g', 'b', 'g', 'g'},
    {'g', 'g', 'g', 'g', 'g', 'b', 'b', 'g'}};
    Point cur(4, 4); 
    char new_color = 'y';
    flood_fill(image, cur, new_color);
    for (int r = 0; r < ROWS; r++) { 
        for (int c = 0; c < COLS; c++) { 
            cout << image[r][c] << " ";
        }
        cout << endl;
    }
    // 输出：
    // g g g g g g g g 
    // g g g g g g r r 
    // g r r g g r g g 
    // g y y y y r g r 
    // g g g y y r g r 
    // g g g y y y y r 
    // g g g g g y g g 
    // g g g g g y y g 
    return 0;
}