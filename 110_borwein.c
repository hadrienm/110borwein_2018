/*
** EPITECH PROJECT, 2019
** 110borwein
** File description:
** 110borwein
*/

#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

double fx(double n, double x)
{
    double resultat = 1;
    for (int k = 0; k <= n; k++)
        resultat *= (sin(x / ((2 * k) + 1)) / (x / ((2 * k) + 1)));
    return resultat;
}

void midpoint_res(double n)
{
    double a = 0.0;
    double b = 5000.0;
    double h = b / 10000.0;
    double resultat = 0;
    double i = a;
    for (; i < 10000.0; i++) {
        resultat += fx(n, (i * h) + h / 2);
    }
    resultat *= h;
    printf("Midpoint:\n");
    printf("I%0.0lf = %.10f\n", n, resultat);
    printf("diff = %.10f\n\n", fabs(resultat - M_PI / 2));
}

void trapezoidal_res(double n)
{
    double a = 0.0;
    double b = 5000.0;
    double h = b / 10000.0;
    double resultat = 0;
    double i = a + 1;
    for (; i < 10000.0; i++)
        resultat += fx(n, i * h);
    resultat = ((resultat * 2) + 1 + fx(n, b)) * (b / (2 * 10000.0));
    printf("Trapezoidal:\n");
    printf("I%0.0lf = %.10f\n", n, resultat);
    printf("diff = %.10f\n\n", fabs(resultat - M_PI / 2));
}

void simpson_res(double n)
{
    double a = 0.0;
    double b = 5000.0;
    double h = b / 10000.0;
    double resultat1 = 0;
    double resultat2 = 0;
    double resultat3 = 0;
    double i = a + 1;
    for (; i < 10000.0; i++)
        resultat1 += fx(n, i * h);
    for (i = 0; i < 10000.0; i++)
        resultat2 += fx(n, (i * h) + (h / 2));
    resultat3 = ((resultat1 * 2) + (resultat2 * 4) + 1 + fx(n, b)) * ((b - a) / (6 * 10000.0));
    printf("Simpson:\n");
    printf("I%0.0lf = %.10f\n", n, resultat3);
    printf("diff = %.10f\n", fabs(resultat3 - M_PI / 2));
}

int h_verified(void)
{
    printf("USAGE\n    ./110borwein n\n\nDESCRIPTION\n    n   constant defining the integral to be compute\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (ac == 2 && strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return h_verified();
    for (size_t i = 0; i < strlen(av[1]); ++i) {
        if (av[1][i] < 48 || av[1][i] > 57)
            return 84;
    }
    double n = atof(av[1]);
    midpoint_res(n);
    trapezoidal_res(n);
    simpson_res(n);
    return (0);
}
