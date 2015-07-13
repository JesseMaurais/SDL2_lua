#include "SDL.hpp"
#include <SDL2/SDL2_gfxPrimitives.h>

extern "C" int luaopen_GFX(lua_State *state)
{
	luaL_newmetatable(state, GFX_METATABLE);
	luaL_Reg regs [] =
	{
	{"Pixel", lux_cast(pixelRGBA)},
	{"HLine", lux_cast(hlineRGBA)},
	{"VLine", lux_cast(vlineRGBA)},
	{"Rectangle", lux_cast(rectangleRGBA)},
	{"RoudedRectangle", lux_cast(roundedRectangleRGBA)},
	{"Box", lux_cast(boxRGBA)},
	{"RoundedBox", lux_cast(roundedBoxRGBA)},
	{"Line", lux_cast(lineRGBA)},
	{"AALine", lux_cast(aalineRGBA)},
	{"ThickLine", lux_cast(thickLineRGBA)},
	{"Circle", lux_cast(circleRGBA)},
	{"Arc", lux_cast(arcRGBA)},
	{"AACircle", lux_cast(aacircleRGBA)},
	{"FilledCircle", lux_cast(filledCircleRGBA)},
	{"Ellipse", lux_cast(ellipseRGBA)},
	{"AAEllipse", lux_cast(aaellipseRGBA)},
	{"FilledEllipse", lux_cast(filledEllipseRGBA)},
	{"Pie", lux_cast(pieRGBA)},
	{"FilledPie", lux_cast(filledPieRGBA)},
	{"Trigon", lux_cast(trigonRGBA)},
	{"AATrigon", lux_cast(aatrigonRGBA)},
	{"FilledTrigon", lux_cast(filledTrigonRGBA)},
	{"Polygon", lux_cast(polygonRGBA)},
	{"AAPolygon", lux_cast(aapolygonRGBA)},
	{"FilledPolygon", lux_cast(filledPolygonRGBA)},
	{"TexturedPolygon", lux_cast(texturedPolygon)},
	{"Bezier", lux_cast(bezierRGBA)},
	{nullptr, nullptr}
	};
	luaL_setfuncs(state, regs, 0);
	return 1;
}

