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
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

void	verify_map(char *buffer, t_game *game)
{
	int	x;

	x = ft_strlen(buffer);
	if (game->invalid_character)
	{
		ft_printf("Error\nInvalid character");
		exit(1);
	}
	game->map_area = x - game->map_height;
	if (buffer[--x] != '\n')
		game->map_height++;
	if (game->map_area != game->map_width * game->map_height)
	{
		ft_printf("Error!\nThe map does not contain the correct plane figure.\n");
		exit(1);
	}
	check_limit_x(game);
	check_limit_y(game);
}

void	check_characters(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	game->invalid_character = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			game->player++;
		else if (buffer[i] == 'C')
			game->collectibles++;
		else if (buffer[i] == 'E')
			game->exit++;
		else if (buffer[i] == '\n')
			game->map_height++;
		else if (buffer[i] != '0' && buffer[i] != '1')
			game->invalid_character++;
		i++;
	}
	if (game->player != 1 || game->collectibles < 1 || game->exit != 1)
	{
		ft_printf("Error\nThe number of Players,");
		ft_printf(" collectibles, or exits is Incorrect.\n");
		exit(1);
	}
}

char	*ft_join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	verify(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*get_map(int fd)
{
	char	buffer;
	char	*line;
	int		rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
		line = NULL;
	line = malloc(1);
	line[0] = '\0';
	while (!verify(line) && rd_bytes > 0)
	{
		rd_bytes = read(fd, &buffer, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			free(line);
			ft_printf("Error\nEmpty map");
			exit(1);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = ft_join(line, buffer);
	}
	return (line);
}
