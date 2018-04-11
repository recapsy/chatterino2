#pragma once

#include <QThread>

namespace chatterino {
namespace singletons {

class NativeMessagingManager
{
    NativeMessagingManager();

public:
    static NativeMessagingManager &getInstance();

    class ReceiverThread : public QThread
    {
    public:
        void run() override;

    private:
        void handleMessage(const QJsonObject &root);
    };

    void writeByteArray(QByteArray a);
    void registerHost();
    void openGuiMessageQueue();
    void sendToGuiProcess(const QByteArray &array);
};

}  // namespace singletons
}  // namespace chatterino
