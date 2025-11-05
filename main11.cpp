#include <iostream>
#include <memory>
using namespace std;


class Document {
public:
    virtual ~Document() = default;
    virtual void open() = 0;
    virtual void close() = 0;
};

class TextDocument : public Document {
public:
    void open() override {
        cout << "Opening Text Document... Editing text content." << endl;
    }

    void close() override {
        cout << "Closing Text Document. Saving text changes." << endl;
    }
};

class SpreadsheetDocument : public Document {
public:
    void open() override {
        cout << "Opening Spreadsheet Document... Calculating formulas." << endl;
    }

    void close() override {
        cout << "Closing Spreadsheet Document. Saving spreadsheet data." << endl;
    }
};


class Application {
public:
    virtual ~Application() = default;


    virtual unique_ptr<Document> createDocument() = 0;
};

class TextApplication : public Application {
public:
    unique_ptr<Document> createDocument() override {
        cout << "TextApplication: Creating new Text Document" << endl;
        return make_unique<TextDocument>();
    }
};

class SheetApplication : public Application {
public:
    unique_ptr<Document> createDocument() override {
        cout << "SheetApplication: Creating new Spreadsheet Document" << endl;
        return make_unique<SpreadsheetDocument>();
    }
};

int main() {

    Application* app = new TextApplication();

    unique_ptr<Document> doc = app->createDocument();

    doc->open();
    doc->close();

    delete app;

    cout << "\n=== Testing SheetApplication ===" << endl;


    Application* sheetApp = new SheetApplication();
    unique_ptr<Document> spreadsheet = sheetApp->createDocument();

    spreadsheet->open();
    spreadsheet->close();

    delete sheetApp;

    return 0;
}
