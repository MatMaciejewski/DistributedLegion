
/*
msg* tqueue_top();
void tqueue_add(msg *m);
void tqueue_del(int from);

void hang_add(int i);
void hang_del(int i);
int hang_contains(int i);
int hang_count();

void send_with_ts(int id, msg *m, int ts);
void send(int id, msg *m);
int trecv(int usec, msg *m);
void send_req_to(int id, int ts);
void send_rel_to(int id);
void send_acc_to(int id);
void handle_req_acc_rel(msg *m);

int get_timestamp();
int get_accept_count();
int get_prev_in_cs();
*/
void stage1_init();
void stage1_enter_cs(int road, void (*event)(int,int), void (*msg_handler)(msg*));