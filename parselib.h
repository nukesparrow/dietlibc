/* parse lib: parse mmapped text with \n terminated lines */

/* a memory buffer. */
struct state {
  const unsigned char* buffirst;/* pointer to the buffer */
  size_t buflen;		/* length of the buffer */
  size_t cur;			/* already parsed bytes */
};

/* open and mmap file, fill in struct state, return fd or return -1 */
int __prepare_parse(const char* filename,struct state* s);
/* unmap file */
void __end_parse(struct state* s);

/* return the length of the matching string, 0 on error */
/* match while pred returns nonzero */
size_t __parse(struct state* s,int (*pred)(int ch));

int isnonblank(int ch);

size_t __parse_ws(struct state* s);		/* skip ' ' or '\t' */
size_t __parse_nws(struct state* s);		/* skip non-whitespace */
size_t __parse_1(struct state* s,char c);	/* skip to c */

size_t scan_ulong(const char* s,unsigned long* l);
