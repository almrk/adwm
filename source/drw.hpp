/* See LICENSE file for copyright and license details. */
#pragma once

typedef struct {
	Cursor cursor;
} Cur;

typedef struct Fnt {
	Display* dpy;
	unsigned int h;
	XftFont* xfont;
	FcPattern* pattern;
	struct Fnt* next;
} Fnt;

enum { ColFg, ColBg, ColBorder }; /* Clr scheme index */
typedef XftColor Clr;

typedef struct {
	unsigned int w, h;
	Display* dpy;
	int screen;
	Window root;
	Drawable drawable;
	GC gc;
	Clr* scheme;
	Fnt* fonts;
} Drw;

/* Drawable abstraction */
Drw* drwCreate(Display* dpy, int screen, Window win, unsigned int w, unsigned int h);
void drwResize(Drw* drw, unsigned int w, unsigned int h);
void drwFree(Drw* drw);

/* Fnt abstraction */
Fnt* drwFontsetCreate(Drw* drw, const char* fonts[], size_t fontcount);
void drwFontsetFree(Fnt* set);
unsigned int drwFontsetGetwidth(Drw* drw, const char* text);
unsigned int drwFontsetGetwidthClamp(Drw* drw, const char* text, unsigned int n);
void drwFontGetexts(Fnt* font, const char* text, unsigned int len, unsigned int* w, unsigned int* h);

/* Colorscheme abstraction */
void drwClrCreate(Drw* drw, Clr* dest, const char* clrname);
void drwClrFree(Drw* drw, Clr* c);
Clr* drwScmCreate(Drw* drw, const char* clrnames[], size_t clrcount);
void drwScmFree(Drw* drw, Clr* scm, size_t clrcount);

/* Cursor abstraction */
Cur* drwCurCreate(Drw* drw, int shape);
void drwCurFree(Drw* drw, Cur* cursor);

/* Drawing context manipulation */
void drwSetfontset(Drw* drw, Fnt* set);
void drwSetscheme(Drw* drw, Clr* scm);

/* Drawing functions */
void drwRect(Drw* drw, int x, int y, unsigned int w, unsigned int h, int filled, int invert);
int drwText(Drw* drw, int x, int y, unsigned int w, unsigned int h, unsigned int lpad, const char* text, int invert);

/* Map functions */
void drwMap(Drw* drw, Window win, int x, int y, unsigned int w, unsigned int h);
