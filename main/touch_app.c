#include "KBN.h"

#define DEV_PATH "/dev/touch_dev"

void* touch(){
	int fd = 0;
	char buf[5]="";
	int lcd_chk = 0;

	if((fd = open(DEV_PATH, O_RDONLY)) < 0){
		fprintf(stderr,"open() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf, 4);
		if(lcd_chk%2 == 0){
			buf[0] == '1' ? servo() : NULL;
			buf[1] == '1' ? power2() : NULL;
			buf[2] == '1' ? exit() : NULL;//terminating
			buf[3] == '1' ? lcd_chk++ : NULL;
			sleep(1);	
		}//normal mode
		else if(lcd_chk%2 == 1){}//lcd mode
	}
}
