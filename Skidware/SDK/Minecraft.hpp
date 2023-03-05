#pragma once
#include "LocalPlayer.hpp"
#include "WorldClient.hpp"
#include "NetworkManager.hpp"
#include "ServerData.hpp"
#include "RenderManager.hpp"
#include "Session.hpp"

class Minecraft
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jfieldID getLocalPlayerFieldID = NULL;
	jobject getLocalPlayerObject = NULL;
	LocalPlayer LocalPlayerInstance = NULL;

	jfieldID getWorldFieldID = NULL;
	jobject getWorldObject = NULL;
	WorldClient WorldInstance = NULL;

	jfieldID getNetworkManagerFieldID = NULL;
	jobject getNetworkManagerObject = NULL;
	NetworkManager NetworkManagerInstance = NULL;

	jobject getNetHandlerObject = NULL;
	jmethodID getNetHandlermd = NULL;
	NetHandlerPlayClient NetHandler = NULL;

	jfieldID getServerDataFieldID = NULL;
	jobject getServerDataObject = NULL;
	ServerData ServerDataInstance = NULL;

	jfieldID getRenderManagerFieldID = NULL;
	jobject getRenderManagerObject = NULL;
	RenderManager RenderManagerInstance = NULL;

	jfieldID getSessionFieldID = NULL;
	jobject getSessionObject = NULL;
	Session SessionInstance = NULL;

	jfieldID leftClickFieldID = NULL;

	jfieldID rightClickFieldID = NULL;

	jmethodID leftClickMethodID = NULL;

	jmethodID rightClickMethodID = NULL;
	
	jfieldID fpsCounterFieldID = NULL;
	jint getfpsCounterInt = NULL;

	jfieldID gameHasFocusFieldID = NULL;
	jboolean hasIngameFocusBool = NULL;

	jfieldID displayWidthFieldID = NULL;
	jint displayWidthInt = NULL;

	jfieldID displayHeightFieldID = NULL;
	jint displayHeightInt = NULL;


public:
	Minecraft(jobject);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	LocalPlayer getLocalPlayer();
	WorldClient getWorld();
	NetworkManager getNetworkManager();
	NetHandlerPlayClient getNetHandler();
	ServerData getServerData();
	RenderManager getRenderManager();
	Session getSession();
	void SetLeftClickDelay(int);
	void SetRightClickDelay(int);
	void LeftClick();
	void RightClick();
	bool InGameHasFocus();
	void setTimer(float value);
	int GetFPS();
	void SetFPS(jint);
	int GetDisplayHeight();
	int GetDisplayWidth();
	void setIsGameHasFocus(jboolean);

	jobject get_player_controller();
	LocalPlayer thePlayer = NULL;
	WorldClient theWorld = NULL;
};