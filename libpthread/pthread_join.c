#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <pthread.h>
#include "thread_internal.h"

int pthread_join(pthread_t th,void**thread_return) {
  int ret=ESRCH;
  _pthread_descr td,this=__thread_self();
  if (th==getpid()) return EDEADLK;
  __NO_ASYNC_CANCEL_BEGIN_(this);
  if ((td=__thread_find(th))) {
    /* test if detached or joined */
    if (td->canceled || td->detached || __testandset(&(td->joined.__spinlock))) {
      UNLOCK(td);
      ret=EINVAL;
    }
    else {
      td->jt=this;
      UNLOCK(td);
      /* wait for thread to exit */
      __thread_suspend(this,0);
      if (thread_return) *thread_return=td->retval;
      /* clean up the mess */
      ret=__thread_cleanup(td);
    }
  }
  __NO_ASYNC_CANCEL_END_(this);
  return ret;
}

