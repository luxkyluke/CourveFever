#include "ctrlkey.h"

CtrlKey::CtrlKey(int rKey, int lKey) :
    rightKey(rKey),leftKey(lKey){

}

CtrlKey::CtrlKey() :
    rightKey(0),leftKey(0){

}

int CtrlKey::getLeftKey(){
    return leftKey;
}

bool CtrlKey::isCtrlKey(int key){
    return(key == leftKey || key == rightKey);
}

bool CtrlKey::operator==(CtrlKey& ctrl){
    return leftKey == ctrl.leftKey
            && rightKey==ctrl.rightKey;
}

int CtrlKey::getRightKey(){
    return rightKey;
}

