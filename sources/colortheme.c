/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colortheme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:03:45 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 17:07:39 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		theme0(t_sto *inf, int y, int x)
{
	double perc;

	perc = inf->zarr[y * inf->mw + x] - inf->zmin / inf->zrange;
	if (perc < 0.1)
		return (0x1d2671);
	else if (perc < 0.2)
		return (0x2f276f);
	else if (perc < 0.3)
		return (0x41296e);
	else if (perc < 0.4)
		return (0x542B6c);
	else if (perc < 0.5)
		return (0x662d6b);
	else if (perc < 0.6)
		return (0x792f69);
	else if (perc < 0.7)
		return (0x8b3168);
	else if (perc < 0.8)
		return (0x9e3366);
	else if (perc < 0.9)
		return (0xb03565);
	else
		return (0xc33764);
}

static int		theme1(t_sto *inf, int y, int x)
{
	double perc;

	perc = inf->zarr[y * inf->mw + x] - inf->zmin / inf->zrange;
	if (perc < 0.2)
		return (0x3c101b);
	else if (perc < 0.3)
		return (0x651b2c);
	else if (perc < 0.4)
		return (0x8d263e);
	else if (perc < 0.5)
		return (0xb53050);
	else if (perc < 0.6)
		return (0xcf4a69);
	else if (perc < 0.7)
		return (0xd9728b);
	else if (perc < 0.8)
		return (0xe49aac);
	else
		return (0xefc3cd);
}

static int		theme2(t_sto *inf, int y, int x)
{
	double perc;

	perc = inf->zarr[y * inf->mw + x] - inf->zmin / inf->zrange;
	if (perc < 0.2)
		return (0x44443b);
	else if (perc < 0.3)
		return (0x606053);
	else if (perc < 0.4)
		return (0x7b7b6b);
	else if (perc < 0.5)
		return (0x949484);
	else if (perc < 0.6)
		return (0xacac9f);
	else if (perc < 0.8)
		return (0xc4c4bb);
	else
		return (0xdbdbd6);
}

int				getstdcolor(t_sto *inf, int y, int x)
{
	if (inf->colorthemeindex == 0)
		return (theme0(inf, y, x));
	else if (inf->colorthemeindex == 1)
		return (theme1(inf, y, x));
	else
		return (theme2(inf, y, x));
}
