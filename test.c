#include "push_swap.h"

void	print_split(char **tab)
{
	int i = 0;
	while (*(tab + i))
	{
		printf("%s ", *(tab + i));
		i++;
	}
	printf("\n");
}

void	test(t_ps *params)
{
	t_dlst	*curr;

	curr = params->a->head;
	while (curr)
	{
		printf("curr - %d, prev - %d, next - %d\n", curr->value, curr->prev ? curr->prev->value : -666, curr->next ? curr->next->value : -666);
		curr = curr->next;
	}
}
