/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:18:26 by anareval          #+#    #+#             */
/*   Updated: 2025/02/17 17:32:09 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlnend(const char *str);
static char	*bufferjoin(int fd, char *str, char *bff);
static void	*ft_free(char **str);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*bff;
	int			lnend;
	char		*str2;

	bff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!bff)
		return (ft_free(&bff));
	str = bufferjoin(fd, str, bff);
	free(bff);
	lnend = ft_strlnend(str);
	str2 = ft_strdup(str);
	free(str);
	str2[lnend] = '\0';
	return (str2);
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
			break ;
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
	int	i;

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
