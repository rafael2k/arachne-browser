
#include "arachne.h"

#define fname "_4prt.bmp"

int PrintScreen2BMP(char virtscr)
{
 struct
 {
  short sigBMP;                  // Ze jde o BMP  "BM" -- File_header
  long size;                       // Velikost souboru
  long resWin;                    // Reserva Windows 4 bajty
  long offBit;                     // Zacatek obrazu

  short  zn28;                       // Cislo 28 (delka) -- INFOHEADER
  short  nic;
  long  dx_bm;                      // pocet sloupcu
  long  dy_bm;                      // pocet radku
  short  rovin;                      // pocet rovin 1
  short  bit_pix;                    // bitu na pixel
  long compress;                   // komprese
  long sizeimg;                    // velikost obrazu
  long Xpelmet;                    // Rozliseni
  long Ypelmet;
  long ClrUsed;                    // Pocet pouzitych barev
  long CltImport;                  // Pocet dulezitych barev
 } bmp_hed;                          // Sum = 54bytu

 unsigned char buf[4000];        //2*1600 + 4 + secure overhead
 int i,j,f,depth=8,max,zblo;
 long x,y,offbit;
 unsigned long fsize;
#ifdef HICOLOR
 unsigned char *RGBquadbuf;
#endif
 char *charhed=(char *)&bmp_hed;

#ifdef VIRT_SCR
 if(virtscr)
 {
  if(allocatedvirtual[activeframe])
  {
   xv_set_actvirt(activeframe);
   x=virtualxend[activeframe]-virtualxstart[activeframe];
   y=virtualyend[activeframe]-virtualystart[activeframe];
   outs(MSG_WRITE);
  }
  else
  {
   outs(MSG_NOVIRT);
   return 0;
  }
 }
 else
#endif
 if(x_getmaxcol()<255 && xg_256 != MM_Hic)
 {
  outs(MSG_NOVGA);
  return 0;
 }
 else //screenshot
 {
  x=x_maxx()+1;
  y=x_maxy()+1;
 }//end if

 f = open( fname, O_RDWR | O_BINARY | O_CREAT | O_TRUNC, S_IREAD|S_IWRITE );

 if(f<0)
  return 0;

#ifdef HICOLOR

 RGBquadbuf=farmalloc(3096);
 if(!RGBquadbuf)
  return 0;

 if(xg_256 == MM_Hic)
 {
  depth=24;
  fsize=54l+x*y*3;
  offbit=54;
 }
 else
#endif
 {
  fsize=54l+256l*4l+x*y;
  offbit=54+256*4;
 }

 memset(&bmp_hed,0,54);

 charhed[0] = 'B';
 charhed[1] = 'M';
 bmp_hed.size = fsize;
 bmp_hed.offBit = offbit;
 bmp_hed.zn28 = 0x28;
 bmp_hed.dx_bm = x;
 bmp_hed.dy_bm = y;
 bmp_hed.rovin = 1;
 bmp_hed.bit_pix = depth;
 bmp_hed.sizeimg = x*y;    // velikost obrazu
 if(depth != 24)
  bmp_hed.ClrUsed = IiNpal;  // Pocet pouzitych barev

#ifdef LINUX
 write(f, charhed,2);   
 write(f, charhed+4,52); // ????????????????? gcc deforms struct size ???
#else
 i=write(f, &bmp_hed,54);
#endif

 if(depth !=24)//write BMP palette
 {
  buf[3]='\0';
  j=0;
  while(j<256)
  {
   buf[2]=Iipal[3*j]<<2;
   buf[1]=Iipal[3*j+1]<<2;
   buf[0]=Iipal[3*j+2]<<2;
   i=write(f,buf,4);
   j++;
  }//loop
 }//end if write palette

 max=(int)y;
 y--;
 while(y>=0)
 {
#ifdef VIRT_SCR
  if(virtscr)
   xv_int_rea(0,(int)y,(int)x,1,(char *)buf);
  else
#endif
  {
   x_getimg(0,(int)y,(int)(x-1),(int)y,(char *)buf);
   x_setcolor(((int)y)%16);
   x_line(0,(int)y,(int)(x-1),(int)y);
  }
#ifdef HICOLOR
  if(depth==24)
  {
   short *pixel;
   i=0;
   while(i<(int)x)
   {
    if(xg_hi16)
    {
     pixel=(short *)&buf[4+2*i]; //length of Hicolor pixel = 16 bits
     RGBquadbuf[i*3]=(unsigned char)((*pixel&0x001f)<<3);         //b
     RGBquadbuf[i*3+1]=(unsigned char)((*pixel&0x07e0)>>3);       //g
     RGBquadbuf[i*3+2]=(unsigned char)((*pixel&0xf800)>>8);       //r
    }
    else
    {
     RGBquadbuf[i*3]=(unsigned char)((*pixel&0x001f)<<3);         //b
     RGBquadbuf[i*3+1]=(unsigned char)((*pixel&0x03e0)>>2);       //g
     RGBquadbuf[i*3+2]=(unsigned char)((*pixel&0xfc00)>>7);       //r
    }
//#define RGBHI15(R,G,B)  (((unsigned)R>>1)<<10)|(((unsigned)G>>1)<<5)|((unsigned)B>>1)
//#define RGBHI16(R,G,B)  (((unsigned)R>>1)<<11)|((unsigned)G<<5)|((unsigned)B>>1)

    i++;
   }
   zblo=(4-((int)(x*3)%4))%4;
   write(f,RGBquadbuf,(int)(x*3)+zblo);
  }
  else
#endif
  {
   zblo=(4-((int)(x)%4))%4;
   write(f,&buf[4],(int)x+zblo);
  }
  if(virtscr)
   percentbar( (int)( 100l*( (max-(int)y)) /max ) );
  else
   x_putimg(0,(int)y,(char *)buf,0);
  y--;
 }
#ifdef HICOLOR
 free(RGBquadbuf);
#endif
 close(f);
 sprintf(GLOBAL.location,"file:%s",fname);
 GLOBAL.gotolocation=1;
 return 1;
}
