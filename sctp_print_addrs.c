/*
 * =============================================================================
 *
 *       Filename:  sctp_print_addrs.c
 *
 *    Description:  displaying address list. figure 23-12, page 499.
 *
 *        Version:  1.0
 *        Created:  04/06/2015 10:27:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =============================================================================
 */

#include "unp.h"

void sctp_print_addresses(struct sockaddr_storage *addrs, int num)
{
	struct sockaddr_storage *ss;
	int	i, salen;

	ss = addrs;
	for (i = 0; i < num; i++) {
		printf("%s\n", Sock_ntop((SA *)ss, salen));
#ifdef	HAVE_SOCKADDR_SA_LEN
		salen = ss->ss_len;
#else
		switch (ss->ss_family) {
		case AF_INET:
			salen = sizeof(struct sockaddr_in);
			break;
#ifdef	IPV6
		case AF_INET6:
			salen = sizeof(struct sockaddr_in6);
			break;
#endif
		default:
			err_quit("sctp_print_addresses: unknown AF");
			break;
		}
#endif
		ss = (struct sockaddr_storage*)((char *)ss + salen);
	}
}
