/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-25 08:30:59 by mpazouki          #+#    #+#             */
/*   Updated: 2024-09-25 08:30:59 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

// convert the given character into an integer
int ft_atoi(char *s)
{
	int res;
	res = 0;
	while(*s)
	{
		res = res *10 + *s++ - '0';
	}
	return(res);
}


// check if the given number is a prime or not
int is_prime(int num)
{
	int i;
	i = 2; // always start with 2 cause it is the smallest prime number
	if (num <=1)
		return(0);
	while (i*i <= num)
	{
		if(num % i == 0)
			return(0);
		i++;
	}
	return(1);
}


// to print out the ineger with write function 
//we have to use put_nbr to split the number into integer and the character 
// in case to print it with write one by one character
void put_nbr(int n)
{
	if (n>=10)
		put_nbr(n/10);
	char digit;
	digit = n % 10 + '0'; // +'0' is just to change the int to char for printing
	write(1, &digit, 1);
}


int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int	nbr;
		nbr = ft_atoi(argv[1]); // covert char -> int
		int sum;
		sum = 0;
		while(nbr > 0)
		{
			if (is_prime(nbr))
				sum += nbr; // add all prime number till getting nbr
			nbr--;
		}
		put_nbr(sum);
	}
	if (argc != 2)
		put_nbr(0);  // if it turns no argument or more than 2 it prints 0  
	
	write(1, "\n", 1);
	return (0);

} 

