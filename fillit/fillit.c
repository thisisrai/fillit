/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:46 by pstringe          #+#    #+#             */
/*   Updated: 2017/12/28 15:01:17 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		has_valid_number_of_connections(char *tetromino)
{
	if(!tetromino)
	{
		return (0);
	}
	return(1);
}

static int		has_valid_number_of_monominos(char *tetromino)
{
	if(!tetromino)
	{
		return (0);
	}	
	return (1);
}

static int		is_valid_tetromino (char *tetromino)
{
	if(!tetromino)
	{
		return (0);
	}
	if(has_valid_number_of_monominos(tetromino) && has_valid_number_of_connections(tetromino))
	{
		return (1);
	}
	return (0);
}

char	**validate_tetrominos(char **tetrominos)
{
	int i;

	i = 0;
	while (*(tetrominos + i))
	{
		if(!is_valid_tetromino(tetrominos[i]))
		{
			ft_two_d_free((void **)tetrominos);
		}
        i++;
	}
	return (tetrominos);
}

int		main(int argc, char **argv)
{
	char 	*unvalidated_tetromino_set;
	char	*valid_tetromino_set;
	char	**tetrominos;

	if(argc != 2)
	{
		return (error(-6));
	}
	unvalidated_tetromino_set = read_tetromino_set(argv[1]);
	valid_tetromino_set = validate_tetromino_set(unvalidated_tetromino_set);
	if(!valid_tetromino_set)
	{
		return(error(-5));
	}
	tetrominos = get_individual_tetrominos(valid_tetromino_set);
	/*validate the tetrominos according to number of omminos and connections*/
	tetrominos = validate_tetrominos(tetrominos);
	if(!tetrominos)
	{
		return(error(-8));
	}
	ft_putendl("It works");	
	return (0);
}
