/*
** EPITECH PROJECT, 2019
** 110borwein
** File description:
** 110borwein
*/

#include "my.h"

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
    gauss_res(n);
    return (0);
}
