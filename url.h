// ========================================================================
// URL (Uniform Resource Locator) structure, and related stuff
// (c)1996-1999 Michael Polak, Arachne Labs
// ========================================================================

#include "bin_file.h"

#ifndef __URL_H
#define __URL_H

#define URLSIZE 256
#define PROTOCOLSIZE 9
#define STRINGSIZE 40
#define PASSWORDSIZE 16

struct Url
{
 char protocol[PROTOCOLSIZE];
 char user[STRINGSIZE];
 char password[PASSWORDSIZE];
 char host[STRINGSIZE];
 unsigned port;
 char file[URLSIZE];
 char kotva[STRINGSIZE]; //#xxxx
};

#define IGNORE_PARENT_FRAME -1
#define GLOBAL_LOCATION_AS_BASEURL -2

struct AUTH_STRUCT
{
 char realm[80];
 char host[STRINGSIZE];
 char user[STRINGSIZE];
 char password[PASSWORDSIZE];
 char flag;
};

//cache item structure
struct HTTPrecord
{
 char URL[URLSIZE];    // Uniform Resource Locator
 int x;                // coordinates where the document was last displayed
 long y;               //
 long size;            // size in bytes
 char knowsize;        // logical - size is valid
 char mime[STRINGSIZE];// mime type
 char locname[80];     // full filename (after conversion to TXT,HTM,GIF,BMP)
 char rawname[80];     // full filename (before conversion)
 int handle;           // file handle
 long lastseen;        // last seen time
 char dynamic;         // document is dynamic
};


extern struct bin_file HTTPcache;
extern struct HTTPrecord HTTPdoc;
extern struct AUTH_STRUCT *AUTHENTICATION;

void AnalyseURL(char *str,struct Url *url,int frame);
void ResetURL(struct Url *url);
int SearchInCache(struct Url *absURL,struct HTTPrecord *cacheitem, XSWAP *cacheitemadr, unsigned *status);
int QuickSearchInCache(struct Url *absURL,struct HTTPrecord *cacheitem, XSWAP *cacheitemadr, unsigned *status);
XSWAP Write2Cache(struct Url *absURL,struct HTTPrecord *cacheitem, char ovr,char newfilename);
void UpdateInCache(XSWAP cacheadr, struct HTTPrecord *store);
void DeleteFromCache(XSWAP cacheadr);
void url2str(struct Url *url,char *out);
void UpdateFilenameInCache(XSWAP cacheadr, struct HTTPrecord *store);

#endif