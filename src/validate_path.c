/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarside <jgarside@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:28:56 by jgarside          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:06 by jgarside         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"
#include "../printf/ft_printf.h"

void	validate_path(int y, int x, t_game *game)
{
	if (game->map[y][x] == 'E')
		game->exit_path++;
	if (y < 0 || y >= game->map_height || x < 0 || x >= game->map_width
		|| game->map[y][x] == '1' || game->map[y][x] == 'E')
		return ;
	if (game->map[y][x] == 'C')
		game->collectible_path++;
	game->map[y][x] = '1';
	validate_path(y, (x - 1), game);
	validate_path(y, (x + 1), game);
	validate_path((y - 1), x, game);
	validate_path((y + 1), x, game);
	return ;
}

void	check_path(t_game *game)
{
	game->y = 0;
	while ((game->y) < (game->map_height))
	{
		game->x = 0;
		while ((game->x) < (game->map_width))
		{
			if (game->map[game->y][game->x] == 'P')
			{
				validate_path(game->y, game->x, game);
				if (game->collectibles == game->collectible_path
					&& game->exit_path)
				{
					game->x = 0;
					game->y = 0;
				}
				else
				{
					ft_printf("Error\nNo valid path available");
					exit(1);
				}
			}
			game->x++;
		}
		game->y++;
	}
}
