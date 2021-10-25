#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                                  // constructor WITHOUT memory allocation
    ChatBot(std::string filename);              // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    ChatBot(const ChatBot& other);              // copy constructor
    ChatBot(ChatBot&& other);                   // move constructor
    ChatBot& operator=(const ChatBot& other);   // copy assignment: clean up target and copy
    ChatBot& operator=(ChatBot&& other);        // move assignment: clean up target and move

    // NOTE: Since ChatBot is not intended to be copied, the copy constructor
    // and copy assignment should be deleted (see commented code below).
    // However, I left them in above since the instructions specifically
    // say to have them.

    // ChatBot(const ChatBot& other) = delete; // prevent construction by copy
    // ChatBot& operator=(const ChatBot& other) = delete; // prevent assignment by copy

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
