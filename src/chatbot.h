#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <iostream>
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
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    // Copy constructor
    ChatBot(const ChatBot& source);
    // Copy assignmet
    ChatBot& operator=(const ChatBot& source) {
      std::cout << "ChatBot Copy Assignment" << std::endl;
      if(source._image != NULL)
        {
          _image = source._image;
        }
      _chatLogic = source._chatLogic;
      _rootNode = source._rootNode;
      return *this;
    }
    // Move constructor
    ChatBot(ChatBot&& source);
    // Move assignment
    ChatBot& operator=(ChatBot&& source) {
      std::cout << "ChatBot Move Assignment" << std::endl;
      if(source._image != NULL)
        {
          _image = source._image;
          delete source._image;
          source._image = NULL;
        }
      _chatLogic = source._chatLogic;
      _rootNode = source._rootNode;
      _chatLogic = nullptr;
      _rootNode = nullptr;
      return *this;
    }
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
