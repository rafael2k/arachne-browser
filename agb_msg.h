/*
Message file for ARACHNE WWW browser

Notes for translators:

1) Please translate only quoted messages (text between " .... ")
2) Please keep symbols like %s, %d, etc. They will be replaced by program.
3) Symbol \n means line break
4) For German message file, there is one big inconvenience: text mode messages
   must be displayed in DOS code page, while graphics mode messages in Windows
   code page. This is because of characters with "umlauts".

*/

//Messages with (almost) unlimited size (one line of text):

#define MSG_START  "\nArachne V%s%s startuje...\n%s\n"
#define MSG_END    "\nArachne V%s%s%s uspesne skoncila...\n%s\n\n"
#define MSG_MEM    "Arachne nema dostatek konvencni (dolni) DOSovske pameti"
#define MSG_BYTES  ": (chybi %lu bytu)\n"
#define MSG_XSWAP  "Zakazana operace s xSwapem"
#define MSG_XDEL   "nelze mazat z xSwapu"
#define MSG_DELAY1 "D�te si k�vu ?"
#define MSG_DELAY2 "Moment, pros�m..."
#define MSG_BREAK  "Pro p�eru�en� stiskn�te <Ctrl+Pause>."
#define MSG_ESC    "Pro p�eru�en� stiskn�te <Esc>..."
#define MSG_ANYKEY " stisknete cokoliv "
#define MSG_ALLOC  "Chyba pri alokaci pameti - %s !\nSnazim se dealokovat xSwap..."
#define MSG_DNSERR "Nemohu nal�zt po��ta� %s - pros�m zkontrolujte va�e nastaven� !"
#define MSG_BADEXE "Chyba v EXE souboru."
#define MSG_TCPIP  "Inicializuji TCP/IP..."
#define MSG_FONT   "Aktualizuji informace o fontech..."
#define MSG_RETURN "Pro navrat na WWW napiste 'arachne -r'\n"
#define MSG_THIS   "> Toto je NEKOMERCNI (neregistrovana) verze Arachne,%s<\n"
#define MSG_HANGUP "Ukon�uji telefonick� spojen�..."
#define MSG_ERRIMG "Obr�zek nelze nahr�t..."
#define MSG_CONV   "Zpracov�v�m '%s' => %s. %s %s"
#define MSG_PLUGIN "Zpracov�v�m '%s'. %s"
#define MSG_ERROR  "Chyba!"
#define MSG_NOTMEM "Str�nka je p��li� dlouh� !"
#define MSG_ABORT  "P�enos dat byl p�eru�en !"
#define MSG_ASKDNS "Dotazuji se name serveru na %s ..."
#define MSG_ERRCON "Nemohu se p�ipojit na %s - pros�m zkontrolujte va�e nastaven� !"
#define MSG_CON    "P�ipojuji se na %s, port %d ..."
#define MSG_REQ    "Nav�z�no spojen� s %s - ��d�m str�nku '%s' ..."
#define MSG_POST   "Odes�l�n data metodou POST..."
#define MSG_READ   "P�e�teno %d byt�.\n"
#define MSG_HTTP   "HTTP hlavi�ka "
#define MSG_REDIR  "P�esm�rov�n�..."
#define MSG_CLOSE  "Ukon�uji spojen�..."
#define MSG_CLOSED "Spojen� ukon�eno."
#define MSG_DOWNLD "P�en��m soubor ("
#define MSG_X_OF_Y "%s%d %% z %ld byt� ) ..."
#define MSG_BYTESR "%s%ld byt� p�e�teno) ..."
#define MSG_MISOBJ "%d objekt� chyb�, "
#define MSG_DISK   "Nahr�v�m dokument z disku"
#define MSG_ADJUST "Upravuji r�me�ky, obr�zky a tabulky"
#define MSG_DLPERC "Stahuji dokument (%d %% of %ld byt�) ..."
#define MSG_DLBYTE "Stahuji dokument (%ld byt� p�e�teno) ..."
#define MSG_REDRAW "Obnovuji obrazovku..."
#define MSG_RENDER "Generuji virtu�ln� obrazovku..."
#define MSG_FORM   "Processing form..."
#define MSG_FRAMES "This is multiple document:"
#define MSG_DELAY0 "Meditating..."
#define MSG_VERIFY "Ov��uji obr�zky..."
#define MSG_CFGERR "Chyba p�i �ten� %s - del�� ne� %d ��dk� nebo�    nedostatek pam�ti\n"
#define MSG_KILL   "Ru��m diskovou cache..."
#define MSG_DEAD   "Cache je nyn� zru�ena."
#define MSG_URL "Zadejte URL str�nky kterou chcete prohl��et a�    stiskn�te <Enter> ..."
#define MSG_TCPERR "CHYBA: %s\n"
#define MSG_TCPILL "Nedovolen� TCP/IP status: %d\n"
#define MSG_NOIP   "Nedefinovan� IP adresa !"
#define MSG_CONFIG "Aktualizuji konfigura�n� soubor..."
#define MSG_WRITE  "Zapisuji soubor..."
#define MSG_COPY   "Kop�ruji..."
#define MSG_HOTLST "Lokace p�id�na do hotlistu."
#define MSG_ERRHOT "Nelze zapisovat do hotlistu !"
#define MSG_FNTERR "Chyba pri nahravani fontu: "
#define MSG_MEMLFT "(Zbyvajici volna pamet = %lu)\n"
#define MSG_F5ZOOM "\n\nV tomto modu muzete pouzit <F5> nebo <*> k zobrazeni pres celou obrazovku\n\nProsim%s..."
#define MSG_VERR1  "\nNelze inicializovat video mod !"
#define MSG_VERR2 "Jestlize vase SVGA karta neni v nizee uvedenem seznamu, zkuste nainstalovat VESA driver."
#define MSG_VERR3 "Jestlize pouzivate 256 kB VGA kartu, nainstalujte prosim \"Arachne Light\"."
#define MSG_GIF "P�vodn� paleta=%d, GIF paleta=%d, Barev celkem=%d."
#define MSG_LDPAL  "Nahr�v�m %d palet ..."
#define MSG_MIXPAL "Mixuji paletu z %d barev ..."
#define MSG_BMP "P�vodn� paleta=%d, BMP=Truecolor, Barev celkem=%d."
#define MSG_ASKING "P�ipojeno. Asking for ��d�m'%s'..."
#define MSG_WTRPL  "P�ipojeno. �ek�m na odezvu..."
#define MSG_RDRPL  "�tu odpov��... (%ld byt� p�e�teno)"
#define MSG_CONVI  "Zpracov�v�m %d vlo�en� objekty. %s %s"
#define MSG_LOGIN  "P�ihla�uji se..."
#define MSG_DETECT "Zji�t�no %lu zpr�v (%lu byt� v mailboxu)\n"
#define MSG_GET1   "Na��t�m zpr�vu # %lu z %lu (%lu%s"
#define MSG_GET2   "Na��t�m zpr�vu # %lu (%lu byt�) z %lu (%lu%s"
#define MSG_GET3   " byt� v mailboxu)\n"
#define MSG_DELE   "Ma�u zpr�vu # %lu z %lu"
#define MSG_SKIP "Vynech�v�m zpr�vu # %lu, p��li��    velk�-nedostatek m�sta na disku \n"
#define MSG_ERROPN "Soubor nelze otev��t!"
#define MSG_MEMSEL "\nTypy pam�ti pro swapov�n�:\n"
#define MSG_SMTP   "P�ipojuji k SMTP serveru..."
#define MSG_ICON1  "P�edchoz� prohl��en� dokument"
#define MSG_ICON2  "N�sleduj�c� prohl��en� dokument"
#define MSG_ICON3  "Dom�c� str�nka"
#define MSG_ICON4  "Vytisknout str�nku"
#define MSG_ICON5  "P�id�n� do hotlistu"
#define MSG_ICON6  "Hotlist"
#define MSG_ICON7  "Ukon�en� Arachne"
#define MSG_ICON8  "Vyhled�v�n� v r�mci str�nky"
#define MSG_ICON9  "N�pov�da"
#define MSG_ICONH  "Historie"
#define MSG_ZOOM   "P�ekreslit obrazovku"
#define MSG_EXIT   "Ukon�en� Arachne"
#define MSG_INFO2  "Dal�� informace"
#define MSG_DIAL2  "Nastaven� p�ipojen�"
#define MSG_SEND   "Odes�l�m zpr�vu, %ld byt� of %ld..."
#define MSG_UPLOAD "Uploaduji dokument, %ld byt� z %ld..."
#define MSG_SENT   "%d byt� odesl�no, �ek�m na odezvu..."
#define MSG_MAILUP "SMTP upload"
#define MSG_MAILDL "POP3 download"
#define MSG_REMOVE "Vymaz�no %s"
#define MSG_DIAL   "Chv�li strpen�, vyt���m telefon� ��slo! %s"
#define MSG_USEMAP "Linking client side imagemaps..."
#define MSG_PRN    "Konvertuji na  oby�ejn� text..."
#define MSG_SRCH1  "Vyhled�v�m '%s'..."
#define MSG_SRCH2  "Nenalezeno !"
#define MSG_IMAGE  "%s obr�zek %dx%d"
#define MSG_COLORS ", %d barvy"
#define MSG_LINECOL"��dek:%04d Sloupec:%03d"
#define MSG_SRCH4  "Prohledat dokument:"
#define MSG_ENTER  "Zadejte hledan� �et�zec a stiskn�te <Enter>"
#define MSG_PS     "Tisknu PostScriptovou str�nku # %d z %d ..."

//Messages with unlimited, but same size (use spaces to indent):

#define MSG_SELVGA   "Vyberte video kartu : "
#define MSG_RESOL    "Zvolte rozliseni : "
#define MSG_MEMORY "\nZvolte druh pameti : "

//Messages with limited size:

//                 >------------<
#define MSG_UNREG  "Unregistered"

//                 >-------|----|-----<
#define MSG_INFMSG " device free  used"

//(aproximately)   >-------------<
#define MSG_SAVE   "Ulo�it/upload"
#define MSG_OPEN   "Nahr�t/otev��"
#define MSG_PRINT  "Tisk/export"
#define MSG_SEARCH "Hledat"
#define MSG_EDIT   "Editace"
#define MSG_SOURCE "Zdrojov� text"
#define MSG_INFO   "Informace"
#define MSG_IMAGES "Nahr�t obr�zky"
#define MSG_MAIL   "V� e-mail"
#define MSG_HOME   "Desktop"

//(aproximately)   >------<
#define MSG_TITLE  "Titul:"