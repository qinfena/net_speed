#define FILE_NET "/proc/net/dev"
#define INET " ens33"
#define SUM 1.0

typedef struct net_info{
	char inet[16];
	int r_bytes;	
	int r_packets;
	int r_errs;
	int r_drop;
	int r_fifo;
	int r_frame;
	int r_compressed;
	int r_multicast;

	int t_bytes;
	int t_packets;
	int t_errs;
	int t_drop;
	int t_fifo;
	int t_colls;
	int t_carrier;
	int t_compressed;
}NET_INFO;
