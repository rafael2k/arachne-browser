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
//!!glennmcc: June 22, 2002 ... spelling correction "succesfuly->successfully" ;-)

#define MSG_START  "\nArachne V%s%s wird beendet...\n%s\n"
#define MSG_END    "\nArachne V%s%s%s wurde erfolgreich beendet...\n%s\n\n"
#define MSG_ENDX   "Arachne wurde erfolgreich verlassen...\n\n"
#define MSG_MEM    "Kein konventioneller Speicher mehr vorhanden!"
#define MSG_MEMERR "Arachne kann keinen Speicher mehr reservieren!\n"
#define MSG_BYTES  ": (%lu bytes fehlen)\n"
#define MSG_XSWAP  "Illegale xSwap Operation"
#define MSG_XDEL   "Von xSwap kann nicht gel�scht werden"
#define MSG_DELAY1 "Wie w�rs mit einem Kaffee ?"
#define MSG_DELAY2 "Bitte einen Moment..."
#define MSG_BREAK  "<Strg+Pause> Abbrechen."
#define MSG_ESC    "<Esc> Abbrechen..."
#define MSG_ANYKEY " dr�cke eine Taste"
#define MSG_ALLOC  "Speicherreservierungsfehler - %s in der Zeile %d (Datei: %s)!\nVersuche xSwap zu l�schen..."
#define MSG_DNSERR "Kann Computer %s nicht finden - bitte check deinen Computer !"
#define MSG_BADEXE "Fehler in EXE-Datei."
#define MSG_TCPIP  "Initialisiere TCP/IP..."
#define MSG_FONT   "Update Schriftinformation..."
#define MSG_RETURN "Tippe 'arachne -r' um zu Arachne zur�ckzukehren.\n"
#define MSG_HANGUP "Verbindung wird beendet..."
#define MSG_ERRIMG "Bild kann nicht geladen werden..."
#define MSG_CONV   "Prozess: '%s' [%s]. %s %s"
#define MSG_PLUGIN "Prozess: '%s'. %s"
#define MSG_ERROR  "Fehler!"
#define MSG_NOTMEM "Seite zu lang!"
#define MSG_ABORT  "Transfer unterbrochen !"
#define MSG_ASKDNS "Frage Domain Name Server (DNS) f�r %s ..."
#define MSG_ERRCON "Kann nicht mit %s verbinden - bitte check die Einstellungen !"
#define MSG_CON    "Verbinde nach %s, Port %u ..."
#define MSG_REQ    "Verbunden zu %s - Frage nach Objekt '%s' ..."
#define MSG_POST   "Poste Daten..."
#define MSG_READ   "%d bytes gelesen.\n"
#define MSG_HTTP   "HTTP Kopf von"
#define MSG_REDIR  "Redirection..."
#define MSG_CLOSE  "Verbindung beenden..."
#define MSG_CLOSED "Verbindung beendet."
#define MSG_DOWNLD "Downloade Datei ("
#define MSG_X_OF_Y "%s%ld von %ld bytes ) ..."
#define MSG_BYTESR "%s%ld bytes gelesen) ..."
#define MSG_MISOBJ "%d Objekte fehlen, "
#define MSG_DISK   "Lade Seite von Platte"
#define MSG_ADJUST "Setze Frames, Bilder und Tabellen"
#define MSG_DLPERC "Downloade Seite (%ld von %ld bytes) ..."
#define MSG_DLBYTE "Downloade Seite (%ld bytes gelesen) ..."
#define MSG_REDRAW "Bildschirm wird upgedated..."
#define MSG_RENDER "Generiere einen Virtual Screen..."
#define MSG_FORM   "Bearbeitung von ..."
#define MSG_FRAMES "Das ist ein mehrteiliges Dokument:"
#define MSG_DELAY0 "Meditiere..."
#define MSG_VERIFY "Verifiziere Bilder..."
#define MSG_CFGERR "Fehler beim Lesen von %s:\nDatein nicht gefunden, Datei ist l�nger als %d  Zeilen oder kein Speicher mehr vorhanden\n"
#define MSG_KILL   "L�sche Cache..."
#define MSG_DEAD   "Cache gel�scht."
#define MSG_URL    "Gib die URL ein und dr�cke <Enter>."
#define MSG_TCPERR "FEHLER: %s\n"
#define MSG_TCPILL "Illegaler TCP/IP Status: %d\n"
#define MSG_NOIP   "Undefininierte IP Adresse !"
#define MSG_CONFIG "Update Konfigurationsdatei..."
#define MSG_WRITE  "Schreibe Datei..."
#define MSG_COPY   "Kopiere..."
#define MSG_HOTLST "URL '%.40s' zur Hotlist hinzugef�gt."
#define MSG_ERRHOT "Kann zur Hotlist nichts hinzuf�gen!"
#define MSG_FNTERR "Fehler beim Laden der Schrift: "
#define MSG_MEMLFT "(Freier Speicher = %lu)\n"
#define MSG_F5ZOOM "\n\nIn diesem Modus kannst du <F5> oder <*> dr�cken um zum Vollbildmodus zu wechseln.\n\nBitte%s..."
#define MSG_VERR1  "\nKann nicht in den Graphikmodus wechseln - bitte starte setup.bat !"
#define MSG_APCK   "\nKann arachne.pck nicht laden - bitte starte setup.bat !"
#define MSG_GIF    "Originalpallette=%d, GIF-Pallette=%d, Farbenanzahl=%d."
#define MSG_LDPAL  "Lade %d Farbpallette ..."
#define MSG_MIXPAL "Mixe Pallette mit %d Farben ..."
#define MSG_BMP    "Originalpalette=%d, BMP=Truecolor, Farbanzahl=%d."
#define MSG_ASKING "Verbunden. Frage nach '%s'..."
#define MSG_WTRPL  "Verbunden. Warte auf Antwort..."
#define MSG_RDRPL  "Lese Antwort... (%ld bytes gelesen)"
#define MSG_CONVI  "Bearbeite %d Embeded Objekte. %s %s"
#define MSG_LOGIN  "Einloggen..."
#define MSG_DETECT "Erkenne %lu Nachrichten (%lu bytes in der Mailbox)\n"
#define MSG_GET1   "Lade Nachrichten # %lu von %lu (%lu%s"
#define MSG_GET2   "Lade Nachrichten # %lu (%lu bytes) von %lu (%lu%s"
#define MSG_GET3   " bytes in der Mailbox)\n"
#define MSG_DELE   "L�sche Nachricht # %lu von %lu"
#define MSG_SKIP   "�berspringe # %lu, zu gro� f�r die Platte\n"
#define MSG_ERROPN "Datei kann nicht ge�ffnet werden!"
#define MSG_SMTP   "Verbinde zu SMTP Server..."
#define MSG_ICON1  "Vorherige Seite"
#define MSG_ICON2  "N�chste Seite"
#define MSG_ICON3  "Homepage"
#define MSG_ICON4  "Aktualiseren"
#define MSG_ICON5  "Zur Hotliste hinzuf�gen"
#define MSG_ICON6  "Hotliste"
#define MSG_ICON7  "Transfer abgebrochen"
#define MSG_ICON8  "Suchmaschine"
#define MSG_ICON9  "Hilfe"
#define MSG_ICONH  "History"
#define MSG_ZOOM   "Gr��e �ndern"
#define MSG_EXIT   "Arachne beenden"
#define MSG_INFO2  "Mehr Information"
#define MSG_DIAL2  "Link zur Kontrollseite"
#define MSG_SEND   "Sende Nachricht, %ld bytes von %ld..."
#define MSG_UPLOAD "Uploade Datei, %ld bytes von %ld..."
#define MSG_SENT   "%d bytes gesendet, warte auf Antwort..."
#define MSG_MAILUP "SMTP uploadet"
#define MSG_MAILDL "POP3 downloadet"
#define MSG_REMOVE "%s gel�scht"
#define MSG_DIAL   "Just a moment, w�hle! %s"
#define MSG_USEMAP "Linke Klientseitige Graphik..."
#define MSG_PRN    "Konverte zu Text..."
#define MSG_SRCH1  "Suche nach '%s'..."
#define MSG_SRCH2  "Nicht gefunden !"
#define MSG_IMAGE  "%s Bilder %dx%d"
#define MSG_COLORS ", %d Farben"
#define MSG_LINECOL "Zeile:%04d/%04d Spalte:%03d"
#define MSG_SRCH4  "Suchen"
#define MSG_ENTER  "Gib Suchbegriff ein und dr�cke <Enter>"
#define MSG_PS     "Drucke PostScript Datei # %d of %d ..."
#define MSG_CLPDEL "L�sche Objekte mittels <Delete>-Taste..."
#define MSG_CLPADD "Du kannst den Link zur Hotliste hinzuf�gen..."
#define MSG_EDTADD "Titel"
#define MSG_AENTER "Bearbeite Name und dr�cke <Enter>"
#define MSG_BACKGR "Downloade parallel Bilder ("
#define MSG_IDENT  "Ignoriere IDENT Aufruf auf Port 113..."
#define MSG_EFNAME "Gib Dateinamen ein und dr�cke <Enter>"
#define MSG_REFRSH "Arachne wird '%.40s' laden in %d Sekunden. %s"
#define MSG_DOCDON "%s (Ladezeit=%ld:%02d)"
#define MSG_BLOCK  "^B Beginnt Block, ^K Beendet den Block, ^C Kopiert Block, ^M Verschiebt Block, ^Y Schneidet block aus"
#define MSG_NOVIRT "Virtual Screen kann nicht exportiert werden !"
#define MSG_NOVGA  "Graphicmodus wird nicht unterst�tzt !"
#define MSG_BLCUT  "Schneide Block aus"
#define MSG_BLCLIP "Kopiere Block in Zwischenablage"
#define MSG_BLPAST "F�ge Block ein von Zwischenablage"
#define MSG_MISLNK "Fehlender Link: %d"
#define MSG_ERRIKN "Fehler bei ICON-Datei. GUI kann nicht gezeichnet werden!\n"
#define MSG_BLCKWR "Block geschrieben."
#define MSG_MEMSEL "\nSpeicherarten zum Auslagern:\n"
#define MSG_MEMXMS "0. XMS (Empfohlen) <Enter>"
#define MSG_MEMEMS "1. EMS (f�r XT/AT)"
#define MSG_MEMDSK "2. Disk (notfalls)"
#define MSG_MEMORY "\nW�hle Speicherart aus [Esc zum Abbrechen]: "

#define MSG_VGASEL "\nVerf�gbare Graphikmoden:\n"
#define MSG_VGAVGA "0. VGA (empfolen) <Enter>"
#define MSG_VGAEGA "1. EGA (veraltet)"
#define MSG_VGACGA "2. CGA (veraltet)"
#define MSG_VIDEO  "\nW�hle Graphikmodus [Esc zum Abbrechen]: "

//Messages with limited size:

//                 >-------|----|-----<
#define MSG_INFMSG " device free  used"

//(aproximately)   >-------------<
#define MSG_SAVE   "Speich./Upld."
#define MSG_OPEN   "Lade/�ffn.URL"
#define MSG_PRINT  "Drucken/Exprt"
#define MSG_SEARCH "Suche        "
#define MSG_EDIT   "Local bearb. "
#define MSG_SOURCE "Quellcode    "
#define MSG_INFO   "Seiteninfo   "
#define MSG_IMAGES "Lade Bilder"
#define MSG_MAIL   "Dein E-Mail"
#define MSG_HOME   "Desktop"
#define MSG_WRITEF "Schreibe Datei"
#define MSG_READF  "Lese Datei"
#define MSG_SRCHTX "Suche im Txt"
#define MSG_PRT    "Drucken"
#define MSG_BLKCUT "Ausschneiden"
#define MSG_BLKCLP "zur Zwschabl."
#define MSG_BLKPST "Einf�gen"
#define MSG_BLKCOP "Kopieren"
#define MSG_BLKMOV "Verschieben"
#define MSG_BLKDEL "L�schen"

//(aproximately)   >------<
#define MSG_TITLE  "Titel"
