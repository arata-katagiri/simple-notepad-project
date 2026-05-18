//
// Created by abdil on 5/18/2026.
//

#ifndef SIMPLE_NOTEPAD_PROJECT_LINENUMBERAREA_H
#define SIMPLE_NOTEPAD_PROJECT_LINENUMBERAREA_H
#include <QTextEdit>
#include <qwidget.h>

class LineNumberArea : public QWidget {
public:
    LineNumberArea(QTextEdit *editor): QWidget(editor), text_edit(editor)
    {}

    int lineNumberWidth() const {
        int digits = QString::number(text_edit->document()->blockCount()).length();
        int char_width = fontMetrics().horizontalAdvance(QLatin1Char('9'));

        return digits * char_width + 10;
    }

    QSize sizeHint() const override {
        return QSize(lineNumberWidth(), 0);
    }



private:
    QTextEdit *text_edit;
};

#endif //SIMPLE_NOTEPAD_PROJECT_LINENUMBERAREA_H