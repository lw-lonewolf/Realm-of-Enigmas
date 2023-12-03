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
    d.title = "No going back...";
    d.messages[0].speaker = guideChar;
    d.messages[0].message = "So you want to go back...";
    d.messages[1].speaker = guideChar;
    d.messages[1].message = "You can't just go back like that. But well...";

    return d;
}

Dialog rockDialog() {
    Dialog d;
    d.title = "Rock";
    d.messages[0].speaker = rockChar;
    d.messages[0].message = "Hello I am rock.";
    d.messages[1].speaker = guideChar;
    d.messages[1].message = "It seems my students do not fully understand what it means to wield the blade.";
    d.messages[2].speaker = rockChar;
    d.messages[2].message = "shut up this is my dialog not yours";
    d.messages[3].speaker = guideChar;
    d.messages[3].message = "sorry";

    return d;
}