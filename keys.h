#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.i = TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.i = TAG} },

#define S "/home/me/projects/mdwm/bin/"
static const Arg dummy = {.i = 0};

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier         key           function        argument */
	{ MODKEY,           XK_p,         spawn,          {.v = "dmenu_run" } },
	{ MODKEY|ShiftMask, XK_Return,    spawn,          {.v = "st" } },
	{ MODKEY,           XK_f,         spawn,          {.v = "firefox"} },
	{ MODKEY,           XK_s,         spawn,          {.v = S"dpms"} },
	{ MODKEY,           XK_j,         focusstack,     {.i = +1 } },
	{ MODKEY,           XK_k,         focusstack,     {.i = -1 } },
	{ MODKEY,           XK_h,         setmfact,       {.f = -0.05} },
	{ MODKEY,           XK_l,         setmfact,       {.f = +0.05} },
	{ MODKEY,           XK_Return,    zoom,           dummy },
	{ MODKEY|ShiftMask, XK_c,         killclient,     dummy },
	{ MODKEY|ShiftMask, XK_w,         killclient,     dummy },
	{ MODKEY|ShiftMask, XK_space,     togglefloating, dummy },
	{ MODKEY|ShiftMask, XK_q,         quit,           dummy },
	{ MODKEY|ShiftMask, XK_BackSpace, killclient,     dummy },
	{ 0,                XK_Print,     spawn,          {.v = S"screenshot" } },
	{ MODKEY,           XK_Print,     spawn,          {.v = S"screenshot_region"} },

	{ 0,        XF86XK_AudioMute,           spawn,    {.v = S"mute"} },
	{ 0,        XF86XK_AudioRaiseVolume,    spawn,    {.v = S"increase_volume"} },
	{ 0,        XF86XK_AudioLowerVolume,    spawn,    {.v = S"decrease_volume"} },
	{ 0,        XF86XK_MonBrightnessUp,     spawn,    {.v = S"high_brightness"} },
	{ MODKEY,   XK_d,                       spawn,    {.v = S"mid_brightness"} },
	{ 0,        XF86XK_MonBrightnessDown,   spawn,    {.v = S"low_brightness"} },

	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
};
