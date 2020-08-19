/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:29:19 by kmaneera          #+#    #+#             */
/*   Updated: 2020/08/19 11:30:30 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	putmenu3(t_sto *inf)
{
	mlx_string_put(inf->mlx, inf->win, 50, 190, MENUCOLOR,\
			"CHANGE PROJECTION       : P");
	mlx_string_put(inf->mlx, inf->win, 50, 210, MENUCOLOR,\
			"CHANGE THEME COLOR      : T");
	mlx_string_put(inf->mlx, inf->win, 50, 230, MENUCOLOR,\
			"ENABLE BOLD MODE        : B");
	mlx_string_put(inf->mlx, inf->win, 50, 250, MENUCOLOR,\
			"ENABLE VAN GOGH MODE    : V");
	mlx_string_put(inf->mlx, inf->win, 50, 270, MENUCOLOR,\
			"ENABLE LEAK DETECTION   : L");
	mlx_string_put(inf->mlx, inf->win, 50, 290, MENUCOLOR,\
			"EXIT                    : ESC");
	mlx_string_put(inf->mlx, inf->win, 0, 1060, 0x808080,\
		inf->filename);
}

void		putmenu2(t_sto *inf)
{
	mlx_string_put(inf->mlx, inf->win, 197, 40, MENUCOLOR, "CONTROLS");
	mlx_string_put(inf->mlx, inf->win, 50, 70, MENUCOLOR,\
			"MOVE                    : ARROWS");
	mlx_string_put(inf->mlx, inf->win, 50, 90, MENUCOLOR,\
			"ZOOM                    : + - (MAIN_PAD)");
	mlx_string_put(inf->mlx, inf->win, 50, 110, MENUCOLOR,\
			"ROTATE AROUND X AXIS    : W S ");
	mlx_string_put(inf->mlx, inf->win, 50, 130, MENUCOLOR,\
			"ROTATE AROUND Y AXIS    : A D ");
	mlx_string_put(inf->mlx, inf->win, 50, 150, MENUCOLOR,\
			"ROTATE AROUND Z AXIS    : Q E ");
	mlx_string_put(inf->mlx, inf->win, 50, 170, MENUCOLOR,\
			"FLATTEN/ROUGHEN         : L.SHIFT/R.SHIFT");
	putmenu3(inf);
}

void		putmenu(t_sto *inf)
{
	if (inf->projindex == 0)
		mlx_string_put(inf->mlx, inf->win, 1630, 40, MENUCOLOR,\
				"TRUE ISOMETRIC PROJECTION");
	else if (inf->projindex == 1)
		mlx_string_put(inf->mlx, inf->win, 1640, 40, MENUCOLOR,\
				"2:1 ISOMETRIC PROJECTION");
	else if (inf->projindex == 2)
		mlx_string_put(inf->mlx, inf->win, 1690, 40, MENUCOLOR,\
				"PARALLEL PROJECTION");
	if (inf->boldmodeindex)
		mlx_string_put(inf->mlx, inf->win, 1791, 975, 0x00FF00, "BOLD");
	else
		mlx_string_put(inf->mlx, inf->win, 1791, 975, MENUCOLOR, "BOLD");
	if (inf->vgmodeindex)
		mlx_string_put(inf->mlx, inf->win, 1750, 1000, 0x00FF00,\
				"VAN GOGH MODE");
	else
		mlx_string_put(inf->mlx, inf->win, 1750, 1000, MENUCOLOR,\
				"VAN GOGH MODE");
	if (inf->clindex)
		mlx_string_put(inf->mlx, inf->win, 1746, 1025, 0x00FF00,\
				"LEAK DETECTION");
	else
		mlx_string_put(inf->mlx, inf->win, 1746, 1025, MENUCOLOR,\
				"LEAK DETECTION");
}
