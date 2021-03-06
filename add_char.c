/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:41:08 by ehande            #+#    #+#             */
/*   Updated: 2021/04/15 21:13:15 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

static int len(char *str)
{
    int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int add_l_char(char **line, char ch)
{
    int i;
    char *out;
    char *tmp;

    tmp = *line;
    i = len(tmp);
    i += 1;
    if(!(out = malloc(sizeof(char) * (i + 1))))
        return (0);
    out[i] = '\0';
    out[--i] = ch;
    while (i--)
        out[i] = tmp[i];
    free(*line);
    *line = out;
    return (1);
}

int add_f_char(char **line, char ch)
{
    int i;
    char *out;
    char *tmp;

    tmp = *line;
    i = len(tmp);
    i ++;
    if(!(out = malloc(sizeof(char) * (i + 1))))
        return (0);
    out[i] = '\0';
    --i;
    while (i--)
        out[i + 1] = tmp[i];
    out[0] = ch;
    free(*line);
    *line = out;
    return (1);
}