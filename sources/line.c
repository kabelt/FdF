/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:56:38 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/24 10:46:41 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpix_bold_helper(t_sto *inf, int color, int i)
{
	if (i < SCREENWIDTH * SCREENHEIGHT)
		((int*)(inf->img_addr))[i++] = color;
	if (i < SCREENWIDTH * SCREENHEIGHT)
		((int*)(inf->img_addr))[i++] = color;
	if (i < SCREENWIDTH * SCREENHEIGHT)
		((int*)(inf->img_addr))[i] = color;
}

void	putpix_bold(t_sto *inf, int y, int x, int color)
{
	int i;

	y -= 1;
	i = SCREENWIDTH * y + x;
	if (y >= 0 && y < SCREENHEIGHT && x >= 0 && x < SCREENWIDTH)
		putpix_bold_helper(inf, color, i);
	y++;
	i = SCREENWIDTH * y + x;
	if (y >= 0 && y < SCREENHEIGHT && x >= 0 && x < SCREENWIDTH)
		putpix_bold_helper(inf, color, i);
	y++;
	i = SCREENWIDTH * y + x;
	if (y >= 0 && y < SCREENHEIGHT && x >= 0 && x < SCREENWIDTH)
		putpix_bold_helper(inf, color, i);
}

void	putpix(t_sto *inf, int y, int x, int color)
{
	int i;

	i = SCREENWIDTH * y + x;
	if (y >= 0 && y < SCREENHEIGHT && x >= 0 && x < SCREENWIDTH)
		((int*)(inf->img_addr))[i] = color;
}

void	putline2(t_sto *inf, t_pl *pl, t_coord *h, t_coord *t)
{
	pl->curx = h->x;
	pl->cury = h->y;
	pl->curcolor = h->color;
	while (1)
	{
		if (inf->boldmodeindex)
			putpix_bold(inf, pl->cury, pl->curx, shader(pl, h, t));
		else
			putpix(inf, pl->cury, pl->curx, shader(pl, h, t));
		if (pl->curx == t->x && pl->cury == t->y)
			break ;
		pl->e2 = 2 * pl->err;
		if (pl->e2 >= pl->dy)
		{
			pl->err += pl->dy;
			pl->curx += pl->sx;
		}
		if (pl->e2 <= pl->dx)
		{
			pl->err += pl->dx;
			pl->cury += pl->sy;
		}
	}
	free(pl);
}

void	putline(t_sto *inf, t_coord *h, t_coord *t)
{
	t_pl *pl;

	pl = (t_pl*)ft_memalloc(sizeof(t_pl));
	if ((pl->dx = t->x - h->x) < 0)
		pl->dx *= -1;
	pl->sx = h->x < t->x ? 1 : -1;
	if ((pl->dy = t->y - h->y) > 0)
		pl->dy *= -1;
	pl->sy = h->y < t->y ? 1 : -1;
	pl->err = pl->dx + pl->dy;
	putline2(inf, pl, h, t);
}
