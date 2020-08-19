/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:14:05 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 17:17:06 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_sto	*infini(void)
{
	t_sto *inf;

	if (!(inf = (t_sto*)ft_memalloc(sizeof(t_sto))))
		errexit("Error! cannot allocate memory");
	if (!(inf->maplst = (t_lst**)ft_memalloc(sizeof(t_lst*))))
		errexit("Error! cannot allocate memory");
	*(inf->maplst) = NULL;
	if (!(inf->mlx = mlx_init()))
		errexit("Error! fail to eatablish mlx connection");
	inf->sw = SCREENWIDTH;
	inf->sh = SCREENHEIGHT;
	if (!(inf->win = mlx_new_window(inf->mlx, inf->sw, inf->sh, "FDF")))
		errexit("Error! cannot create a new window");
	if (!(inf->img = mlx_new_image(inf->mlx, SCREENWIDTH, SCREENHEIGHT)))
		errexit("Error! cannot create a new image");
	inf->img_addr = mlx_get_data_addr(inf->img, &inf->img_bpp,\
			&inf->img_sl, &inf->img_edn);
	inf->z_scaler = 1;
	return (inf);
}

int		main(int ac, char **av)
{
	t_sto *inf;

	if (ac != 2)
		errexit("Error! usage : ./fdf <filename>");
	inf = infini();
	inf->filename = av[1];
	readmap(inf, av[1]);
	makeart(inf);
	control(inf);
	mlx_loop(inf->mlx);
	return (0);
}
