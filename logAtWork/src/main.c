/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:44:16 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/14 09:41:08 by mbougrin         ###   ########.fr       */
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

static void	saveLogActivity(void)
{
	system("pmset -g log | grep -e 'Display is turned off' | tail -n 1 > tmp/lastoff");
	system("pmset -g log | grep -e 'Display is turned on' | tail -n 1 > tmp/laston");

}

static void	checkTurn(char *on, char *off)
{
	t_stc 		*stc = singleton(NULL);
	static char		*last;
	char			**spliton;
	char			**splitoff;
	static bool		check;

	if (last != NULL && ft_strcmp(on, last) != 0)
	{
		check = false;
		ft_strdel(&last);
		stc->key = -2;
		checkKey();
		stc->key = 0;
		return ;
	}
	spliton = ft_strsplit(on, ':');
	splitoff = ft_strsplit(off, ':');
	stc->key = -2;
	if (ft_atoi(spliton[0]) < ft_atoi(splitoff[0]) && check == false)
	{
		last = ft_strdup(on);
		check = true;
		checkKey();
	}
	if (ft_atoi(spliton[1]) < ft_atoi(splitoff[1]) && check == false)
	{
		last = ft_strdup(on);
		check = true;
		checkKey();
	}
	if (ft_atoi(spliton[2]) < ft_atoi(splitoff[2]) && check == false)
	{
		last = ft_strdup(on);
		check = true;
		checkKey();
	}
	ft_strstrdel(spliton);
	ft_strstrdel(splitoff);
	stc->key = 0;
}

static int	checkTurnDay(char *on, char *off)
{
	if (ft_strcmp(on, off) == 0)
		return (1);
	return (0);
}

static void checkActivity(void)
{
	char	**on;
	char	**off;
	int		fd;
	char	*line;

	fd = open("tmp/laston", O_RDONLY);
	get_next_line(fd, &line);
	on = ft_strsplit(line, ' ');
	ft_strdel(&line);
	close(fd);
	fd = open("tmp/lastoff", O_RDONLY);
	get_next_line(fd, &line);
	off = ft_strsplit(line, ' ');
	ft_strdel(&line);
	close(fd);
	if (checkTurnDay(on[0], off[0]) == 1)
		checkTurn(on[1], off[1]);
	ft_strstrdel(on);
	ft_strstrdel(off);
}

//main loop program

int			loop(void)
{
	t_stc 	*stc = singleton(NULL);
	int		saveCount = AUTO_SAVE;

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
			saveLogActivity();
			checkActivity();
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
