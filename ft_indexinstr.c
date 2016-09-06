int	ft_indexinstr(char index, char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == index)
			return (1);
	
	}
	return (0);
}
