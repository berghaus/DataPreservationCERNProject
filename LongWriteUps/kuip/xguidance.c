/*
 * This file has been generated by the KUIP compiler.  Do NOT change it!
 *
 * KUIP header: 921023      Generation date: Wed May 25 15:26:28 1994
 *
 * Input file: xguidance.cdf
 */

#if !defined(F77_LCASE) && !defined(F77_UCASE) && !defined(F77_USCORE)
#  if defined(__EXTENDED__) && !defined(IBM370) && !defined(_IBMR2)
#    define IBM370
#  endif
#  if defined(CRAY) || defined(IBM370) || defined(vms)
#    define F77_UCASE
#  else
#    if ( defined(apollo) || defined(__apollo) ) && defined(APOFTN)
#      define F77_LCASE
#    else
#      define F77_USCORE
#    endif
#  endif
#endif

typedef int     IntFunc();
typedef char*   CharFunc();
typedef char** pCharFunc();
typedef void    SUBROUTINE();
#ifdef IBM370
#  pragma linkage(SUBROUTINE,FORTRAN)
#endif

extern void klnkmenu();
extern void klnkbrcl();
extern void klnkkmcl();
extern void klnkicon();
extern void klnkbutt();

typedef unsigned long KmPixmap; /* Pixmap from <X11/X.h>                   */
 typedef void *KmWidget;         /* Widget from <X11/Intrinsic.h>           */
 typedef void *KmCalldata;       /* XmAnyCallbackStruct from <Motif/Xm.h>   */
                                 /*                                         */
 typedef enum {                  /*                                         */
   BRACT_OPEN = 0,               /*                                         */
   BRACT_ROOT = 1,               /*                                         */
   BRACT_CONT = 2,               /*                                         */
   BRACT_GRAF = 3                /*                                         */
 } BrActTag;                     /*                                         */
                                 /*                                         */
 typedef enum {                  /*                                         */
   BrActUpdate    = 0x01,        /* browser window has to be updated ('!')  */
   BrActSeparator = 0x02,        /* put separator in menu ('/')             */
   BrActToggle    = 0x04,        /* register as toggle button               */
   BrActToggleOn  = 0x08,        /* toggle state is on                      */
   BrActSensitive = 0x10         /* button is sensitive                     */
 } BrActFlag;                    /*                                         */
                                 /*                                         */ 

typedef struct _BrAction {      /*                                         */ 
  struct _BrAction *next;       /* link to next action binding             */ 
  BrActFlag   flags;            /*                                         */ 
  char       *text;             /* text line in menu                       */ 
  char       *user_text;        /* user text overriding CDF text (malloced)*/ 
  char       *accel;            /* accelerator                             */ 
  char       *exec;             /* action commands                         */ 
  SUBROUTINE *call_F;           /* action routine                          */ 
  IntFunc    *call_C;           /* action function                         */ 
  BrActTag    tag;              /* for which window the action is defined  */ 
  struct _BrClass *class;       /* pointer to BrClass in case of open menu */
 } BrAction;                     /*                                         */
                                 /*                                         */
 typedef struct _BrClass {       /*                                         */
   struct _BrClass *next;        /* link to next browsable class            */
   char       *name;             /* unique identifier name                  */
   char       *title;            /* title for popup menu (maybe NULL)       */
   SUBROUTINE *scan_km_F;        /* user function scanning the directory    */
   pCharFunc  *scan_km_C;        /* user function scanning the directory    */
   SUBROUTINE *scan_br_F;        /* user function scanning for browsables   */
   pCharFunc  *scan_br_C;        /* user function scanning for browsables   */
   BrAction   *root;             /* list of actions in root window          */
   BrAction   *open;             /* list of actions in open menu            */
 } BrClass;                      /*                                         */
                                 /*                                         */ 

typedef struct _KmIcon {        /*                                         */ 
  struct _KmIcon *next;         /* link to next icon                       */ 
  char       *name;             /* unique identifier name                  */ 
  int         width;            /* width of the pixmap                     */ 
  int         height;           /* height of the pixmap                    */ 
  char       *bitmap;           /* bitmap data                             */ 
  KmPixmap    pix;              /* filled in Motif part                    */ 
  KmPixmap    hi_pix;           /* high lighted pixmap                     */
 } KmIcon;                       /*                                         */
                                 /*                                         */
 typedef struct _KmClass {       /*                                         */
   struct _KmClass *next;        /* link to next object class               */
   int         is_dir;           /* flag if class has is a directory        */
   char       *name;             /* unique identifier name                  */
   char       *title;            /* title for popup menu (maybe NULL)       */
   char       *big_icon;         /* name of the big icon                    */
   KmIcon     *bicon;            /* pointer to the big icon structure       */
   char       *sm_icon;          /* name of the small icon                  */
   KmIcon     *sicon;            /* pointer to the small icon structure     */
   SUBROUTINE *user_icon_F;      /* user function to return icon bitmap     */
   IntFunc    *user_icon_C;      /* user function to return icon bitmap     */
   BrAction   *cont;             /* list of actions in content window       */
   BrAction   *graf;             /* list of actions in graphics window      */
   int         obj_count;        /* number of objects in content window     */
 } KmClass;                      /*                                         */
                                 /*                                         */ 

typedef enum {                  /*                                         */ 
  KmButtSensitive       = 0x00, /* sensitive button                        */ 
  KmButtNonSensitive    = 0x01, /* non-sensitive button ('NS')             */ 
  KmButtToggleSensitive = 0x02, /* toggle-sensitive button ('TS')          */ 
  KmButtSensitivityMask = 0x03, /* mask for sensitivity type               */ 
  KmButtSeparator       = 0x04, /* put separator in menu ('/')             */ 
  KmButtBrowser         = 0x08  /* button is in main browser ('BR')        */
 } KmButtFlag;                   /*                                         */
                                 /*                                         */
 typedef struct _KmButton {      /*                                         */
   struct _KmButton *next;       /* button label or menu item               */
   char       *menu;             /* menu name or NULL for buttons           */
   char       *label;            /* button label or menu item               */
   SUBROUTINE *call_F;           /* callback routine (FORTRAN)              */
   IntFunc    *call_C;           /* callback routine (C)                    */
   char       *action;           /* name of callback routine                */
   char       *mnemo;            /* button mnemonic                         */
   char       *accel;            /* button accelerator                      */
   char       *accel_text;       /* button accelerator text                 */
   KmButtFlag  flags;            /* sensitivity type etc.                   */
   KmWidget    widget;           /* Motif widget ID                         */
 } KmButton;                     /*                                         */
                                 /*                                         */ 

extern struct {                        /*                                     
    */   /* indirect calls to avoid linking HIGZ                              
    */   IntFunc    *graf_info_C;      /* pass display, open and close
 (ixmotif)  */   SUBROUTINE *graf_size_F;      /* resize window (IGRSIZ)      
            */   SUBROUTINE *graf_pick_F;      /* identifying graphics objects
 (IGOBJ)    */   SUBROUTINE *graf_attr_F;      /* set attributes (IGSET)      
            */   SUBROUTINE *graf_close_F;     /* close workstation (ICLWK)   
            */   /* optional routines for Motif customization                 
            */   pCharFunc  *user_FallBk_C;    /* get application fallbacks   
            */   IntFunc    *user_TopWid_C;    /* pass toplevel widget
 identifiers        */ } klnkaddr;                     /*                     
                    */ 

typedef enum {                  /*                                         */ 
  KmFLAG_FORGET = 0x01,         /* last value is not kept for Motif panels */ 
  KmFLAG_MINUS  = 0x02,         /* -VALUE is not an abbrev for CHOPT=VALUE */ 
  KmFLAG_QUOTE  = 0x04,         /* do not remove quotes                    */ 
  KmFLAG_VARARG = 0x08,         /* append additional args to this param.   */ 
  KmFLAG_CONST  = 0x10,         /* do not allow to assign a value          */ 
  KmFLAG_HIDDEN = 0x20,         /* do not show in menus                    */ 
  KmFLAG_SEPARATE = 0x40        /* treat arguments as separate tokens      */
 } KmParFlag;                    /*                                         */
                                 /*                                         */
 typedef enum {                  /*                                         */
   KmTYPE_CHAR   = 'C',          /* character string                        */
   KmTYPE_FILE   = 'F',          /* file name                               */
   KmTYPE_INT    = 'I',          /* integer                                 */
   KmTYPE_OPTION = 'O',          /* option                                  */
   KmTYPE_REAL   = 'R'           /* real                                    */
 } KmParType;                    /*                                         */
                                 /*                                         */ 

typedef struct {                /* file name                               */ 
  char         *filter_default; /* filter wildcard                         */ 
  char         *filter_current; /* current filter                          */
 } KmParFile;                    /*                                         */
                                 /*                                         */
 typedef struct {                /*                                         */
   char         *range_lower;    /* lower value of range                    */
   char         *range_upper;    /* upper value of range                    */
   char         *slider_lower;   /* lower limit for slider                  */
   char         *slider_upper;   /* upper limit for slider                  */
   int           decimals;       /* number of decimals used for slider      */
 } KmParInt;                     /*                                         */
                                 /*                                         */
 typedef struct {                /* option                                  */
   char        **text;           /* explanations (parallel to range_value)  */
   int          *mutex;          /* mutex group to which text belongs       */
   int          *radio;          /* radio group to which text belongs       */
 } KmParOption;                  /*                                         */
                                 /*                                         */ 

typedef KmParInt KmParReal;     /* real and int have the same fields       */ 
                                /*                                         */
 typedef struct {                /*                                         */
   char         *name;           /* parameter name                          */
   int           abbrev;         /* minimum length that name is recognized  */
   char         *prompt;         /* prompt string                           */
   char         *dfault;         /* default value                           */
   char         *last;           /* last value for Motif panel (malloced)   */
   int           width;          /* width of input field                    */
   int           range_count;    /* number of items in range_value          */
   char        **range_value;    /* list of allowed values                  */
   int           select_count;   /* number of items in select_count         */
   char        **select_value;   /* list of values for selection box        */
   KmParFlag     flags;          /* special flags                           */
   KmParType     type;           /* parameter type                          */
   void        *ptype;           /* structure pointer selected by type      */
 } KmParameter;                  /*                                         */
                                 /*                                         */ 

typedef struct _KmCommand {     /*                                         */ 
  struct _KmCommand *next;      /* link to next command                    */ 
  char         *path;           /* command path                            */ 
  char         *name;           /* command name                            */ 
  int           hidden;         /* flag if command is invisible            */ 
  int           level;          /* depth of submenus                       */ 
  int           total;          /* total number of parameters              */ 
  int           mandatory;      /* number of mandatory parameters          */ 
  KmParameter **par;            /* list of total parameter descriptions    */ 
  int           list_par;       /* index+1 of parameter taking a list      */ 
  int           xcount;         /* count number of action calls            */ 
  SUBROUTINE   *action_F;       /* action routine                          */ 
  IntFunc      *action_C;       /* action routine                          */ 
  SUBROUTINE   *user_help_F;    /* user help routine                       */ 
  pCharFunc    *user_help_C;    /* user help routine                       */ 
  int          nguidance;       /* number of lines in guidance text        */ 
  char        **guidance;       /* help text                               */ 
  int           argc;           /* number of arguments entered             */ 
  char        **argv;           /* argc argument values                    */ 
  char         *argline;        /* argument line as entered                */ 
  int          *argoffs;        /* argc offsets into argline for KUGETE    */
 } KmCommand;                    /*                                         */
                                 /*                                         */ 

typedef struct _KmMenu {        /*                                         */ 
  struct _KmMenu *next;         /* link to next menu                       */ 
  struct _KmMenu *down;         /* link to submenu                         */ 
  char         *path;           /* path of parent menu                     */ 
  char         *name;           /* menu name                               */ 
  int           level;          /* depth of submenus                       */ 
  KmCommand    *cmds;           /* link to first command                   */ 
  int          nguidance;       /* number of lines in guidance text        */ 
  char        **guidance;       /* help text                               */
 } KmMenu;                       /*                                         */
                                 /*                                         */
 extern void klnkbrcl();         /*                                         */
 extern void klnkicon();         /*                                         */
 extern void klnkkmcl();         /*                                         */
 extern void klnkmenu();         /*                                         */
                                 /*                                         */ 

#ifdef F77_LCASE
#  define mydef_ mydef
#  define myuhlp_ myuhlp
#endif

#ifdef F77_UCASE
#  define mydef_ MYDEF
#  define myuhlp_ MYUHLP
#endif

#ifdef IBM370
#  pragma linkage(MYDEF,FORTRAN)
#  pragma linkage(MYUHLP,FORTRAN)
#endif

extern void mydef_();
extern void myuhlp_();

void mydef_()
{

static char *_MYMENU_MYCMD_guidance[] = {
 "This is the first sentence of the first paragraph.  The HELP menus",
 "show the first phrase of the first paragraph.  The phrase",
 "finishes at the first line ending with a '.' which is only now.",
 "The first paragraph is still continuing here but this",
 "sentence does not appear in the HELP menu.", "",
 "Consecutive lines are formatted into paragraphs.",
 "The maximum line width used for terminal output is determined",
 "by the SET/COLUMNS command (usually 80 columns).",
 "Because blank lines are ignored the start of a new paragraph has to be",
 "indicated by a line containing only a '.' in the first column.", "",
 "A '.' at the end of a line indicates a sentence ending period and",
 "adds an additional space for improved readability.",
 "Abbreviations like e.g. or etc. should therefore not appear",
 "at the end of a line.",
 "For consistency the extra space between sentences belonging to",
 "the menu phrase should be added by hand.",
 " Text not starting in the first column is verbatim",
 "             material and will not be reformatted.", "",
 "       This should       be used", "                    for",
 "          examples  and  tables.",
 "Again extra space between verbatim lines has to be indicated by '.' lines.",
 "For terminal output a verbatim block is always separated by",
 "a blank line from the surrounding paragraphs." };
static KmCommand _MYMENU_MYCMD = {  (KmCommand*)0, "/MYMENU/MYCMD", "MYCMD",
 0, 1, 0, 0, (KmParameter**)0, 0, 0, (SUBROUTINE*)0, (IntFunc*)0, myuhlp_,
 (pCharFunc*)0, 27, _MYMENU_MYCMD_guidance, 0, (char**)0, (char*)0, (int*)0 };

static char *_MYMENU_guidance[] = { "This is the menu for my own commands" };
static KmMenu _MYMENU = {  (KmMenu*)0,  (KmMenu*)0, "/MYMENU", "MYMENU", 1,
 &_MYMENU_MYCMD, 1, _MYMENU_guidance };

  klnkmenu( &_MYMENU, 921023 );
}


