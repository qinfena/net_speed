#include <stdio.h>
#include "apue.h"
#include "speed.h"

int get_net_info(NET_INFO * nInfo){
	FILE *fp = NULL;
	char del_line[256];
	char temp[8][16];

	fp = fopen(FILE_NET, "r");
	if (fp == NULL) {
		err_sys("fopen error");
		return -1;
	}
	fgets(del_line, sizeof(del_line), fp);
	fgets(del_line, sizeof(del_line), fp);

	memset(del_line, 0, sizeof(del_line));
	fgets(del_line, sizeof(del_line), fp);
	//printf("%s\n", del_line);
	//sscanf(del_line, "%s%s%s%*s%s%*s%*s%*s%*s%s%s", nInfo.inet, nInfo.r_bytes, nInfo.r_packets, nInfo.r_drop, nInfo.t_bytes, nInfo.t_packets);
	sscanf(del_line, "%s%s%s%*s%s%*s%*s%*s%*s%s%s", nInfo->inet, temp[0], temp[1], temp[2], temp[3], temp[4]);
	nInfo->r_bytes 		= atoi(temp[0]);
	nInfo->r_packets 	= atoi(temp[1]);
	nInfo->r_drop		= atoi(temp[2]);
	nInfo->t_bytes		= atoi(temp[3]);
	nInfo->t_packets	= atoi(temp[4]);

	//printf("%s %d %d %d %d %d\n", nInfo->inet, nInfo->r_bytes, nInfo->r_packets, nInfo->r_drop, nInfo->t_bytes, nInfo->t_packets);

	fclose(fp);

	return 0;
}

int 
main () {
	float r_bytes_speed, t_bytes_speed;
	int r_packet_total, t_packet_total;
	int r_bytes_total, t_bytes_total;
	int total_packets, total_bytes;

	NET_INFO old_nInfo, new_nInfo, orige_nInfo;
	get_net_info(&orige_nInfo);
	while(1) {
		get_net_info(&old_nInfo);
		sleep(SUM);
		get_net_info(&new_nInfo);
		r_bytes_speed 	= (new_nInfo.r_bytes 	- old_nInfo.r_bytes) * 8 / SUM / 1024;
		t_bytes_speed 	= (new_nInfo.t_bytes	- old_nInfo.t_bytes) * 8 / SUM / 1024;
		r_packet_total 	= new_nInfo.r_packets 	- orige_nInfo.r_packets;
		t_packet_total 	= new_nInfo.t_packets 	- orige_nInfo.t_packets;
		r_bytes_total	= new_nInfo.r_bytes		- orige_nInfo.r_bytes;
		t_bytes_total	= new_nInfo.t_bytes		- orige_nInfo.t_bytes;
		total_packets 	= r_packet_total 		+ t_packet_total;
		total_bytes		= r_bytes_total			+ t_bytes_total;

		system("clear");
		printf("\t\tTotal\tTotal\tIncoming\tIncoming\tOutgoing\tOutgoing\n");
		printf("\t\tPackets\tBytes\tPackets\t\tBytes\t\tPackets\t\tBytes\n");
		printf("Total:\t\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", \
		total_packets, total_bytes, r_packet_total, r_bytes_total, t_packet_total ,t_bytes_total);
		printf("RX speed: %.2f Kbps\nTX speed: %.2f Kbps\nincoming packets:%d\noutcoming packets:%d\n\n",\
		 r_bytes_speed, t_bytes_speed, r_packet_total, t_packet_total);
		//printf("----------------------------------------------------------->\n\n");
	}

	return 0;
}
