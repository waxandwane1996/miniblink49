﻿
#include "nodeblink.h"
#include "wke.h"
#include "electron.h"
#include "gin/dictionary.h"
#include "common/api/event_emitter.h"

namespace base {
class ListValue;
}

namespace atom {

class NodeBindings;

class WebContents : public mate::EventEmitter<WebContents> {
public:
    struct CreateWindowParam {
        int x;
        int y;
        int width;
        int height;
        unsigned styles;
        unsigned styleEx;
        bool transparent;
        std::wstring title;
    };

    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env);
    static WebContents* create(v8::Isolate* isolate, gin::Dictionary options);

    explicit WebContents(v8::Isolate* isolate, v8::Local<v8::Object> wrapper);
    ~WebContents();

    wkeWebView getWkeView() const { return m_view; }

    void onNewWindowInBlinkThread(const CreateWindowParam* createWindowParam);

    void postMessage(const std::string& channel, const base::ListValue& listParams);

private:
    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);

    void _loadURLApi(const std::string& url);

    std::string _getURLApi();

    std::string getTitleApi();

    bool isLoadingApi();

    bool isLoadingMainFrameApi();

    bool isWaitingForResponseApi();

    void _stopApi();

    void _goBackApi();

    void _goForwardApi();

    void _goToOffsetApi();

    bool isCrashedApi();

    void setUserAgentApi(const std::string userAgent);

    std::string getUserAgentApi();

    void insertCSSApi();

    void savePageApi();

    void openDevToolsApi();

    void closeDevToolsApi();

    void isDevToolsOpenedApi();

    void isDevToolsFocusedApi();

    void enableDeviceEmulationApi();

    void disableDeviceEmulationApi();

    void toggleDevToolsApi();

    void inspectElementApi();

    void setAudioMutedApi();

    void isAudioMutedApi();

    void undoApi();

    void redoApi();

    void cutApi();

    void copyApi();

    void pasteApi();

    void pasteAndMatchStyleApi();

    void _deleteApi();

    void selectAllApi();

    void unselectApi();

    void replaceApi();

    void replaceMisspellingApi();

    void findInPageApi();

    void stopFindInPageApi();

    void focusApi();

    bool isFocusedApi();

    void tabTraverseApi();

    void _sendApi();

    void sendInputEventApi();

    void beginFrameSubscriptionApi();

    void endFrameSubscriptionApi();

    void startDragApi();

    void setSizeApi();

    bool isGuestApi();

    bool isOffscreenApi();

    void startPaintingApi();

    void stopPaintingApi();

    bool isPaintingApi();

    void setFrameRateApi();

    void getFrameRateApi();

    void invalidateApi();

    void getTypeApi();

    void getWebPreferencesApi();

    void getOwnerBrowserWindowApi();

    void hasServiceWorkerApi();

    void unregisterServiceWorkerApi();

    void inspectServiceWorkerApi();

    void printApi();

    void _printToPDFApi();

    void addWorkSpaceApi();

    void reNullWorkSpaceApi();

    void showDefinitionForSelectionApi();

    void copyImageAtApi();

    void capturePageApi();

    void setEmbedderApi();
    
    void nullFunction();

    static void staticDidCreateScriptContextCallback(wkeWebView webView, void* param, void* frame, void* context, int extensionGroup, int worldId);
    void onDidCreateScriptContext(wkeWebView webView, void* frame, v8::Local<v8::Context>* context, int extensionGroup, int worldId);

public:
    static v8::Persistent<v8::Function> constructor;
    static gin::WrapperInfo kWrapperInfo;

private:
    NodeBindings* m_nodeBinding;
    int m_id;
    wkeWebView m_view;
};

} // atom