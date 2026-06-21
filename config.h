/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *fonts[]          = { "JetBrainsMonoNL Nerd Font:size=14" };
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#bbbbbb", "#222222", "#444444" },
	[SchemeSel]  = { "#eeeeee", "#222222", "#fabd2f"  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3" };

/* key definitions */
#include "keys.h"

/* button definitions */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
};

