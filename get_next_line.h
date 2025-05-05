/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:18:40 by anareval          #+#    #+#             */
/*   Updated: 2025/05/05 16:50:36 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

// Reads a full line from a file descriptor.
char	*get_next_line(int fd);

// Duplicates a string by allocating new memory.
char	*ft_strdup(const char *str);

// Calculates the length of a string.
int		ft_strlen(const char *str);

// Finds the first occurrence of a character in a string.
char	*ft_strchr(const char *str, int c);

// Extracts a substring from a given position and length.
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Joins two strings into a new one.
char	*ft_strjoin(const char *s1, const char *s2);

#endif
