#ifndef CTRLKEY_H
#define CTRLKEY_H

/**
 * @brief The CtrlKey class, keep informations about
 * which key controle which player
 */
class CtrlKey{
    int rightKey, leftKey;
public:
    CtrlKey();
    CtrlKey(int rKey, int lKey);
    int getRightKey() ;
    int getLeftKey() ;
    bool isCtrlKey(int key) ;
    bool operator==(CtrlKey& crtl);
};

#endif // CTRLKEY_H
