/*
 * @(#) Gemini\appledit.h
 * @(#) Stefan Eissing, 04. Februar 1992
 *
 * description: Header File for appledit.c
 */

#ifndef __appledit__
#define __appledit__

struct applInfo
{
	struct applInfo *nextappl;	/* pointer zur n�chsten Struktur */
	char path[MAX_PATH_LEN];			/* Pfad der Applikation */
	char name[MAX_FILENAME_LEN];	/* Name der Applikation */
	char label[MAX_FILENAME_LEN];	/* Label des Laufwerks */
	char wildcard[WILDLEN];		/* zust�ndig f�r z.B. *.c */
	word startmode;				/* Modus f�r Programmstart */
};
typedef struct applInfo ApplInfo;

extern ApplInfo *applList;


ApplInfo *GetApplInfo (ApplInfo *List, const char *name);

int InsertApplInfo (ApplInfo **List, ApplInfo *prev, ApplInfo *ai);
int DeleteApplInfo (ApplInfo **List, const char *name);
void FreeApplList (ApplInfo **list);

void EditApplList (const char *applname, const char *path,
					const char *label, word defstartmode);

#endif