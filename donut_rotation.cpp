#include <bits/stdc++.h>
#define PI 3.1415

using namespace std;

const int width = 75, height = 30;

int main() {
    double inner_radius = 0.5;
    double outer_radius = 1;
    double k2 = 4.2;
    double k1 = width * k2 * 3 / (8 * (inner_radius + outer_radius));
    double rx = 0;
    double rz = 0;
    double i = 0;
    double j = 0;
    double zb[height * width + height];
    double cx, cy, x, y, z;
    char b[height * width + height];
    while(true) {
        cout << "\x1b[0;0H";
        for (int i = 0; i < width * height + height; ++i) {
            b[i] = ' ';
            zb[i] = 0;
        }
        for (int i = 0; i < height; ++i) {
            b[i * (width + 1) + width] = '\n';
        }
        for (i = 0; i < 2 * PI; i += PI / 100) {
            for (j = 0; j < 2 * PI; j += PI / 100) {
                cx = outer_radius + inner_radius * cos(i);
                cy = inner_radius * sin(i);
                z = k2 + cos(rx) * cx * sin(j) + cy * sin(rx);
                x = (cx * (cos(rz) * cos(j) + sin(rx) * sin(rz) * sin(j)) - cy * cos(rx) * sin(rz)) / (z * 3);
                y = (cx * (sin(rz) * cos(j) - sin(rx) * cos(rz) * sin(j)) + cy * cos(rx) * cos(rz)) / (z * 3);
                z = 1 / ((z - 1) / (z * 3));
                int x2 = (width / 2 + k1) * z * x / 2 + width / 2;
                int y2 = (height / 2 - k1) * z * y / 2 + height / 2;
                double l = cos(j) * cos(i) * sin(rz) - cos(rx) * cos(i) * sin(j) - sin(rx) * sin(i) + cos(rz) * (cos(rx) * sin(i) - cos(i) * sin(rx) * sin(j));
                if (l > 0){
                    if (x2 < width && x2 >= 0 && y2 < height && y2 >= 0 && z > zb[x2 + y2 * (width + 1)]) {
                        zb[x2 + y2 * (width + 1)] = z;
                        b[x2 + y2 * (width + 1)] = ".,-:=*+*#%@"[(int)(l * 7.3)];
                    }
                }
            }
        }
        cout.write(b, sizeof(b));
        cout.flush();
        rx += 0.05;
        rz += 0.025;
    }
    return 0;
}

