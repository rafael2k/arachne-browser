/*-----Simulace kursoru pro 16/256 barevne mody---*/
/* Zobrazi kursor daneho tvaru od mista x,y       */
/* Velikost kursoru 16 x 16 pixlu                 */

/* Kursor je zadan dvema bitovymi maskami jako v  */
/* GMOUSE (screen and cursor mask)                */

/* Funkce: Pamatuje se stav kursoru (on/off),     */
/* X,Y kde byl naposled zobrazen, image pod       */
/* kursorem.                                      */

/* Nejprve se zavola fce x_yncurs(1,x,y,col) pro  */
/* prvni zobrazeni kurzoru v bode X,Y.            */
/* Dale volame fci x_cursor(x,y). Je-li x,y       */
/* nezmeneno od posledniho volani fce x_cursor    */
/* nedela nic. Je-li x,y jine presune se kursor   */
/* na nove misto. Zmizeni kursoru dosahneme       */
/* zavolanim fce x_yncurs(0,?,?);                 */
/*------------------------------------------------*/

#include "posix.h"
#include "x_lopif.h"

//void x_cross_cur(int x, int y);       // Pro krizovy kursor 1 a 2
//void x_cross_on(int on, int x, int y, int col);
//extern int xg_typcur;
#if HI_COLOR
char xg_curs[520];            /* Image pod kursorem          */
#else
char xg_curs[260];            /* Image pod kursorem          */
#endif

char xg_f_cur=0;
unsigned int xg_c_col;       /* On/Off,barva kurzoru     */
int  xg_x_cur,xg_y_cur;      /* Posledni souradnice      */
unsigned short xg_and16[68];   // Masky pro 16 bar. cursor.
unsigned short xg_or16[68];
short xg_s1[16];   /* Screen mask  */
short xg_s2[16];   /* Cursor mask  */


// Nova fce na orezavani img v 16 barvach ve smeru dx - spec pro cursor
void  x_rizni16(unsigned char *img, int dxnew, int dynew, unsigned char *newimg, int Pln);

void  x_cursor(int x, int y)
{
  unsigned char and_dx[134], or_dx[134];
  int i,k16,k,xdx,ydy,Pln;
  unsigned short mask;
#if HI_COLOR
  char pic16[520];
  unsigned short *pic26, *curs2;
#else
  char pic16[260];
#endif

/*
  if(xg_typcur != 0)           // Krizovy kursor typu 1 a 2
   { x_cross_cur(x, y);
     return;
   }
*/

  if(xg_f_cur <= 0) goto End_c;                  /* Vypnuty cursor */
  if(x == xg_x_cur && y == xg_y_cur) goto End_c; /* Bez pohybu     */

  x_putimg(xg_x_cur,xg_y_cur,xg_curs,0);         /* Obnoveni obrazu */

  xdx = x_maxx() - x;        // 221195
  if(xdx > 15) xdx = 15;
  ydy = x_maxy() - y;
  if(ydy > 15) ydy = 15;
  x_getimg(x,y,x+xdx,y+ydy,xg_curs);              /* Uschova noveho mista */
  xg_x_cur = x;
  xg_y_cur = y;

  if(xg_256 == MM_256)                    //------- 256 barev
  {
  /* Vyrobit tvar kursoru a zobrazit ho */
  pic16[0] = xdx+1;
  pic16[2] = ydy+1;
  pic16[1] = pic16[3] = 0;
  k16=0;
  for(k=0; k<(ydy+1); k++)
     { mask = 0x8000;
       for(i=0; i<(xdx+1); i++)
	 { if((mask & xg_s1[k]) != 0)
	     { pic16[4+k16+i] = xg_curs[4+k16+i];  /* Presun pixlu */
	     }
	   else
	     { if((mask & xg_s2[k]) != 0)
		 pic16[4+k16+i] = xg_c_col;        /* Barva kursoru */
	       else
		 pic16[4+k16+i] = 0;               /* Barva backgroundu */
	     }
	   mask = mask>>1;
	 }
       k16 += (xdx+1);
     }
  x_putimg(x,y,pic16,0);           /* Zobrazeni kursoru */
  }
#if HI_COLOR
  else if(xg_256 == MM_Hic)
  {
  pic26 = (unsigned short *)pic16;
  curs2 = (unsigned short *)xg_curs;

  pic16[0] = xdx+1;
  pic16[2] = ydy+1;
  pic16[1] = pic16[3] = 0;
  k16=0;
  for(k=0; k<(ydy+1); k++)
     { mask = 0x8000;
       for(i=0; i<(xdx+1); i++)
	 { if((mask & xg_s1[k]) != 0)
	     { pic26[2+k16+i] = curs2[2+k16+i];  /* Presun pixlu */
	     }
	   else
	     { if((mask & xg_s2[k]) != 0)
		 pic26[2+k16+i] = xg_c_col;        /* Barva kursoru */
	       else
		 pic26[2+k16+i] = 0;               /* Barva backgroundu */
	     }
	   mask = mask>>1;
	 }
       k16 += (xdx+1);
     }
  x_putimg(x,y,pic16,0);           /* Zobrazeni kursoru */
  }
#endif
  else if(xg_256 == MM_16)         //-------- 16 barev
  {
  Pln = 4;

  As_16color:
  if((xdx+1) < 16 || (ydy+1) < 16)
   { x_rizni16((unsigned char *)xg_and16, (xdx+1), (ydy+1), and_dx, Pln);
     x_putimg(x,y,and_dx,3);
     x_rizni16((unsigned char *)xg_or16,  (xdx+1), (ydy+1), or_dx, Pln);
     x_putimg(x,y,or_dx,2);
   }
  else
   { x_putimg(x,y,(char *)xg_and16,3);
     x_putimg(x,y,(char *)xg_or16,2);
   }
  }
  else if(xg_256 == MM_2)          //------- 2 barvy
  {
   Pln = 1;
   goto As_16color;
  }

  End_c:;
}

/*------ Zapne/vypne kursor a nastavi jeho barvu -------*/

void x_yncurs(int on, int x, int y, int col)
{
#if HI_COLOR
  char pic16[520];
  unsigned short *pic26, *curs2;
#else
  char pic16[260];
#endif
  unsigned char and_dx[134], or_dx[134];
  int i,k16,k,xdx,ydy,Pln;
  unsigned short mask;

  /*
  if(xg_typcur != 0)           // Krizovy kursor typu 1 a 2
   { x_cross_on(on, x, y, col);
     return;
   }
  */

  if(on != 0)       /* ----------- Zapnuti */
  {
  if(xg_f_cur > 0) return;
  xg_f_cur = 1;
#if HI_COLOR
  if(xg_256 == MM_Hic)
  { if(xg_hipalmod == 0)
      xg_c_col = xg_hival[col];
    else
      xg_c_col = col;
  }
  else
  {  xg_c_col = col;
  }
#else
  xg_c_col = col;
#endif
  xg_x_cur = x;
  xg_y_cur = y;

  xdx = x_maxx() - x;        // 221195
  if(xdx > 15) xdx = 15;
  ydy = x_maxy() - y;        // 221195
  if(ydy > 15) ydy = 15;
  x_getimg(x,y,x+xdx,y+ydy,xg_curs);

  if(xg_256 == MM_256)           //-------- 256 barev
  {
  /* Vyrobit tvar kursoru a zobrazit ho */
  pic16[0] = xdx+1;
  pic16[2] = ydy+1;
  pic16[1] = pic16[3] = 0;

  k16=0;
  for(k=0; k<(ydy+1); k++)
     { mask = 0x8000;
       for(i=0; i<(xdx+1); i++)
	 { if((mask & xg_s1[k]) != 0)
	     { pic16[4+k16+i] = xg_curs[4+k16+i];  /* Presun pixlu */
	     }
	   else
	     { if((mask & xg_s2[k]) != 0)
		 pic16[4+k16+i] = xg_c_col;        /* Barva kursoru */
	       else
		 pic16[4+k16+i] = 0;               /* Barva backgroundu */
	     }
	   mask = mask>>1;
	 }
       k16 += (xdx+1);
     }

  x_putimg(x,y,pic16,0);           /* Zobrazeni kursoru */
  }
#if HI_COLOR
  else if(xg_256 == MM_Hic)
  {
  pic26 = (unsigned short *)pic16;
  curs2 = (unsigned short *)xg_curs;

  pic16[0] = xdx+1;
  pic16[2] = ydy+1;
  pic16[1] = pic16[3] = 0;

  k16=0;
  for(k=0; k<(ydy+1); k++)
     { mask = 0x8000;
       for(i=0; i<(xdx+1); i++)
	 { if((mask & xg_s1[k]) != 0)
	     { pic26[2+k16+i] = curs2[2+k16+i];  /* Presun pixlu */
	     }
	   else
	     { if((mask & xg_s2[k]) != 0)
		 pic26[2+k16+i] = xg_c_col;        /* Barva kursoru */
	       else
		 pic26[2+k16+i] = 0;               /* Barva backgroundu */
	     }
	   mask = mask>>1;
	 }
       k16 += (xdx+1);
     }
  x_putimg(x,y,pic16,0);           /* Zobrazeni kursoru */
  }
#endif
  else if(xg_256 == MM_16)         //-------- 16 barev
  {
  Pln = 4;

  As_16color:
  if((xdx+1) < 16 || (ydy+1) < 16)
   { x_rizni16((unsigned char *)xg_and16, (xdx+1), (ydy+1), and_dx, Pln);
     x_putimg(x,y,and_dx,3);
     x_rizni16((unsigned char *)xg_or16,  (xdx+1), (ydy+1), or_dx, Pln);
     x_putimg(x,y,or_dx,2);
   }
  else
   { x_putimg(x,y,(char *)xg_and16,3);
     x_putimg(x,y,(char *)xg_or16,2);
   }
  }
  else if(xg_256 == MM_2)
  {
    Pln = 1;
    goto As_16color;
  }

  }
  else              /*--------------- Vypnuti */
  {
  xg_f_cur -= 1;
  if(xg_f_cur == 0)
     x_putimg(xg_x_cur,xg_y_cur,xg_curs,0);
  else
     xg_f_cur = -2;
  }

}

void x_defcurs(short *screen, short *cursor, int col)
{
  int i,j,inx,c4,c3,c2,c1;
  unsigned int mask,cosi;
  union { unsigned short  i2;
	  unsigned char c2[2];
	} u;
  unsigned char chch;

#if HI_COLOR
  if(xg_256 == MM_Hic)
  { if(xg_hipalmod == 0)
      xg_c_col = xg_hival[col];
    else
      xg_c_col = col;
  }
  else
  {  xg_c_col = col;
  }
#else
  xg_c_col = col;
#endif

  for(i=0; i<16; i++)
    { xg_s1[i] = screen[i];
      xg_s2[i] = cursor[i];
    }

  if(xg_256 == MM_16)               // Vyrobit masky pro AND z s1 a OR z s2
    {
      memset(xg_and16,0,134);       // Nulovani
      memset(xg_or16,0,134);
      xg_and16[0] = xg_and16[1] = 16;
      xg_or16[0]  = xg_or16[1]  = 16;

      inx = 2;                      // Vyroba AND masky
      for(i=0; i<16; i++)
       {
	 u.i2 = xg_s1[i];
	 chch = u.c2[0];
	 u.c2[0] = u.c2[1];
	 u.c2[1] = chch;
	 xg_and16[inx]  =  u.i2;
	 xg_and16[inx+1] = u.i2;
	 xg_and16[inx+2] = u.i2;
	 xg_and16[inx+3] = u.i2;
	 inx += 4;
       }

       inx = 2;                    // Vyroba OR masky s barvou
       c4 = col & 0x0008;
       c3 = col & 0x0004;
       c2 = col & 0x0002;
       c1 = col & 0x0001;
       for(i=0; i<16; i++)
	 { mask = 0x8000;
	   cosi = xg_s2[i];
	   for(j=0; j<16; j++)
	     { if((mask & cosi) != 0)
		{ if(c4 != 0) xg_or16[inx]   |= mask;
		  if(c3 != 0) xg_or16[inx+1] |= mask;
		  if(c2 != 0) xg_or16[inx+2] |= mask;
		  if(c1 != 0) xg_or16[inx+3] |= mask;
		}
		mask = mask>>1;
	     }
	   inx += 4;
	 }

       for(i=2; i<66; i++)
	 { u.i2 = xg_or16[i];
	   chch = u.c2[0];
	   u.c2[0] = u.c2[1];
	   u.c2[1] = chch;
	   xg_or16[i] = u.i2;
	 }
    }

  if(xg_256 == MM_2)               // Vyrobit masky pro AND z s1 a OR z s2
    {
      memset(xg_and16,0,134);      // Nulovani
      memset(xg_or16,0,134);
      xg_and16[0] = xg_and16[1] = 16;
      xg_or16[0]  = xg_or16[1]  = 16;

      for(i=0; i<16; i++)          // Vyroba AND masky
       {
	 u.i2 = xg_s1[i];
	 chch = u.c2[0];
	 u.c2[0] = u.c2[1];
	 u.c2[1] = chch;
	 xg_and16[i+2]  =  u.i2;
       }

      for(i=0; i<16; i++)          // Vyroba OR masky
       {
	 u.i2 = xg_s2[i];
	 chch = u.c2[0];
	 u.c2[0] = u.c2[1];
	 u.c2[1] = chch;
	 xg_or16[i+2]  =  u.i2;
       }
    }

}

void  x_rizni16(unsigned char *img, int dxnew, int dynew, unsigned char *newimg,
		int Pln)
{
//  Pln 1-bin/4-16col

    int dxori,bori,bnew, ori_of,new_of;
    //int dyori;
    int k,i,j;

    dxori = img[0];  // !! max 255 x 255 pixlu !!
    //dyori = img[2];

    if((dxori & 0x0007) == 0)     // delka orig bit. roviny v B
      bori = (dxori / 8);
    else
      bori = ((dxori / 8) + 1);

    if((dxnew & 0x0007) == 0)     // delka nove bit. roviny v B
      bnew = (dxnew / 8);
    else
      bnew = ((dxnew / 8) + 1);

    memset(newimg, 0, (bnew*Pln*dynew+4) );
    newimg[0] = dxnew;
    newimg[2] = dynew;

    ori_of = 4; new_of = 4;    // Zacatky radku

    for(k=0; k<dynew; k++)     // Cykl pres radky
     {
      for(i=0; i<Pln; i++)     // Pres roviny radku
       {
	 for(j=0; j<bnew; j++) // Kopie casti roviny
	  {
	   newimg[new_of + i*bnew +j] = img[ori_of + i*bori +j];
	  }
       }
      ori_of += (Pln * bori);
      new_of += (Pln * bnew);
     }
}
