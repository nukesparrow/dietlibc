#ifndef _LINUX_EVENTPOLL_H
#define _LINUX_EVENTPOLL_H

#include <sys/ioctl.h>

#define EP_FDS_PAGES(n)	(((n) + POLLFD_X_PAGE - 1) / POLLFD_X_PAGE)
#define EP_MAP_SIZE(n)	(EP_FDS_PAGES(n) * PAGE_SIZE * 2)

struct evpoll {
  int ep_timeout;
  unsigned long ep_resoff;
};

#endif
