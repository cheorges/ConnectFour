#include "view/viewmanager.h"
#include "engine/controller/gameengine.h"

int main() {
    ViewManager* viewManager = new ViewManager();
    GameEngine(viewManager).init();
}
