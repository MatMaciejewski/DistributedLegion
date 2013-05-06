#include "common.h"
#include "stage1.h"
#include "stage2.h"

void handle(msg *m){
	switch(m->type){
		case M_REQ:
		case M_ACC:
		case M_REL:
			handle_req_acc_rel(m);
		break;
		
		case M_ASK:
		case M_TKS:
			handle_ask_tks(m);
		break;
	};	
}

void talk_to_last_in_queue(int road, int prev){
	stage2_enter_queue(prev, 10);
}

void walk_on_the_road(int road){
	sprintf(buf,"Imma walkin' on da road %i", road); lg();
	sleepForMax(1000);
}


///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int main()
{
	init_slave();
	stage1_init();
	stage2_init();

	stage1_enter_cs(0, talk_to_last_in_queue, handle);
	stage2_enter_cs(0, 5, 10, walk_on_the_road, handle);
		


	sprintf(buf, "finished"); lg();
	quit_slave();
}
