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

#define MSG_START  "\nArachne V%s%s est� carregando...\n%s\n"
#define MSG_END    "\nArachne V%s%s%s foi carregado com sucesso no DOS...\n%s\n\n"
#define MSG_ENDX   "Arachne foi carregado com sucesso...\n\n"
#define MSG_MEM    "Arachne esgotou a memoria convencional (baixa) do DOS"
#define MSG_MEMERR "Arachne esgotou a memoria - a aloca��o malloc() falhou.\n"
#define MSG_BYTES  ": (%lu bytes faltantes\n"
#define MSG_XSWAP  "Opera�� ilegal de xSwap"
#define MSG_XDEL   "N�o � poss�vel deletar do xSwap"
#define MSG_DELAY1 "Gostaria de um cafezinho ?"
#define MSG_DELAY2 "Um momento, por favor..."
#define MSG_BREAK  "<Ctrl+Pause> aborta."
#define MSG_ESC    "<Esc> aborta..."
#define MSG_ANYKEY " pressione qualquer tecla "
#define MSG_ALLOC  "Erro de aloca��o de mem�ria - %s na linha %d do arquivo %s!\nTentando de-alocar xSwap..."
#define MSG_DNSERR "N�o foi poss�vel localizar o computador %s - por favor verifique a configura��o !"
#define MSG_BADEXE "Erro no arquivo EXE."
#define MSG_TCPIP  "Initializando TCP/IP..."
#define MSG_FONT   "Atualizando informa��o de fonte..."
#define MSG_RETURN "Tecle 'arachne -r' para retornar a World Wide Web.\n"
#define MSG_THIS   "> Esta � uma vers�o N�O-COMERCIAL (n�o registrada) do Arachne,%s<\n"
#define MSG_HANGUP "Terminando conex�o discada (dial-up)..."
#define MSG_ERRIMG "N�o foi poss�vel carregar a imagem..."
#define MSG_CONV   "Processando '%s' [%s]. %s %s"
#define MSG_PLUGIN "Processando '%s'. %s"
#define MSG_ERROR  "Erro!"
#define MSG_NOTMEM "P�gina � longa demais !"
#define MSG_ABORT  "Transfer�ncia interrompida !"
#define MSG_ASKDNS "Procurando servidor de nome para %s ..."
#define MSG_ERRCON "N�o foi poss�vel conectar no %s - por favor, verifique a configura��o !"
#define MSG_CON    "Conectando no %s, porta %u ..."
#define MSG_REQ    "Conectado no %s - solicitando objeto '%s' ..."
#define MSG_POST   "Enviando dados..."
#define MSG_READ   "%d bytes foram lidos.\n"
#define MSG_HTTP   "Cabe�alho HTTP de"
#define MSG_REDIR  "Redirecionando..."
#define MSG_CLOSE  "Fechando a conex�o..."
#define MSG_CLOSED "Conex�o fechada."
#define MSG_DOWNLD "Transferindo o arquivo ("
#define MSG_X_OF_Y "%s%ld de %ld bytes ) ..."
#define MSG_BYTESR "%s%ld bytes lidos) ..."
#define MSG_MISOBJ "%d objeto faltante, "
#define MSG_DISK   "Carregando a p�gina do disco"
#define MSG_ADJUST "Ajustando frames, imagens e tabelas"
#define MSG_DLPERC "Transferindo p�gina (%ld de %ld bytes) ..."
#define MSG_DLBYTE "Transferindo p�gina (%ld bytes lidos) ..."
#define MSG_REDRAW "Atualizando a tela..."
#define MSG_RENDER "Gerando a tela virtual..."
#define MSG_FORM   "Processando formul�rio..."
#define MSG_FRAMES "Isto � um documento m�ltiplo:"
#define MSG_DELAY0 "Meditando..."
#define MSG_VERIFY "Verificando imagens..."
#define MSG_CFGERR "Erro lendo %s:\nArquivo n�o encontrado, o arquivo � menor que %d linhas ou esgotou a mem�ria\n"
#define MSG_KILL   "Apagando o cache de disco..."
#define MSG_DEAD   "O cache foi apagado."
#define MSG_URL    "Digite o URL que deseja surfar e tecle <Enter> ..."
#define MSG_TCPERR "ERRO: %s\n"
#define MSG_TCPILL "Status de TCP/IP ilegal: %d\n"
#define MSG_NOIP   "Endere�o IP n�o definido !"
#define MSG_CONFIG "Atualizando o arquivo de configura��o..."
#define MSG_WRITE  "Escrevendo arquivo..."
#define MSG_COPY   "Copiando..."
#define MSG_HOTLST "URL '%.40s' foi adicionado em Favoritos."
#define MSG_ERRHOT "N�o foi poss�vel escrever no Favoritos !"
#define MSG_FNTERR "Erro no carregamento do arquivo de fontes: "
#define MSG_MEMLFT "(mem�ria livre dispon�vel = %lu)\n"
#define MSG_F5ZOOM "\n\nNeste modo voc� pode usar as teclas <F5> ou <*> para mudar para o modo de tela-cheia.\n\nPor favor%s..."
#define MSG_VERR1  "\nN�o foi poss�vel inicializar o modo de v�deo - por favor, execute o setup.bat !"
#define MSG_APCK   "\nN�o foi poss�vel carregar o arachne.pck - por favor, execute o setup.bat !"
#define MSG_GIF    "Paleta de cores original=%d, paleta GIF=%d, Total de cores=%d."
#define MSG_LDPAL  "Carregando %d paletas de cores ..."
#define MSG_MIXPAL "Combinando paleta de %d cores ..."
#define MSG_BMP    "Paleta original=%d, BMP=Truecolor, Total de cores=%d."
#define MSG_ASKING "Conectado. Procurando por '%s'..."
#define MSG_WTRPL  "Conectado. Aguardando a resposta..."
#define MSG_RDRPL  "Lendo resposta... (%ld bytes lidos)"
#define MSG_CONVI  "Processando %d objetos incluidos. %s %s"
#define MSG_LOGIN  "Efetuando o Logon em..."
#define MSG_DETECT "Detetado %lu menssagens (%lu bytes na caixa de entrada)\n"
#define MSG_GET1   "Obtendo menssagem # %lu of %lu (%lu%s"
#define MSG_GET2   "Obtendo menssagem # %lu (%lu bytes) de %lu (%lu%s"
#define MSG_GET3   " bytes na caixa de entrada)\n"
#define MSG_DELE   "Deletando menssagem # %lu de %lu"
#define MSG_SKIP   "Pulando a menssagem # %lu, grande de mais para o espa�o de disco dispon�vel\n"
#define MSG_ERROPN "N�o foi poss�vel abrir o arquivo!"
#define MSG_SMTP   "Conectando ao servidor SMTP..."
#define MSG_ICON1  "P�ginas visitadas anteriormente"
#define MSG_ICON2  "P�ginas a visitar"
#define MSG_ICON3  "Homepage"
#define MSG_ICON4  "Recarregar"
#define MSG_ICON5  "Adicionar ao Favoritos"
#define MSG_ICON6  "Favoritos"
#define MSG_ICON7  "Abortar transfer�ncia"
#define MSG_ICON8  "Mecanismo de Busca"
#define MSG_ICON9  "Ajuda"
#define MSG_ICONH  "Hist�rico"
#define MSG_ZOOM   "Redimensionar"
#define MSG_EXIT   "Sair do Arachne"
#define MSG_INFO2  "Mais informa��es"
#define MSG_DIAL2  "P�gina de controle de conex�o"
#define MSG_SEND   "Enviando mensagem, %ld bytes de %ld..."
#define MSG_UPLOAD "Transferindo arquivo, %ld bytes de %ld..."
#define MSG_SENT   "%d bytes enviados, aguardando pela resposta..."
#define MSG_MAILUP "Upload via SMTP"
#define MSG_MAILDL "Download do POP3"
#define MSG_REMOVE "Deletado %s"
#define MSG_DIAL   "Aguarde um momento, discando ! %s"
#define MSG_USEMAP "Criando liga��o para mapa de imagens..."
#define MSG_PRN    "Convertendo para texto puro..."
#define MSG_SRCH1  "Procurando por '%s'..."
#define MSG_SRCH2  "N�o encontrado !"
#define MSG_IMAGE  "%s imagem %dx%d"
#define MSG_COLORS ", %d cores"
#define MSG_LINECOL "Linha:%04d/%04d Coluna:%03d"
#define MSG_SRCH4  "Buscar"
#define MSG_ENTER  "Digite o texto a buscar e tecle <Enter>"
#define MSG_PS     "Imprimindo p�gina PostScript # %d de %d ..."
#define MSG_CLPDEL "Voc� pode remover o objeto selecionado usando a tecla de <Delete> ..."
#define MSG_CLPADD "Voc� pode adicionar links selecionados a Favoritos..."
#define MSG_EDTADD "T�tulo"
#define MSG_AENTER "Edite o nome e tecle <Enter>"
#define MSG_BACKGR "Transfer�ncia paralela de imagens ("
#define MSG_IDENT  "Ignorando a solicitacao de IDENT na porta 113..."
#define MSG_EFNAME "Digite o nome do arquivo e tecle <Enter>"
#define MSG_REFRSH "Arachne voar� para '%.40s' em %d segundos. %s"
#define MSG_DOCDON "%s (tempo de carga=%ld:%02d)"
#define MSG_BLOCK  "^B in�cio do bloco, ^K  fim do block, ^C copia o bloco, ^M move o bloco, ^Y recortar o bloco"
#define MSG_NOVIRT "N�o existe tela virtual para exportar !"
#define MSG_NOVGA  "Modo gr�fico n�o suportado !"
#define MSG_BLCUT  "Recortar o bloco para a �rea de transfer�ncia"
#define MSG_BLCLIP "Copiar o bloco para a �rea de transfer�ncia"
#define MSG_BLPAST "Colar o bloco da �rea de transfer�ncia"
#define MSG_MISLNK "Links perdidos: %d"
#define MSG_ERRIKN "Erro no processamento do arquivo de �cones. N�o � poss�vel mostrar a interface do usu�rio !\n"
#define MSG_BLCKWR "Bloco foi escrito."

#define MSG_MEMSEL "\nTipos de mem�ria dispon�veis para a troca:\n"
#define MSG_MEMXMS "0. XMS (recomendado) [Enter]"
#define MSG_MEMEMS "1. EMS (for XT/AT)"
#define MSG_MEMDSK "2. Disco (ultima opcao)"
#define MSG_MEMORY "\nSelecione o tipo de mem�ria [Esc para abortar]: "

#define MSG_VGASEL "\nCategorias de placa de v�deo dispon�veis:\n"
#define MSG_VGAVGA "0. VGA (recomendado) [Enter]"
#define MSG_VGAEGA "1. EGA (hist�rico)"
#define MSG_VGACGA "2. CGA (experimental)"
#define MSG_VIDEO  "\nSelecione o tipo de v�deo [Esc para abortar]: "

//Messages with limited size:

//                 >------------<
#define MSG_UNREG  "Sem Registro"

//                 >-------|----|-----<
#define MSG_INFMSG " equip. livr usado"

//(aproximately)   >-------------<
#define MSG_SAVE   "Salvar/upload"
#define MSG_OPEN   "Abrir URL"
#define MSG_PRINT  "Imp./Exportar"
#define MSG_SEARCH "Buscar na p�gina"
#define MSG_EDIT   "Edi��o local"
#define MSG_SOURCE "P�gina de origem"
#define MSG_INFO   "P�gina de info"
#define MSG_IMAGES "Carregar imagens"
#define MSG_MAIL   "Seu eMail"
#define MSG_HOME   "Desktop"
#define MSG_WRITEF "Escrever arquivo"
#define MSG_READF  "Ler arquivo"
#define MSG_SRCHTX "Busca no texto"
#define MSG_PRT    "Imprimir"
#define MSG_BLKCUT "Recortar"
#define MSG_BLKCLP "Para �rea transf."
#define MSG_BLKPST "Colar"
#define MSG_BLKCOP "Copiar"
#define MSG_BLKMOV "Mover"
#define MSG_BLKDEL "Deletar"

//(aproximately)   >------<
#define MSG_TITLE  "T�tulo"
