/* SceneInit.cpp
 * Contains scene initialization functions called after the scene location is
 * loaded.
 *
 * */

void onSceneInit(SceneLocation sceneLocation) {
    switch (sceneLocation) {
        case SCENE_DEMO_SCENE:
            createPopup("Tutorial", "Use WASD or the arrow keys to move around.");
            break;
        case SCENE_ROCK_GAME:
            onRockSceneShown();
            break;

    }

}