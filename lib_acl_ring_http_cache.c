
#include "lib_acl.h"
/*
 * lib_acl.h
 * @author:wuyujie
 * detail :
*/


typedef struct cache_http{
	 //char buf[1024]
	 int fd;
	 ACL_RING entry;
	
}cache_t;


int main(void){
	
	ACL_RING header;
	acl_ring_init(&header);
	
	cache_t item1,item2;
	item1.fd=1;
	item2.fd=2;
	acl_ring_append(&header,&(item1.entry));
        acl_ring_append(&header,&(item2.entry));

	ACL_RING_ITER iter;
        acl_msg_open("ring.log","./fifo");
	
	acl_ring_foreach(iter,&header){
		 ACL_RING *p=iter.ptr;
		 cache_t * temp=acl_ring_to_appl(p,cache_t,entry);
		 printf(" >>>>>>>fd=%d\n",temp->fd);
                 acl_msg_info("[info] %s %d",__FUNCTION__,__LINE__);
	}
	


	acl_msg_close();
	return 0;
	
}
