#include "push_swap.h"

void	sort_three(t_stacks	*stacks)
{
	if (stacks->size_a == 2) //2_1_3
	{
		if (stacks->a[0] > stacks->a[1])
			sa(stacks);
		return;
	}
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] > stacks->a[2]) //3_2_1
	{
		sa(stacks);
		rra(stacks);
		return;
	}
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] < stacks->a[2] && stacks->a[0] > stacks->a[2]) //3_1_2
	{
		ra(stacks);
		return;
	}
	else if (stacks->a[0] < stacks->a[1] && stacks->a[1] > stacks->a[2] && stacks->a[0] < stacks->a[2]) //1_3_2
	{
		sa(stacks);
		ra(stacks);
	}
	else if(stacks->a[0] < stacks->a[1] && stacks->a[0] > stacks->a[2] && stacks->a[1] < stacks->a[2]) //2_3_1
	{
		rra(stacks);
	}
}
