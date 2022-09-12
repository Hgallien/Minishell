#include "execution.h"

void	save_fd(int *save, int *fd)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		if (fd[i] >= 0)
		{
			save[i] = dup(i);
			dup2(fd[i], i);
		}
		i++;
	}
}

void	restore_fd(int *save, int *fd)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		if (fd[i] >= 0)
		{
			dup2(save[i], i);
			close(fd[i]);
		}
		i++;
	}
}
