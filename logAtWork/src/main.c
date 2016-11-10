/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:44:16 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/10 01:05:52 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

//singleton struct stc pattern design

t_stc		*singleton(t_stc *stc)
{
	static t_stc *singleton;

	if (stc != NULL)
		singleton = stc;
	else
		return (singleton);
	return (NULL);
}

// print all information into ncurse

static void	print(void)
{
	printDate();
	printTime();
	printWorkTime();
	printBreakTime();
	printWeekTime();
	printMonthTime();
	printThreeMonthTime();
	printAllTime();
	printWorkBreak();
}

// check next day passed and restart program

static int	checkDate(void)
{
	t_stc 		*stc = singleton(NULL);
	time_t		timestamp;
	struct tm	*t;

	timestamp = time(NULL);
	t = localtime(&timestamp);
	if (stc->dateNumber != t->tm_mday)
		return (-1);
	return (0);
}

//main loop program

int			loop(void)
{
	t_stc 	*stc = singleton(NULL);
	int		saveCount = 60;

	stc->currentTime = time(NULL);
	bkgd(COLOR_PAIR(1));
	wrefresh(stdscr);
	while (stc->key != 27)
	{
		stc->key = getch();
		stc->currentTime = time(NULL);
		stc->clock = clock();
		checkKey();
		print();
		refreshWindow();
		if (stc->clock / CLOCKS_PER_SEC == saveCount)
		{
			save();
			saveCount += AUTO_SAVE;
		}
		if (checkDate() == -1)
			return (-1);
	}
	return (27);
}

int			main(void)
{
	while (1)
	{
		initNcurse();
		initColor();
		initMainWindow();
		if (loop() == 27)
		{
			deleteMainWindow();
			endwin();
			break ;
		}
		deleteMainWindow();
		endwin();
	}
	return (0);
}
