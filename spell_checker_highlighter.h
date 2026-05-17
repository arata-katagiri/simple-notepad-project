//
// Created by abdil on 5/17/2026.
//

#ifndef SIMPLE_NOTEPAD_PROJECT_SPELL_CHECKER_HIGHLIGHTER_H
#define SIMPLE_NOTEPAD_PROJECT_SPELL_CHECKER_HIGHLIGHTER_H

#include <QRegularExpression>
#include <QSyntaxHighlighter>
#include "spell_checker.h"

class spell_checker_highlighter : public QSyntaxHighlighter {
public:
    spell_checker_highlighter(QTextDocument* parent, const spell_checker& checker)
        : QSyntaxHighlighter(parent), checker(checker) {}

    void highlightBlock(const QString& text) override {
        QTextCharFormat spell_check_format;
        spell_check_format.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);
        spell_check_format.setUnderlineColor(Qt::red);

        QRegularExpression word_regex("\\b[a-zA-Z]+\\b");
        auto it = word_regex.globalMatch(text);
        while (it.hasNext()) {
            auto match = it.next();
            if (!checker.is_correct(match.captured().toStdString()))
                setFormat(match.capturedStart(), match.capturedLength(), spell_check_format);
        }
    }
private:
    const spell_checker& checker;
};

#endif //SIMPLE_NOTEPAD_PROJECT_SPELL_CHECKER_HIGHLIGHTER_H