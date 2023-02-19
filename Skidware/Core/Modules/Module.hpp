

#ifndef PHANTOM_CHEAT_H
#define PHANTOM_CHEAT_H


class Module {
public:
    explicit Module(const char* name, const int bind, const char* description = "");

    void OnTick();
    void OnUpdate();
    void OnRender();
    const char* getName();
    const char* getDescription();
    void renderSetts();

    bool enabled;
    int bind;
private:
    const char* name;
    const char* description;
};


#endif //PHANTOM_CHEAT_H