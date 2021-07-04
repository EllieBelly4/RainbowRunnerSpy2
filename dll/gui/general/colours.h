
#ifndef RRSPY2_GUI_COLOURS
#define RRSPY2_GUI_COLOURS

#define TO_IMCOL32(colour) IM_COL32((colour).x * 255, (colour).y * 255, (colour).z * 255, 255)
static const ImVec4 &defaultDFCNodeColour = ImVec4(0.929f, 0.682f, 0.286f, 1);

extern ImVec4 colourYellow;
extern ImVec4 entityActiveColour;
extern ImVec4 entityColour;
extern ImVec4 propertyColour;
extern ImVec4 gcPropertyColour;
extern ImVec4 gcSuperclassColour;
extern ImVec4 gcclassColour;
extern ImVec4 tabColour;
extern ImVec4 propertiesColour;
extern ImVec4 tabSelectedColour;
extern ImVec4 windowBackground;
extern ImVec4 windowTitleBg;
extern ImVec4 panelBg;
extern ImVec4 panelBgLt;
extern ImVec4 listAltBg;
extern ImVec4 listAltBgLt;
extern ImVec4 listSelected;
extern ImVec4 titleBg;
extern ImVec4 titleBgActive;
extern ImVec4 titleAltText;
extern ImVec4 textDisabled;

#endif