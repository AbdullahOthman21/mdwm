#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },
static const char *dmenucmd[] = { "dmenu_run",  NULL };
static const char *termcmd[]  = { "st",         NULL };
static const char *ff[]       = { "firefox",    NULL };

static const char *dpms[] = { "xset", "dpms", "force", "off", NULL };

#define brightness "/sys/class/backlight/intel_backlight/brightness"
static const char *high_brightness[]   = { "sh", "-c", "echo 19200 | sudo tee "brightness, NULL };
static const char *mid_brightness[]    = { "sh", "-c", "echo 4000  | sudo tee "brightness, NULL };
static const char *low_brightness[]    = { "sh", "-c", "echo 100   | sudo tee "brightness, NULL };

static const char *screenshot[]        = { "sh", "-c", "maim    ~/$(date +%Y-%m-%d_%H-%M-%S).png", NULL };
static const char *screenshot_region[] = { "sh", "-c", "maim -s ~/$(date +%Y-%m-%d_%H-%M-%S).png", NULL };

#define HERBE "pkill herbe; herbe $(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}')"
static const char *increase_volume[]   = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ +5%; " HERBE, NULL };
static const char *decrease_volume[]   = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ -5%; " HERBE, NULL };
static const char *mute[]              = { "sh", "-c", "pactl set-sink-mute @DEFAULT_SINK@ toggle", NULL };

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_f,      spawn,          {.v = ff} },
	{ MODKEY,                       XK_s,      spawn,          {.v = dpms} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_w,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ 0,                            XK_Print, spawn,          {.v = screenshot} },
	{ MODKEY,                       XK_Print, spawn,          {.v = screenshot_region} },
	{ MODKEY|ShiftMask,             XK_BackSpace, killclient,  {0} },
	{ 0, XF86XK_AudioMute,         spawn, {.v = mute} },
	{ 0, XF86XK_AudioRaiseVolume,  spawn, {.v = increase_volume} },
	{ 0, XF86XK_AudioLowerVolume,  spawn, {.v = decrease_volume} },
	{ 0, XF86XK_MonBrightnessUp,   spawn, {.v = high_brightness} },
	{ MODKEY, XK_d,                spawn, {.v = mid_brightness} },
	{ 0, XF86XK_MonBrightnessDown, spawn, {.v = low_brightness} },
};
