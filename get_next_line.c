/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:18:26 by anareval          #+#    #+#             */
/*   Updated: 2025/02/18 17:55:20 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlnend(const char *str);
static char	*bufferjoin(int fd, char *str, char *bff);
static void	*ft_free(char **str);
static char	*ft_cutline(char *str);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*bff;
	char		*line;
	char		*temp;
	int			lnlen;

	bff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!bff)
		return (ft_free(&bff));
	str = bufferjoin(fd, str, bff);
	free(bff);
	if (str == 0)
		return (NULL);
	line = ft_cutline(str);
	lnlen = ft_strlnend(str);
	temp = ft_substr(str, lnlen + 1, (ft_strlen(str) - lnlen));
	free(str);
	str = temp;
	return (line);
}

char	*ft_cutline(char *str)
{
	char	*line;

	line = ft_strdup(str);
	if (!line)
		return (ft_free(&line));
	line[ft_strlnend(str) + 1] = '\0';
	return (line);
}

char	*bufferjoin(int fd, char *str, char *bff)
{
	int		bffrd;
	char	*temp;

	bffrd = 1;
	while (bffrd > 0)
	{
		bffrd = read(fd, bff, BUFFER_SIZE);
		if (bffrd == -1)
			return (ft_free(&str));
		if (bffrd == 0)
		{
			free(str);
			return (0);
		}
		bff[bffrd] = '\0';
		if (!str)
			temp = ft_strdup("");
		else
			temp = str;
		str = ft_strjoin(temp, bff);
		free(temp);
		if (ft_strchr(bff, '\n'))
			break ;
	}
	return (str);
}

int	ft_strlnend(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

void	*ft_free(char **str)
{
	free(str);
	*str = NULL;
	return (NULL);
}
