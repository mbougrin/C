/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:11:25 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/28 18:47:53 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>
# include <stdio.h>
# include <time.h>
# include <sys/socket.h>
# include <sys/wait.h>
# include <resolv.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/select.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/types.h>
# include <dirent.h>

# define PATH			"./log"
# define PING 			"google.fr"
# define SPEEDTEST 		"google.fr"
# define SIZEPACKET 	64
# define NBPACKET 		10
# define TIMEOUT 		1
# define BUF_SIZE		1024

# define FD_FREE		0
# define FD_SERV		1
# define FD_CLIENT		2

typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr		t_sockaddr;
typedef struct icmphdr		t_icmphdr;
typedef struct addrinfo		t_addrinfo;

typedef struct				s_ret
{
	bool					ping;
	bool					log;
}							t_ret;

typedef struct				s_packet
{
	t_icmphdr				hdr;
	char					*msg;
}							t_packet;

typedef struct				s_fd
{
	int						type;
	void					(*fct_read)();
	void					(*fct_write)();
	char					buf_read[BUF_SIZE + 1];
	char					buf_write[BUF_SIZE + 1];
	t_ret					ret;
}							t_fd;


typedef struct				s_sock
{
	fd_set					writefd;
	fd_set					readfd;
	int						sd;
	int						maxsd;
	int						dmax;
	int						r;
	struct sockaddr_in		sin;
	t_fd					*fds;
}							t_sock;

typedef struct				s_av
{
	int						timeout;
	int						port;
	int						size;
	int						nbpacket;
	bool					v;
}							t_av;

typedef struct				s_ping
{
	char					*ipping;
	char					*speedtestip;
	char					*myip;
	double					msmin;
	double					msmoy;
	double					msmax;
	double					allms;
	int						sd;
	int						transmitted;
	int						lost;
	int						allpacket;
}							t_ping;

typedef struct				s_stc
{
	t_av					av;
	t_ping					ping;
	t_addrinfo				hints;
	t_sock					socket;
	char					*name;
	t_addrinfo				*addr;
}							t_stc;

//process.c
void						cpuinfo(int cs);
void						meminfo(int cs);
void						version(int cs);
void						process(int cs);

//socketwrite.c
void						writeping(int cs);

//socket.c
void						mainloop(void);
void						createsocket(void);

//log.c
void						writelog(char *str, char *path);
void						printlog(int cs);

//ping.c
void						ipconnect(void);
void						timeout(void);
t_packet					sendpacket(t_addrinfo *addr_info);
void						recvpacket(struct timeval start, \
								struct timeval end, t_packet packet);
void						socketconfig(void);
void						ping(t_addrinfo *addr_info);

//init.c
void						initstc(void);

//error.c
void						openerror(void);
void						mallocerror(void);
void						socketerror(void);
void						setsockopterror(void);
void						addrerror(void);
void						connecterror(void);
void						sendtoerror(void);
void						accepterror(void);

//parse.c
void						parseav(char **av);

//tool.c
int							percentage(int nombre, int nombre2);
unsigned short				checksum(void *b, int len);
t_stc						*singleton(t_stc *stc);
void						freestc(void);

#endif
