#ifndef ___DL_INT_H__
#define ___DL_INT_H__

#include <elf.h>
#include <dlfcn.h>

#define DEBUG

struct _dl_handle {
  struct _dl_handle *next;
  struct _dl_handle *prev;

  char *	name;
  int		flag_global;

  /* basic */
  char *	mem_base;	/* base address of maped *.so */
  unsigned long mem_size;	/* len of mem block */
  unsigned long lnk_count;	/* reference count (other libraries) */
  unsigned long img_off;	/* */

  /* symbol resolve helper */
  unsigned long*hash_tab;	/* hash table */

  unsigned long*pltgot;		/* PLT / GOT */
  unsigned long*got;		/* global offset table */

  char *	dyn_str_tab;	/* dyn_name table */

  Elf32_Sym *	dyn_sym_tab;	/* dynamic symbol table */
  Elf32_Rel *	plt_rel;	/* PLT relocation table */

  /* INIT / FINI */
  void (*fini)(void);
};

#define HASH_BUCKET_LEN(p)	(*((p)))
#define HASH_BUCKET(p)		((p)+2)

#define HASH_CHAIN_LEN(p)	(*((p)+1))
#define HASH_CHAIN(p)		((p)+2+HASH_BUCKET_LEN(p))

/* elf_hash.c */
unsigned long elf_hash(const unsigned char *name);

/* _dl_alloc.c */
extern struct _dl_handle* _dl_root_handle;
extern struct _dl_handle* _dl_top_handle;
void _dl_free_handle(struct _dl_handle* dh);
struct _dl_handle* _dl_get_handle();
struct _dl_handle* _dl_find_lib(const char* name);

/* _dl_open.c */
void *_dl_open(const char* filename, int flags);
void *_dl_load(const char* filename, const char*pathname, int fd, int flags);

/* _dl_search.c */
void _dl_set_rpath(const char *path);
int _dl_search(char *buf, int len, const char *filename);

/* _dl_sym.c */
void *_dl_sym(struct _dl_handle * h, int symbol);
/* dlsym.c */
void *_dlsym(void * h, char* symbol);

/* _dl_queue.c */
int _dl_queue_lib(const char* name, int flags);
void _dl_open_dep();

/* _dl_relocate.c */
int _dl_relocate(struct _dl_handle* dh, Elf32_Rel *rel, int num);

/* dlerror.c */
extern int   _dl_error;
extern const char* _dl_error_location;
extern const char* _dl_error_data;

#endif
