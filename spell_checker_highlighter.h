#ifndef SPELL_CHECKER_HIGHLIGHTER_H
#define SPELL_CHECKER_HIGHLIGHTER_H

#include <QRegularExpression>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>

#include <cctype>
#include <set>
#include <string>

class spell_checker_highlighter : public QSyntaxHighlighter {
public:
    spell_checker_highlighter(QTextDocument* document, const std::set<std::string>* dictionary)
        : QSyntaxHighlighter(document)
    {
        this->dictionary = dictionary;
        format.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);
        format.setUnderlineColor(Qt::red);
    }

protected:
    void highlightBlock(const QString& text) override
    {
        QRegularExpression re("[A-Za-z]+");
        QRegularExpressionMatchIterator it = re.globalMatch(text);

        while (it.hasNext()) {
            QRegularExpressionMatch match = it.next();

            std::string word = match.captured().toLower().toStdString();

            if (dictionary->find(word) == dictionary->end()) {
                setFormat(match.capturedStart(), match.capturedLength(), format);
            }
        }
    }

private:
    const std::set<std::string>* dictionary;
    QTextCharFormat format;
};

#endif // SPELL_CHECKER_HIGHLIGHTER_H
