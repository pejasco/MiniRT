/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:43:09 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/01 14:33:39 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include "../inc/minirt.h"

/*
The string "-1.23e42" represents a floating-point number in 
scientific notation.
It means -1.23 multiplied by 10 to the power of 42.
-1.230000000000000e+42
-123000000000000000000000000000000000000000000


If you wanted to represent -1.23 times 
ten to the power of -4, it would be written as "-1.23e-4"
-1.230000000000000e-04
-0.000123
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void process_fraction_part(const char **str, t_atof_vars *vars) 
{
    (*str)++;
    while (ft_isdigit(**str)) 
    {
        double digit = (**str - '0') * vars->fraction;
        if (vars->result > DBL_MAX - digit) 
        {
            printf("Overflow: Number too large\n");
            vars->result = DBL_MAX;
            return;
        }
        vars->result += digit;
        vars->fraction *= 0.1;
        (*str)++;
    }
}

void process_exponent_part(const char **str, t_atof_vars *vars)
{
    (*str)++;
    if (**str == '-')
    {
        vars->exponent_sign = -1;
        (*str)++;
    }
    else if (**str == '+')
        (*str)++;
    while (ft_isdigit(**str))
    {
        if (vars->exponent > INT_MAX / 10)
        {
            printf("Overflow: Exponent too large\n");
            vars->result = DBL_MAX;
            return;
        }
        vars->exponent = vars->exponent * 10 + (**str - '0');
        (*str)++;
    }
}

void sign_mgt(const char **str, t_atof_vars *vars)
{
    while ((**str >= '\t' && **str <= '\r') || **str == ' ')
        (*str)++;
    if (**str == '-')
    {
        vars->sign = -1.0;
        (*str)++;
    }
    else if (**str == '+')
        (*str)++;
}

double ft_atof(const char *str)
{
    t_atof_vars vars;

    vars.result = 0.0;
    vars.exponent = 0;
    vars.sign = 1.0;
    vars.exponent_sign = 1;
    vars.fraction = 0.1;

    sign_mgt(&str, &vars);
    while (ft_isdigit(*str))
    {
        vars.result = vars.result * 10.0 +(*str - '0');
        str++;
    }
    if (*str == '.')
        process_fraction_part(&str, &vars);
    if (*str == 'e' || *str == 'E')
        process_exponent_part(&str, &vars);
    vars.result *= pow(10.0, vars.exponent_sign * vars.exponent);
    return (vars.sign * vars.result);
}

/*
int main(void)
{
    double  atof_res;
    double  ft_atof_res;
    
    //const char *arry = "-1.23e42    342342341";
    const char *arry = "-1.23e42";
    ft_atof_res = ft_atof(arry);
    atof_res = atof(arry);

    printf("ft_atof:: Result: %f\n", ft_atof_res);
    printf("atof:: Result   : %f\n", atof_res);
    return (0);
}
*/