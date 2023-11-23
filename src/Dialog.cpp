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