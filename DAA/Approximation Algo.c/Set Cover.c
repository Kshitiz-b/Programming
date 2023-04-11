#include <stdio.h>
#include <stdbool.h>

#define MAX_SETS 1000
#define MAX_ELEMENTS 1000

int set[MAX_SETS][MAX_ELEMENTS]; // set array to store the sets
bool covered[MAX_ELEMENTS];      // to keep track of covered elements

// function to find the greedy approximate solution for the set cover problem
void set_cover(int num_sets, int num_elements)
{
    int i, j, max, max_index;
    int selected_sets[MAX_SETS];
    int num_selected_sets = 0;
    for (i = 0; i < num_elements; i++)
    {
        covered[i] = false;
    }
    while (num_selected_sets < num_sets)
    {
        max = -1;
        // find the set that covers the maximum number of uncovered elements
        for (i = 0; i < num_sets; i++)
        {
            if (selected_sets[i])
            {
                continue;
            }
            int count = 0;
            for (j = 0; j < num_elements; j++)
            {
                if (set[i][j] && !covered[j])
                {
                    count++;
                }
            }
            if (count > max)
            {
                max = count;
                max_index = i;
            }
        }
        // add the selected set to the solution and mark its elements as covered
        selected_sets[max_index] = 1;
        num_selected_sets++;
        for (j = 0; j < num_elements; j++)
        {
            if (set[max_index][j])
            {
                covered[j] = true;
            }
        }
    }
    // print the selected sets
    printf("Selected sets: ");
    for (i = 0; i < num_sets; i++)
    {
        if (selected_sets[i])
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int num_sets, num_elements, i, j, num_elements_in_set;
    printf("Enter the number of sets and elements: ");
    scanf("%d%d", &num_sets, &num_elements);
    for (i = 0; i < num_sets; i++)
    {
        printf("Enter the number of elements in set %d: ", i);
        scanf("%d", &num_elements_in_set);
        printf("Enter the elements in set %d: ", i);
        for (j = 0; j < num_elements_in_set; j++)
        {
            int element;
            scanf("%d", &element);
            set[i][element] = 1;
        }
    }
    set_cover(num_sets, num_elements);
    return 0;
}
