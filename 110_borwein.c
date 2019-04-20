/*
** EPITECH PROJECT, 2019
** 110borwein
** File description:
** 110borwein
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

double fx(double n, double x)
{
    double somme = 1;
    for (int k = 0; k <= n; k++)
        if (x != 0)
            somme *= (sin(x / ((2 * k) + 1)) / (x / ((2 * k) + 1)));
    return somme;
}

void midpoint_res(double n)
{
    double a = 0.0;
    double b = 5000.0;
    double h = (b - a) / 10000.0;
    double somme = 0;
    double i = a;
    for (; i < 10000.0; i++)
        somme += fx(n, a + i * h);
    somme *= (b - a) / 10000.0;
    printf("Midpoint:\n");
    printf("I%0.0lf: %.10f\n", n, somme);
    printf("diff: %.10f\n\n", somme - M_PI / 2);
}

void trapezoidal_res(double n)
{
    double a = 0.0;
    double b = 5000.0;
    double h = (b - a) / 10000.0;
    double somme = 0;
    double i = a + 1;
    for (; i < 10000.0; i++)
        somme += fx(n, a + i * h);
    somme = ((somme * 2) + fx(n, a) + fx(n, b)) * ((b - a) / (2 * 10000.0));
    printf("Trapezoidal:\n");
    printf("I%0.0lf: %.10f\n", n, somme);
    printf("diff: %.10f\n\n", fabs(somme - M_PI / 2));
}

void simpson_res(double n)
{
    double a = 0.0;
    double b = 5000.0;
    double h = (b - a) / 10000.0;
    double somme1 = 0;
    double somme2 = 0;
    double somme3 = 0;
    double i = a + 1;
    for (; i < 10000.0; i++)
        somme1 += fx(n, a + i * h);
    for (i = 0; i < 10000.0; i++)
        somme2 += fx(n, (a + i * h) + (h / 2));
    somme3 = ((somme1 * 2) + (somme2 * 4) + fx(n, a) + fx(n, b)) * ((b - a) / (6 * 10000.0));
    printf("Simpson:\n");
    printf("I%0.0lf: %.10f\n", n, somme3);
    printf("diff: %.10f\n", fabs(somme3 - M_PI / 2));
}

int h_verified(void)
{
    printf("USAGE\n    ./110borwein n\n\nDESCRIPTION\n    n   constant defining the integral to be compute\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    if (ac == 2 && strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return h_verified();
    for (size_t i = 0; i < strlen(av[1]); ++i) {
        if (av[1][i] < 48 || av[1][i] > 57)
            return 84;
    }
    double n = atof(av[1]);
    midpoint(n);
    trapezoidal(n);
    simpson(n);
    return (0);
}
