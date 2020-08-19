/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:41:25 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/22 16:52:24 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setzrange(t_sto *inf, int cz)
{
	if (inf->zmin == 0)
		inf->zmin = cz;
	else if (cz < inf->zmin)
		inf->zmin = cz;
	if (inf->zmax == 0)
		inf->zmax = cz;
	else if (inf->zmax < cz)
		inf->zmax = cz;
	inf->zrange = inf->zmax - inf->zmin;
}

void	setmapwidth(t_sto *inf, int ne)
{
	if (inf->mw == 0)
		inf->mw = ne;
	else if (ne != inf->mw)
		errexit("Error! Invalid map");
}

void	readline_check_cordval(char **tmp2)
{
	if (ft_isnumber_base(tmp2[0], 10) == 0)
		errexit("Error! Invalid map");
	if (tmp2[1] && ft_isnumber_base(tmp2[1], 16) == 0)
		errexit("Error! Invalid map");
}

void	readline(t_sto *inf, char *line)
{
	t_coord	*el;
	int		i;
	int		ne;
	char	**tmp;
	char	**tmp2;

	i = 0;
	ne = get_ne(line, ' ');
	setmapwidth(inf, ne);
	el = (t_coord*)ft_memalloc(sizeof(t_coord) * ne);
	tmp = ft_strsplit(line, ' ');
	while (i < ne)
	{
		tmp2 = ft_strsplit(tmp[i], ',');
		readline_check_cordval(tmp2);
		el[i].z = ft_atoi(tmp2[0]);
		setzrange(inf, el[i].z);
		el[i].color = tmp2[1] ? ft_atoi_base(tmp2[1], 16) : NOCOLOR;
		ft_strsplit_free(tmp2);
		i++;
	}
	ft_strsplit_free(tmp);
	lst_add_back(inf->maplst, lstnew(el, ne));
	inf->mh++;
}

void	readmap(t_sto *inf, char *filename)
{
	int		fd;
	char	**line;
	int		gnl_rt;

	line = (char**)ft_memalloc(sizeof(char*));
	if ((fd = open(filename, O_RDONLY)) < 0)
		errexit("Error! cannot open the file");
	while ((gnl_rt = get_next_line(fd, line)) != 0)
	{
		if (gnl_rt == -1)
			errexit("Error! invalid file");
		readline(inf, *line);
		free(*line);
	}
	free(line);
	lsttoarr(inf);
	getzoom(inf);
}
