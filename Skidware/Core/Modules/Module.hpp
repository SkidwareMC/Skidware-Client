

#ifndef PHANTOM_CHEAT_H
#define PHANTOM_CHEAT_H


#include "../../SDK/EventSystem/Event.hpp"
class Module {
public:
    explicit Module(const char* name, const int bind, const char* description = "");

    void OnTick();
    void onEnable();
    void onDisable();
    void toggle();
    const char* getName();
    const char* getDescription();
    void renderSetts();

    bool enabled = false;
    int bind;
private:
    const char* name;
    const char* description;
};


#endif //PHANTOM_CHEAT_H