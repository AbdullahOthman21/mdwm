#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.i = TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.i = TAG} },

static const char *dmenucmd[]          = { "dmenu_run",         NULL };
static const char *termcmd[]           = { "st",                NULL };
static const char *ff[]                = { "firefox",           NULL };
static const char *dpms[]              = { "dpms",              NULL };
static const char *high_brightness[]   = { "high_brightness",   NULL };
static const char *low_brightness[]    = { "low_brightness",    NULL };
static const char *mid_brightness[]    = { "mid_brightness",    NULL };
static const char *ss[]                = { "screenshot",        NULL };
static const char *ss_region[]         = { "screenshot_region", NULL };
static const char *increase_volume[]   = { "increase_volume",   NULL };
static const char *decrease_volume[]   = { "decrease_volume",   NULL };
static const char *mute[]              = { "mute",              NULL };

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier         key           function        argument */
	{ MODKEY,           XK_p,         spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask, XK_Return,    spawn,          {.v = termcmd } },
	{ MODKEY,           XK_f,         spawn,          {.v = ff} },
	{ MODKEY,           XK_s,         spawn,          {.v = dpms} },
	{ MODKEY,           XK_j,         focusstack,     {.i = +1 } },
	{ MODKEY,           XK_k,         focusstack,     {.i = -1 } },
	{ MODKEY,           XK_h,         setmfact,       {.f = -0.05} },
	{ MODKEY,           XK_l,         setmfact,       {.f = +0.05} },
	{ MODKEY,           XK_Return,    zoom,           {0} },
	{ MODKEY|ShiftMask, XK_c,         killclient,     {0} },
	{ MODKEY|ShiftMask, XK_w,         killclient,     {0} },
	{ MODKEY|ShiftMask, XK_space,     togglefloating, {0} },
	{ MODKEY|ShiftMask, XK_q,         quit,           {0} },
	{ MODKEY|ShiftMask, XK_BackSpace, killclient,     {0} },
	{ 0,                XK_Print,     spawn,          {.v = ss } },
	{ MODKEY,           XK_Print,     spawn,          {.v = ss_region} },

	{ 0,        XF86XK_AudioMute,           spawn,    {.v = mute} },
	{ 0,        XF86XK_AudioRaiseVolume,    spawn,    {.v = increase_volume} },
	{ 0,        XF86XK_AudioLowerVolume,    spawn,    {.v = decrease_volume} },
	{ 0,        XF86XK_MonBrightnessUp,     spawn,    {.v = high_brightness} },
	{ MODKEY,   XK_d,                       spawn,    {.v = mid_brightness} },
	{ 0,        XF86XK_MonBrightnessDown,   spawn,    {.v = low_brightness} },

	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
};
