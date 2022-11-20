
/***************************************************************/
/**                                                           **/
/**  Fernando F. Miqueletti Número USP:12544340               **/
/**   Exercício-Programa 2                                    **/
/**   Professor:Yoshiharu Kohayakawa                          **/
/**   Turma: 3                                                **/
/**                                                           **/
/***************************************************************/



#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define G 6.67e-11

double dist(double p1x, double p1y, double p2x, double p2y);
double forca(char c, int i, double x0, double y0, double m0, double x1, double y1, double m1, double x2, double y2, double m2);
double sen(double x1, double y1, double x2, double y2);
double coss(double x1, double y1, double x2, double y2);
double forca1(char c, int i, double xa, double ya, double ma, double xb, double yb, double mb);
void atualize(double *x, double *y, double *vx, double *vy, double ax, double ay, double dt);


int main(int argc, char *argv[])
{
    char x = 'x';
    char y = 'y';
    double r0x = atof(argv[1]), r0y = atof(argv[2]), v0x = atof(argv[3]), v0y = atof(argv[4]), m0 = atof(argv[5]);
    double r1x = atof(argv[6]), r1y = atof(argv[7]), v1x = atof(argv[8]), v1y = atof(argv[9]), m1 = atof(argv[10]);
    double r2x = atof(argv[11]), r2y = atof(argv[12]), v2x = atof(argv[13]), v2y = atof(argv[14]), m2 = atof(argv[15]);
    double a0x, a0y, a1x, a1y, a2x, a2y;
    double T = atof(argv[16]), deltat = atof(argv[17]);
    while (T >= 0) {
        a0x = forca( x, 0, r0x, r0y, m0, r1x, r1y, m1, r2x, r2y, m2 ) / m0;
        a0y = forca( y, 0, r0x, r0y, m0, r1x, r1y, m1, r2x, r2y, m2 ) / m0;
        a1x = forca( x, 1, r1x, r1y, m1, r0x, r0y, m0, r2x, r2y, m2 ) / m1;
        a1y = forca( y, 1, r1x, r1y, m1, r0x, r0y, m0, r2x, r2y, m2 ) / m1;
        a2x = forca( x, 2, r2x, r2y, m2, r0x, r0y, m0, r1x, r1y, m1 ) / m2;
        a2y = forca( y, 2, r2x, r2y, m2, r0x, r0y, m0, r1x, r1y, m1 ) / m2;

        printf( "%g %g %g %g %g %g\n" , r0x, r0y, r1x, r1y, r2x, r2y);
        atualize( &r0x, &r0y, &v0x, &v0y, a0x, a0y, deltat);
        atualize( &r1x, &r1y, &v1x, &v1y, a1x, a1y, deltat);
        atualize( &r2x, &r2y, &v2x, &v2y, a2x, a2y, deltat);

        T = T - deltat;
    }
    return 0;

}

double dist(double p1x, double p1y, double p2x, double p2y)
{
    double d, dpx, dpy;
    dpy = p2y - p1y;
    dpx= p2x - p1x;
    d = sqrt((dpy * dpy) + (dpx * dpx));
    return d;
}

double forca(char c, int i, double x0, double y0, double m0, double x1, double y1, double m1, double x2, double y2, double m2)
{
    double forcar;
    forcar = forca1( c, i, x0, y0, m0, x1, y1, m1 ) + forca1( c, i, x0, y0, m0, x2, y2, m2);
    return forcar;
}

 double forca1(char c, int i, double xa, double ya, double ma, double xb, double yb, double mb)
{

    double f, d, dd;
    d = dist( xa, ya, xb, yb);
    dd = d * d;
    f = (G * (ma * mb))/ dd;
    if (c == 'y') {
            f = f * sen(xa, ya, xb, yb);
            return f;
    }
    if (c == 'x'){
            f = f * coss(xa, ya, xb, yb);
            return f;
    }
    return 0;
}


double sen(double xi, double yi, double xf, double yf)
{
    double sen;
    sen = (yf - yi) / dist(xi, yi, xf, yf);
    return sen;
}
double coss(double xi, double yi, double xf, double yf)
{
    double coss;
    coss = (xf - xi) / (dist(xi, yi, xf, yf));
    return coss;
}

void atualize(double *x, double *y, double *vx, double *vy, double ax, double ay, double dt)
{
    *vx = (*vx) + (dt * ax);
    *vy = (*vy) + (dt * ay);
    *x = (*x) + ((*vx) * dt);
    *y = (*y) + ((*vy) * dt);

}
