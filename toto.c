#include "libft.h"
#include "list.h"
#include <stdio.h>
int main()
{
	t_lx malist = {&malist, &malist};
	t_lx *iter = &malist;
	t_lx new[10];

	int i = -1;
	while (++i < 10)
		list_add(&new[i], &malist);
	i = 0;
	iter = malist.next;
	DG();
	while (iter != &malist && ++i)
	{
		DG("%p & %p & %p", iter, &new, &malist);
		iter = iter->next;
	}
	container_of(iter);
	printf("end at %d\n", i);
	list_del(&new[5]);
	i = 0;
	iter = malist.next;
	DG();
	while (iter != &malist && ++i)
	{
		DG("%p & %p & %p", iter, &new, &malist);
		iter = iter->next;
	}
	printf("end at %d\n", i);
	return (0);
}
