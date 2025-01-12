#ifndef FRACTOL_H
# define FRACTOL_H

// 2. Nova Fractal

// mandelbrot set equation
// z(n + 1) = z(n)^2 + c
// z[0] = 0
// c init val: pixel coordinates x / zoom, y / zoom


typedef struct s_fractal
{
    int x;
    int y;
    /* z: complex num
    z = zx + i * zy  */
    double zx;
    double zy;
    /* c: complex num
    c = cx + i * cy  */
    double cx;
    double cy;
} t_fractal;

#endif
