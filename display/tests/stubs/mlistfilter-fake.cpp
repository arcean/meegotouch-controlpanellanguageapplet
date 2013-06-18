#include "mlistfilter.h"
#include <mtextedit.h>

MListFilter::MListFilter(MList *){}
MListFilter::~MListFilter(){}
void MListFilter::setEnabled(bool){}
bool MListFilter::enabled(){return true;}
MTextEdit *MListFilter::editor() const {return new MTextEdit();}

    /*

    MSortFilterProxyModel *proxy() const;
*/
 void MListFilter::setFilterRole(int){}
/*
    int filterRole() const;

    void keyPressEvent(QKeyEvent *event);
*/
void MListFilter::setFilterMode(MListFilter::FilterMode){}
/*
    MListFilter::FilterMode filterMode() const;
    void editorTextChanged();
*/
