#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.i = TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.i = TAG} },

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier         key           function        argument */
	{ MODKEY,           XK_p,         spawn,          {.v = "dmenu_run" } },
	{ MODKEY|ShiftMask, XK_Return,    spawn,          {.v = "st" } },
	{ MODKEY,           XK_f,         spawn,          {.v = "firefox"} },
	{ MODKEY,           XK_s,         spawn,          {.v = "dpms"} },
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
	{ 0,                XK_Print,     spawn,          {.v = "screenshot" } },
	{ MODKEY,           XK_Print,     spawn,          {.v = "screenshot_region"} },

	{ 0,        XF86XK_AudioMute,           spawn,    {.v = "mute"} },
	{ 0,        XF86XK_AudioRaiseVolume,    spawn,    {.v = "increase_volume"} },
	{ 0,        XF86XK_AudioLowerVolume,    spawn,    {.v = "decrease_volume"} },
	{ 0,        XF86XK_MonBrightnessUp,     spawn,    {.v = "high_brightness"} },
	{ MODKEY,   XK_d,                       spawn,    {.v = "mid_brightness"} },
	{ 0,        XF86XK_MonBrightnessDown,   spawn,    {.v = "low_brightness"} },

	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
};
