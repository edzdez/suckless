/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;  /* -b  option; if 0, dmenu appears at bottom */
static int opacity = 1; /* -o  option; if 0, then alpha is disabled */
static int fuzzy = 1;   /* -F  option; if 0, dmenu doesn't use fuzzy matching */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {"JetBrains Mono Nerd Font:size=11"};
static const char *prompt = NULL; /* -p  option; prompt to the left of input field */

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
};

static const char *colors[][2] = {
    /*               fg         bg       */
    [SchemeNorm] = {"#cdd6fa", "#1e1e2e"},
    //[SchemeSel] = {"#212121", "#89ddff"},
    [SchemeSel] = {"#cdd6fa", "#45475a"},
    [SchemeOut] = {"#cdd6fa", "#45475a"},
    [SchemeSelHighlight] = {"#a6e3a1", "#47475a"},
    [SchemeNormHighlight] = {"#a6e3a1", "#1e1e2e"},
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;
static unsigned int lineheight = 0; /* -h option; minimum height of a menu line     */
static unsigned int min_lineheight = 11;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " /?\"&[]";
