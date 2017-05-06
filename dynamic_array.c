#include <stdio.h>
#include <stdlib.h>

struct dynamic_arr_t
{
	int *arr;
	int size;
};

struct dynamic_arr_t generate(int);
void free_dynamic_arr(struct dynamic_arr_t*);
struct dynamic_arr_t filter_even(struct dynamic_arr_t);
struct dynamic_arr_t map_sqr(struct dynamic_arr_t);
//struct dynamic_arr_t sqr_of_odds(struct dynamic_arr_t);

int main()
{
	struct dynamic_arr_t array;
	int i,p=5;
	array=generate(p);
	//array=filter_even(array);
	array=map_sqr(array);
	for(i=0;i<array.size;i++)
	{
		printf("%d\n",*(array.arr+i));
	}
	free_dynamic_arr(&array);
	return 0;
}

struct dynamic_arr_t generate(int num)
{
	struct dynamic_arr_t array;
	int i;
	array.size=num;
	array.arr=malloc(sizeof(int)*array.size);
	for(i=0;i<array.size;i++)
	{
		*(array.arr+i)=i+1;
	}
	return array;
}
void free_dynamic_arr(struct dynamic_arr_t *array)
{
	free(array->arr);
	array->arr=NULL;
}
struct dynamic_arr_t filter_even(struct dynamic_arr_t array)
{
	struct dynamic_arr_t even;
	int i,j=0;
	for(i=0;i<array.size;i++)
	{
		if(*(array.arr+i)%2==0)
		{
			*(even.arr+j)=*(array.arr+i);
			j++;
		}
	}
	even.size=j;
	return even;
}
struct dynamic_arr_t map_sqr(struct dynamic_arr_t array)
{
	int i=0;
	struct dynamic_arr_t sqr;
	for(i=0;i<array.size;i++)
	{
		*(sqr.arr+i)=*(array.arr+i)**(array.arr+i);
	}
	sqr.size=array.size;
	return sqr;
}
/*struct dynamic_arr_t sqr_of_odds(struct dynamic_arr_t array)
{
	struct dynamic_arr_t sqr_odds;
	sqr_odds=filter_even(array);
	
}
*/
