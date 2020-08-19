/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:19:37 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/23 13:11:29 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*tocoord(t_sto *inf, int y, int x)
{
	t_coord *tmp;

	tmp = (t_coord*)ft_memalloc(sizeof(t_coord));
	tmp->y = y;
	tmp->x = x;
	tmp->z = inf->zarr[y * inf->mw + x];
	if (inf->zrange == 0)
	{
		if (inf->colorthemeindex == 0)
			tmp->color = 0x1d2671;
		else if (inf->colorthemeindex == 1)
			tmp->color = 0x3c101b;
		else
			tmp->color = 0x44443b;
	}
	else
		tmp->color = inf->colorarr[y * inf->mw + x] == -1 ?\
			getstdcolor(inf, y, x) : inf->colorarr[y * inf->mw + x];
	return (tmp);
}

void	clearscreen(t_sto *inf)
{
	int *image;
	int i;

	i = 0;
	if (inf->vgmodeindex)
		return ;
	image = (int*)inf->img_addr;
	while (i < SCREENHEIGHT * SCREENWIDTH)
	{
		image[i] = 0x000000;
		i++;
	}
}

void	makeart(t_sto *inf)
{
	int y;
	int x;

	clearscreen(inf);
	y = 0;
	while (y < inf->mh)
	{
		x = 0;
		while (x < inf->mw)
		{
			if (x < inf->mw - 1)
				proj(inf, tocoord(inf, y, x), tocoord(inf, y, x + 1));
			if (y < inf->mh - 1)
				proj(inf, tocoord(inf, y, x), tocoord(inf, y + 1, x));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
	putmenu(inf);
	putmenu2(inf);
}
