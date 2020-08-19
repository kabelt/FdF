/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:31:14 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 17:33:12 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	cal_perc(int h, int t, int cur)
{
	double	cdist;
	double	tdist;

	cdist = cur - h;
	tdist = t - h;
	return ((tdist == 0) ? 1.0 : (cdist / tdist));
}

static int		cal_light(int start, int end, double perc)
{
	return ((int)((1 - perc) * start + perc * end));
}

int				shader(t_pl *pl, t_coord *h, t_coord *t)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	if (pl->curcolor == t->color)
		return (pl->curcolor);
	if (pl->dx > pl->dy)
		perc = cal_perc(h->x, t->x, pl->curx);
	else
		perc = cal_perc(h->y, t->y, pl->cury);
	r = cal_light((h->color >> 16) & 0xFF, (t->color >> 16) & 0xFF, perc);
	g = cal_light((h->color >> 8) & 0xF, (t->color >> 8) & 0xFF, perc);
	b = cal_light(h->color & 0xFF, t->color & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}
