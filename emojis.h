#ifndef EMOJIS_H
#define EMOJIS_H

#include <QRegularExpression>
#include <QObject>
#include <QString>
#include <unordered_map>

#include "lazyloadedimage.h"
#include "concurrentmap.h"

class Emojis
{
public:
    static void parseEmojis(std::vector<std::tuple<LazyLoadedImage*, QString>>& vector, const QString& text);

    static void initEmojis();

    static QString replaceShortCodes(const QString& text);

    struct EmojiData {
        QString value;
        QString code;
    };

private:

    static QRegularExpression* findShortCodesRegex;

    static QMap<QString, EmojiData>* shortCodeToEmoji;
    static QMap<QString, QString>* emojiToShortCode;
    static QMap<QChar, QMap<QString, QString>>* firstEmojiChars;

    static ConcurrentMap<QString, LazyLoadedImage*>* imageCache;

    Emojis() {}
};

#endif // EMOJIS_H