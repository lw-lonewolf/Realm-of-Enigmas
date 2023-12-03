/* SceneInit.cpp
 * Contains scene initialization functions called after the scene location is
 * loaded.
 *
 * */

void onSceneInit(SceneLocation sceneLocation) {
    switch (sceneLocation) {
        case SCENE_OPTIMUS:
            if (showMinigameFeedbackDialog) {
                handleDialog(minigameFeedbackDialog);
                showMinigameFeedbackDialog = false;
                if (minigameFeedbackDialog.identifier == DIALOG_MINIGAME_DEFEAT)
                    createPopup("You Lost", "You failed to complete the challenge. You can always head back here to give it another try.");
                else {

                }
            }
            break;
        case SCENE_DEMO_SCENE:
            createPopup("Tutorial", "Use WASD or the arrow keys to move around.");
            break;
        case SCENE_ROCK_GAME:
            onRockSceneShown();
            break;

    }

}