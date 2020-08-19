/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:03:23 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 17:03:33 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(t_sto *inf, t_coord *coord)
{
	int		ytmp;
	int		xtmp;
	double	radian;

	if (inf->projindex == 0)
		radian = 0.523599;
	else
		radian = 0.46373398;
	ytmp = coord->y;
	xtmp = coord->x;
	coord->x = (xtmp - ytmp) * cos(radian);
	coord->y = -(coord->z) + (xtmp + ytmp) * sin(radian);
}

t_coord		*proj_algo(t_sto *inf, t_coord *coord)
{
	coord->y *= inf->zoom;
	coord->x *= inf->zoom;
	coord->z = coord->z * inf->zoom / inf->z_scaler;
	coord->y -= inf->mh * inf->zoom / 2;
	coord->x -= inf->mw * inf->zoom / 2;
	rotator(inf, coord);
	if (inf->projindex != 2)
		iso(inf, coord);
	coord->y += inf->campos_y + SCREENHEIGHT / 2 + (inf->mh * inf->zoom / 2);
	coord->x += inf->campos_x + SCREENWIDTH / 2;
	return (coord);
}

void		proj(t_sto *inf, t_coord *h, t_coord *t)
{
	h = proj_algo(inf, h);
	t = proj_algo(inf, t);
	putline(inf, h, t);
	free(h);
	free(t);
}
