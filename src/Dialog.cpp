/* Dialog.cpp *
 * This file will contain all the dialogs (NPC talks with the player).
 *
 * */

Dialog testDialog() {
    Dialog d;
    d.title = "Talk to ???";
    d.messages[0].speaker = guideChar;
    d.messages[0].message = "Hello Traveler! I hope you're doing good.";
    d.messages[1].speaker = guideChar;
    d.messages[1].message = "It seems my students do not fully understand what it means to wield the blade.";
    d.messages[2].speaker = guideChar;
    d.messages[2].message = "Perhaps you could show them what you know?";

    return d;
}

Dialog noGoingBackDialog() {
    Dialog d;
    d.identifier = DIALOG_GUIDE_FIRST;
    d.title = "No going back...";
    if (countKeys() == 3) {
        d.messages[0].speaker = guideChar;
        d.messages[0].message = "So you finally collected all the keys.";
        d.messages[1].speaker = playerChar;
        d.messages[1].message = "Yep.";
        d.messages[2].speaker = guideChar;
        d.messages[2].message = "Impressive.";
        d.messages[3].speaker = guideChar;
        d.messages[3].message = "Well then I mustn't behave as an obstacle in your path.";
        d.messages[4].speaker = guideChar;
        d.messages[4].message = "May you enjoy freedom.";
    } else {
        d.messages[0].speaker = guideChar;
        switch (countKeys()) {
            case 0:
                d.messages[0].message = "Walk around and find the keys you need to get back out.";
                break;
            case 1:
                d.messages[0].message = "Great, you obtained your first key. Continue your adventure!";
                break;
            case 2:
                d.messages[0].message = "Two down, one more to go. Keep up the good work, you're almost there.";
                break;
        }
    }

    return d;
}

Dialog rockDialog() {
    Dialog d;
    d.title = "Rock";
    d.identifier = DIALOG_ROCK_GAME;
//    d.messages[0].speaker = rockChar;
//    d.messages[0].message = "Hello I am rock.";
//    d.messages[1].speaker = guideChar;
//    d.messages[1].message = "It seems my students do not fully understand what it means to wield the blade.";
//    d.messages[2].speaker = rockChar;
//    d.messages[2].message = "shut up this is my dialog not yours";
//    d.messages[3].speaker = guideChar;
//    d.messages[3].message = "sorry";
//    d.messages[4].speaker = rockChar;
//    d.messages[4].message = "okay so i have this uhh rock game thing, play it pls.";
    d.messages[0].speaker = rockChar;
    d.messages[0].message = "Up you climb, youngling, to where the key resides. Beware my rocky path, for it yields only to those who persist.";
    d.messages[1].speaker = emptyChar;
    d.messages[1].message = "Climb up the rocky hill without touching any obstacles!";

    return d;
}

Dialog lostMiniGameDialog(Minigame minigame) {
    Dialog d;
    d.identifier = DIALOG_MINIGAME_DEFEAT;
    d.title = "Defeat";
    switch(minigame) {
        case MINIGAME_ROCK_FALLING:
            d.messages[0].speaker = rockChar;
            d.messages[0].message = "The boulders may be daunting, but within every stumble lies the chance to ascend.";
            return d;
            break;
    }
    return d;
}

Dialog wonMiniGameDialog(Minigame minigame) {
    Dialog d;
    d.identifier = DIALOG_MINIGAME_VICTORY;
    d.title = "Victory";
    switch(minigame) {
        case MINIGAME_ROCK_FALLING:
            d.messages[0].speaker = rockChar;
            d.messages[0].message = "You won... I'm flabbergasted.";
            break;
    }

    d.messages[1].speaker = emptyChar;
    d.messages[1].message = setKeysDialogTx();
    return d;
}
