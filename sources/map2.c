/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:52:35 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 16:55:35 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	getzoom(t_sto *inf)
{
	int a;
	int b;

	a = SCREENWIDTH / inf->mw;
	b = SCREENHEIGHT / inf->mh;
	if (a > 2 || b > 2)
	{
		a /= 2;
		b /= 2;
	}
	if (a < b)
		inf->zoom = a;
	else
		inf->zoom = b;
}

int		get_ne(const char *s, char c)
{
	int	now;

	now = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			now++;
		while (*s && *s != c)
			s++;
	}
	return (now);
}

void	lsttoarr_transfer(t_sto *inf)
{
	t_lst	*tmp;
	t_lst	*tbf;
	int		x;
	int		i;
	int		arrsize;

	tmp = *(inf->maplst);
	i = 0;
	arrsize = inf->mh * inf->mw;
	while (i < arrsize)
	{
		x = 0;
		while (x < inf->mw)
		{
			inf->zarr[i] = tmp->coord[x].z;
			inf->colorarr[i++] = tmp->coord[x++].color;
		}
		tbf = tmp;
		tmp = tmp->next;
		free(tbf->coord);
		free(tbf);
	}
	free(inf->maplst);
}

void	lsttoarr(t_sto *inf)
{
	if (!(inf->colorarr = (int*)ft_memalloc(sizeof(int) * inf->mw * inf->mh)))
		errexit("Error! cannot allocate memory");
	if (!(inf->zarr = (int*)ft_memalloc(sizeof(int) * inf->mw * inf->mh)))
		errexit("Error! cannot allocate memory");
	lsttoarr_transfer(inf);
}
