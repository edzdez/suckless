/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 2; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih = 6;   /* horiz inner gap between windows */
static const unsigned int gappiv = 6;   /* vert inner gap between windows */
static const unsigned int gappoh = 6;   /* horiz outer gap between windows and screen edge */
static const unsigned int gappov = 6;   /* vert outer gap between windows and screen edge */
static const int smartgaps_fact = 1;    /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[] = "autostart_blocking.sh";
static const char autostartsh[] = "autostart.sh";
static const char dwmdir[] = "dwm";
static const char localshare[] = ".local/share";
static const int showbar = 1;                 /* 0 means no bar */
static const int topbar = 1;                  /* 0 means bottom bar */
static const int bar_height = 0;              /* 0 means derive from font, >= 1 explicit height */
static const int vertpad = 6;                 /* vertical padding of bar */
static const int sidepad = 6;                 /* horizontal padding of bar */
static const int horizpadbar = 0;   /* horizontal padding for statusbar */
static const int vertpadbar = 0;   /* vertical padding for statusbar */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int showsystray = 1;             /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype = INDICATOR_NONE;
static int floatindicatortype = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[] = {"JetBrains Mono Nerd Font:size=11"};
static const char dmenufont[] = "JetBrains Mono Nerd Font:size=11";

static char c000000[] = "#2e3440"; // placeholder value

static char normfgcolor[] = "#eceff4";
static char normbgcolor[] = "#3b4252";
static char normbordercolor[] = "#81a1c1";
static char normfloatcolor[] = "#81a1c1";

static char selfgcolor[] = "#eceff4";
static char selbgcolor[] = "#88c0d0";
static char selbordercolor[] = "#eceff4";
static char selfloatcolor[] = "#eceff4";

static char titlenormfgcolor[] = "#eceff4";
static char titlenormbgcolor[] = "#3b4252";
static char titlenormbordercolor[] = "#3b4252";
static char titlenormfloatcolor[] = "#3b4252";

static char titleselfgcolor[] = "#2e3440";
static char titleselbgcolor[] = "#88c0d0";
static char titleselbordercolor[] = "#88c0d0";
static char titleselfloatcolor[] = "#88c0d0";

static char tagsnormfgcolor[] = "#eceff4";
static char tagsnormbgcolor[] = "#3b4252";
static char tagsnormbordercolor[] = "#3b4252";
static char tagsnormfloatcolor[] = "#3b4252";

static char tagsselfgcolor[] = "#2e3440";
static char tagsselbgcolor[] = "#88c0d0";
static char tagsselbordercolor[] = "#88c0d0";
static char tagsselfloatcolor[] = "#88c0d0";

static char hidnormfgcolor[] = "#3b4252";
static char hidselfgcolor[] = "#3b4252";
static char hidnormbgcolor[] = "#3b4252";
static char hidselbgcolor[] = "#3b4252";

static char urgfgcolor[] = "#2e3440";
static char urgbgcolor[] = "#ebcb8b";
static char urgbordercolor[] = "#ebcb8b";
static char urgfloatcolor[] = "#ebcb8b";

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
    /*                       fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},      [SchemeSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeTitleNorm] = {OPAQUE, baralpha, borderalpha}, [SchemeTitleSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeTagsNorm] = {OPAQUE, baralpha, borderalpha},  [SchemeTagsSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeHidNorm] = {OPAQUE, baralpha, borderalpha},   [SchemeHidSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeUrg] = {OPAQUE, baralpha, borderalpha},
};

static char *colors[][ColCount] = {
    /*                       fg                bg                border                float */
    [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor, normfloatcolor},
    [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor, selfloatcolor},
    [SchemeTitleNorm] = {titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor},
    [SchemeTitleSel] = {titleselfgcolor, titleselbgcolor, titleselbordercolor, titleselfloatcolor},
    [SchemeTagsNorm] = {tagsnormfgcolor, tagsnormbgcolor, tagsnormbordercolor, tagsnormfloatcolor},
    [SchemeTagsSel] = {tagsselfgcolor, tagsselbgcolor, tagsselbordercolor, tagsselfloatcolor},
    [SchemeHidNorm] = {hidnormfgcolor, hidnormbgcolor, c000000, c000000},
    [SchemeHidSel] = {hidselfgcolor, hidselbgcolor, c000000, c000000},
    [SchemeUrg] = {urgfgcolor, urgbgcolor, urgbordercolor, urgfloatcolor},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I"
 * },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
    [DEFAULT_TAGS] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"},
    [ALTERNATIVE_TAGS] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"},
    [ALT_TAGS_DECORATION] = {"<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>"},
};

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     *	WM_WINDOW_ROLE(STRING) = role
     *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
     */
    RULE(.wintype = WTYPE "DIALOG", .isfloating = 1) RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
        RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1) RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
            RULE(.class = "Gimp", .tags = 1 << 4)};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
    /* monitor  bar    alignment         widthfunc                drawfunc                clickfunc name */
    {-1, 0, BAR_ALIGN_LEFT, width_tags, draw_tags, click_tags, "tags"},
    {0, 0, BAR_ALIGN_RIGHT, width_systray, draw_systray, click_systray, "systray"},
    {-1, 0, BAR_ALIGN_LEFT, width_ltsymbol, draw_ltsymbol, click_ltsymbol, "layout"},
    {'A', 0, BAR_ALIGN_RIGHT, width_status2d, draw_status2d, click_status2d, "status2d"},
    {-1, 0, BAR_ALIGN_NONE, width_wintitle, draw_wintitle, click_wintitle, "wintitle"},
};

/* layout(s) */
static const float mfact = 0.5;   /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;     /* number of clients in master area */
static const int resizehints = 0; /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
    {"|M|", centeredmaster},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                                                              \
    {MODKEY, KEY, view, {.ui = 1 << TAG}}, {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},                  \
        {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                                                              \
        {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                                                                     \
    {                                                                                                                  \
        .v = (const char *[])                                                                                          \
        {                                                                                                              \
            "/bin/sh", "-c", cmd, NULL                                                                                 \
        }                                                                                                              \
    }

/* commands */
/* static const char *dmenucmd[] = {"dmenu_run", "-fn", dmenufont,  "-nb", normbgcolor, "-nf", */
/*                                  normfgcolor, "-sb", selbgcolor, "-sf", tagsselfgcolor,  topbar ? NULL : "-b", */
/*                                  NULL}; */
/* static const char *dmenucmd[] = {"dmenu_run", "-X", "6" , "-Y", "6", "-W", "1908", NULL}; */
static const char *dmenucmd[] = {"j4-dmenu-desktop", "--dmenu=dmenu -X 6 -Y 6 -W 1908", "-term=alacritty", "--no-generic", NULL};
static const char *termcmd[] = {"alacritty", NULL};
static const char *filecmd[] = {"nemo", NULL};
static const char *webcmd[] = {"firefox", NULL};

static const char *roficmd[] = {"rofi", "-show", "drun"};

static const char *brightnessupcmd[] = {"/home/edzdez/suckless/dwm-flexipatch/scripts/brightnessup.sh", NULL};
static const char *brightnessdowncmd[] = {"/home/edzdez/suckless/dwm-flexipatch/scripts/brightnessdown.sh", NULL};
static const char *speakermutecmd[] = {"/home/edzdez/suckless/dwm-flexipatch/scripts/muteaudio.sh", NULL};
static const char *speakerupcmd[] = {"/home/edzdez/suckless/dwm-flexipatch/scripts/incvolume.sh", NULL};
static const char *speakerdowncmd[] = {"/home/edzdez/suckless/dwm-flexipatch/scripts/decvolume.sh", NULL};
static const char *micmutecmd[] = {"/home/edzdez/suckless/dwm-flexipatch/scripts/mutemic.sh", NULL};
static const char *screenshotcmd[] = {"/home/edzdez/suckless/dwm-flexipatch/scripts/sshot.sh", NULL};
static const char *changekeyboardcmd[] = {"/home/edzdez/suckless/dwm-flexipatch/scripts/switchkb.sh", NULL};
static const char *rofipowercmd[] = {"rofi", "-show", "power-menu", "-modi", "power-menu:rofi-power-menu"};

static Key keys[] = {
    /* modifier                     key            function                argument */
    /* {MODKEY, XK_d, spawn, {.v = roficmd}}, */
    {MODKEY, XK_d, spawn, {.v = dmenucmd}},
    /* {MODKEY | Mod1Mask, XK_d, spawn, {.v = dmenucmd}}, */
    {MODKEY | Mod1Mask, XK_d, spawn, {.v = roficmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_f, spawn, {.v = filecmd}},
    {MODKEY, XK_b, spawn, {.v = webcmd}},
    {MODKEY, XK_i, spawn, {.v = rofipowercmd}},
    {MODKEY | ShiftMask, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY | ShiftMask, XK_i, incnmaster, {.i = +1}},
    {MODKEY | ShiftMask, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_j, movestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, movestack, {.i = -1}},
    //{MODKEY, XK_Return, zoom, {0}},
    {MODKEY | ShiftMask, XK_equal, incrgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_minus, incrgaps, {.i = -1}},
    {MODKEY, XK_equal, defaultgaps, {6}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_F2, spawn, {.v = brightnessdowncmd}},
    {MODKEY, XK_F3, spawn, {.v = brightnessupcmd}},
    {MODKEY, XK_F5, spawn, {.v = speakermutecmd}},
    {MODKEY, XK_F6, spawn, {.v = speakerdowncmd}},
    {MODKEY, XK_F7, spawn, {.v = speakerupcmd}},
    {MODKEY, XK_F8, spawn, {.v = micmutecmd}},
    {MODKEY, XK_space, spawn, {.v = changekeyboardcmd}},
    {MODKEY, 0x0000ff61, spawn, {.v = screenshotcmd}},
    {MODKEY | ShiftMask, XK_q, killclient, {0}},
    {MODKEY | ShiftMask, XK_c, self_restart, {0}},
    {MODKEY | ShiftMask, XK_e, quit, {0}},
    {MODKEY | Mod1Mask, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY | Mod1Mask, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY | Mod1Mask, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY | Mod1Mask, XK_c, setlayout, {.v = &layouts[3]}},
    {MODKEY | Mod1Mask, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    //{MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3) TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5)
        TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7) TAGKEYS(XK_9, 8)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask           button          function        argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
